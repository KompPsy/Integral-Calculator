
//Libraries
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct integral{

    int a;
    int b;
    string answer= "";
    double powTO;
    double min;
    double max;
    double bx;
    double ax;
    double result;
    char x;
    string *ptr;

};

void showDescription();
void getInterval();
void getValue();
void calucate();

int main(){

    showDescription();
    getInterval();
    getValue();
    calucate();

}

void showDescription(){
    cout<<"This program calculates fractional integrals from user's input"<<endl;

    return;
}

void getInterval(){
    integral interval;
    cout<<"What is the min interval?: "<<endl;
    cin>>interval.min;
    cout<<"What is the max interval?: "<<endl;
    cin>>interval.max;
    return;

}

void getValue(){
    integral value;
    bool isValid = false;
    bool nonZero = false;

    cout<<"Enter Numerator"<<endl;
    cin>> value.a;
    cout<<"Is there a value of x? (Note: Y = Yes & N = No"<<endl;
    cin>> value.x;
    tolower(value.x);

    while(isValid == false) {
        if (value.x == 'y') {
            cout << "Power of the x value: "<<endl;
            cin >> value.powTO;

            while (nonZero == false){
                if (value.powTO == 0){
                    cout << "Input cannot be zero. It will be zero" << endl;
                    cout << "Enter a non zero number: " << endl;
                    cin >> value.powTO;
                    nonZero = false;
                }
                else if (value.powTO != 0){
                    nonZero = true;
                }
            }
            value.powTO++;
            isValid = true;
        }
        else if (value.x == 'n') {
            value.powTO = 1;
            isValid = true;
        }
        else if (value.x != 'y' || 'n') {
            cout << "Enter the correct input: (NOTE : Y = Yes or N = No)" << endl;
            cin >> value.x;
            tolower(value.x);
            isValid = false;
        }
    }

    cout<<"Enter Denumerator"<<endl;
    cin>>value.b;

    return;
}


void calucate(){
    integral computing;

    cout<<"Current Fraction: "<<computing.a<<"x^"<<computing.powTO<<"/"<<computing.b<<endl<<endl;
    computing.b = computing.b*computing.powTO;

    cout<<"New Fraction: "<<computing.a<<"x^"<<computing.powTO<<"/"<<computing.b<<endl<<endl;

    computing.bx = (computing.a*(pow(computing.max,computing.powTO))/computing.b);
    computing.ax = (computing.a*(pow(computing.min,computing.powTO))/computing.b);
    cout<<"Interval "<<computing.min<<" equals: "<<computing.ax<<endl;
    cout<<"Interval "<<computing.max<<" equals: "<<computing.bx<<endl;

    computing.result = computing.bx - computing.ax;
    computing.ptr=&computing.answer;
    cout<<"Total is: "<<computing.result<<endl;
    cout<<*computing.ptr;

    return;

}