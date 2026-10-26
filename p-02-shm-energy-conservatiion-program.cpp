#define _Maths_Varibles
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class Experiment
{
public:
    // Declaring the variables
    double m;
    double k;
    double A; // This is The Amplitude
    double phi;
    double omega;
    double Time_Period;

    void Experiment_input(void) // This is for taking the user inputs
    {
        cout << "Enter The Value of Mass (m): ";
        cin >> m;

        cout << "Enter The Value of Spring Constant (k): ";
        cin >> k;

        cout << "Enter The Value of Amplitude (A): ";
        cin >> A;

        cout << "Enter The Value of Initial Phase (phi) in radians: ";
        cin >> phi;
    }

    void Experiment_calculations(void) // This one for finding the constants omega and time_period
    {
        omega = sqrt(k / m);
        Time_Period = (2.0 * M_PI) / omega;
    }

    void Data_Calculations(void) // This is for Data collections
    {

        ofstream outputFile("shm_data.csv"); // This open file_stream and export the data

        if (!outputFile.is_open())
        {
            cout << "Error opening file for writing data!" << endl;
            return;
        }

        outputFile << "Time,Displacement,Velocity,Acceleration,Kinetic_Energy,Potential_Energy,Total_Energy\n"; // This for Writing the dataset header of in the output file

        double t = 0.0;
        double t_max = 3.0 * Time_Period; // Simulation of 3 full cycles using the T
        double dt = Time_Period / 100.0;

        while (t <= t_max) // This loop runs and genetrates the data for the output file
        {

            double x = A * sin(omega * t + phi);
            double v = A * omega * cos(omega * t + phi);
            double a = -omega * omega * x;

            double kinetic = 0.5 * m * v * v;
            double u = 0.5 * k * x * x;
            double e = kinetic + u;

            outputFile << t << "," << x << "," << v << "," << a << ","
                       << kinetic << "," << u << "," << e << "\n";

            t += dt; // Using this we are incrementing the time
        }

        outputFile.close();
        cout << "\nSimulation data successfully exported to 'shm_data.csv'!" << endl;
    }
};

int main()
{
    Experiment c;

    c.Experiment_input();
    c.Experiment_calculations();

    cout << "\n--- System Properties ---" << endl;
    cout << "Angular Frequency (omega): " << c.omega << " rad/s" << endl;
    cout << "Time Period (T): " << c.Time_Period << " seconds" << endl;
    cout << "--------------------------------------------" << endl;

    c.Data_Calculations();

    return 0;
}
