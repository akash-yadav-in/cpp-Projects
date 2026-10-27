
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;

/*                  ================== EXPERIMENT - 08 ====================

 ---- > OBJECTIVE - TO STUDY RELATIVISTIC TIME DILATION AND LENGHT OF CONTRACTION AS A FUNCTION OF VELOCITY OF AN OBJECT
                         
*/

class Experiment_08
{
public:
    // Here Declared the variables and constants
    double speed_light = 3e8; // Defining the value of the speed of light
    int proper_time = 1;

    int proper_length = 1;
    vector<double> beta_values = {0.1, 0.5, 0.8, 0.9, 0.99};

    void user_input(void)
    {
        double user_input;
        cout << "Enter 1 if you want to change beta values " << endl;

        cout << "Enter 0 if you want to proceed with default values " << endl;

        cin >> user_input; // Taking user input

        if (user_input == 1) // If user want to upload diffrent values of beta
        {
            beta_values.clear();

            cout << "Enter 5 values of beta you want to use and it should be strictly between (( 0 <= beta  < 1)) " << endl;

            for (int i = 0; i < 5; i++) //
            {
                double temp_user_input;
                cout << "Enter the " << i + 1 << " Value : " << endl;
                cin >> temp_user_input;
                while (temp_user_input > 1 || temp_user_input < 0) // check on beta values
                {
                    cout << "Enter the value strictly between (( 0 <= beta  < 1)) " << endl;
                    cin >> temp_user_input;
                }

                beta_values.push_back(temp_user_input);

                cout << endl;
            }
        }
    }

    void calculations_values(ofstream &expfile)
    {
        expfile << "Beta,Velocity(m/s),Gamma,Dilated_Time(s),Contracted_Length(m)\n";

        expfile << fixed << setprecision(4);

        for (int i = 0; i < beta_values.size(); i++)
        {
            double beta = beta_values[i];

            // Calculation Part
            double velocity = beta * speed_light;
            double lorentz_factor = 1.0 / (sqrt(1.0 - (beta * beta)));

            double dilated_time = lorentz_factor * proper_time;

            double contracted_length = proper_length / lorentz_factor;

            // Exporting the generated data into the csv file
            expfile << beta << ","
                    << velocity << ","
                    << lorentz_factor << ","
                    << dilated_time << ","
                    << contracted_length << "\n";
        }
    }
};

int main()
{
    Experiment_08 c;
    c.user_input();

    ofstream expfile{"Experiment_08.csv"};

    if (!expfile.is_open())
    {
        cout << "Error in Opening The File " << endl;
        return -1;
    }

    c.calculations_values(expfile);
    expfile.close();

    cout << "Data For The Simulation Is Generated And saved To The Same Directory As This C++ File '!" << endl;

    return 0;
}
