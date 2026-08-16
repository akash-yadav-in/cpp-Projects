#include<iostream>

using namespace std;



int main(){
    char op;
    double num1;
    double num2;
    double result;

    cout<<"********CALCULATOR***********"<<endl;
    
    cout<<"Enter either (+ - / *): "<<endl;
    cin>>op;
    cout<<"Enter the First Number "<<endl;
    cin>>num1;
    cout<<"Enter the Second Number "<<endl;
    cin>>num2;

    switch(op){
        case '+':
        cout<<"Your Sum Result is: "<<(num1+num2)<<endl;
        break;
        case '-':
        cout<<"Your Difference Result is: "<<(num1-num2)<<endl;
        break;
        case '*':
        cout<<"Your Multiplication Result is: "<<(num1*num2)<<endl;
        break;
        case '/':
        cout<<"Your Division Result is: "<<(num1/num2)<<endl;
        break;
        
        default:
        cout<<"Enter only from these (+ - / *)"<<endl;
        break;
    }
    

    cout<<"*****************************"<<endl;

  
    

   
return 0; 
}
