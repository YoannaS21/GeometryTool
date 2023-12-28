#include <iostream>
#include <cmath>
using namespace std;

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

void parallelLine()
{
    double x = inputPointX();
    double y = inputPointY();
    double slope = inputLineSlope();
    double intercept = inputLineIntercept();

    double parallelSlope = slope;
    double parallelIntercept = (y - parallelSlope * x);

    if (parallelIntercept != intercept)
    {
        cout << "The equasion of the parallel line is: y=" << parallelSlope << "x+"
             << "(" << parallelIntercept << ")";
    }
    else
    {
        cout << "The two lines coincide." << endl;
    }
}

void perpendicularLine()
{
    if (isPointOnLine() == true)
    {
        double x = inputPointX();
        double y = inputPointY();
        double slope = inputLineSlope();

        if (slope != 0)
        {
            double perpendicularSlope = -1 / slope;
            double perpendicularIntercept = y - (perpendicularSlope * x);
            cout << "Equasion of the perpendicular line : y=" << perpendicularSlope << "x+"
                 << "(" << perpendicularIntercept << ")" << endl;
        }
    }

    else
    {
        cout << "The point that you entered does not lie on the line." << endl;
    }
}

int main()
{

    cout << "\n Choose a tool:\n"
            "1. Check whether a point lies on a line\n"
            "2. From a line g and a point p , derive an equation of a line that is parallel to g and passes through p\n"
            "3. Given a line g and a point p lying on it, derive an equation of a line perpendicular to g with a fifth at p\n"

            "4.Exit \n";

    while (true)
    {
        char choice;
        cout << "Enter your choice: " << endl;
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
                cout << "The point does not lie on the line." << endl;
            }

            break;

        case '2':
            parallelLine();
            break;

        case '3':

            perpendicularLine();
            break;

        case '4':
            return 0;
        }
    }
}
