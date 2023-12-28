#include <iostream>
using namespace std;
#include <cmath>

double inputPointX()
{

    cout << "Enter x coordinate of the point: ";
    double X;
    cin >> X;
    return X;
}
double inputPointY()
{
    cout << "Enter y coordinate of the point: ";
    double Y;
    cin >> Y;
    return Y;
}

double inputLineSlope()
{

    cout << "Enter slope:";
    double slope;
    cin >> slope;
    return slope;
}

double inputLineIntercept()
{
    cout << "Enter intercept:";
    double intercept;
    cin >> intercept;
    return intercept;
}

bool isPointOnLine()
{
    double x = inputPointX();
    double y = inputPointY();
    double slope = inputLineSlope();
    double intercept = inputLineIntercept();

    double calculation = abs(y - (slope * x + intercept));
    return calculation < __DBL_EPSILON__;
}

int main()
{

    cout << "\n Choose a tool:\n"
            "1. Check whether a point lies on a line\n"
            "2. \n"
            "3.Exit \n";

    while (true)
    {
        char choice;
        cout << " Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            if (isPointOnLine() == true)
            {
                cout << "The point lies on the line." << endl;
            }
            else
            {
                cout<<"The point does not lie on the line."<<endl;
            }

            break;

        case '3':
            return 0;
        }
    }
}
