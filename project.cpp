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

bool isPointOnLine(double x, double y, double slope, double intercept)
{

    double calculation = abs(y - (slope * x + intercept));
    return calculation < __DBL_EPSILON__;
}

void parallelLine(double x, double y, double slope, double intercept)
{

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

void perpendicularLine(double x, double y, double slope, double intercept)
{
    if (isPointOnLine(x, y, slope, intercept) == true)
    {

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

void intersectionOfTwoLines(double slope1, double intercept1, double slope2, double intercept2)
{

    if (abs(slope1 - slope2) < __DBL_EPSILON__)
    {
        cout << "The two lines don't intersect.";
        return;
    }
    else
    {
        double x = (intercept2 - intercept1) / (slope1 - slope2);
        double y = slope1 * x + intercept1;
        cout << "The intersection point of the two lines is: x=" << x << " "
             << "y=" << y << endl;
    }
}

double distanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}

bool isTriangle(double a, double b, double c)
{
    if (a < (b + c) && b < (c + a) && c < (a + b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

double slopeOflineByTwoPoints(double x1, double y1, double x2, double y2)
{

    double slope = (x2 - x1) / (y2 - y1);
    return slope;
}

void constructHeightEqasion(double slope, double x, double y)
{
    if (slope != 0)
    {
        double heightSlope = -1 / slope;
        double heightIntercept = y - (heightSlope * x);
        cout << "y=" << heightSlope << "x+"
             << "(" << heightIntercept << ")" << endl;
    }
}

void caseHeights(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = distanceBetweenTwoPoints(x1, y1, x2, y2);
    double b = distanceBetweenTwoPoints(x2, y2, x3, y3);
    double c = distanceBetweenTwoPoints(x1, y1, x3, y3);

    if (isTriangle(a, b, c) == true)
    {
        double slopeOfA = slopeOflineByTwoPoints(x1, y1, x2, y2);
        double slopeOfB = slopeOflineByTwoPoints(x2, y2, x3, y3);
        double slopeOfC = slopeOflineByTwoPoints(x3, y3, x1, y1);
        cout << "The eqasions of the heights are:" << endl;
        constructHeightEqasion(slopeOfA, x3, y3);
        constructHeightEqasion(slopeOfB, x1, y1);
        constructHeightEqasion(slopeOfC, x2, y2);
    }
    else
    {
        cout << "The points youi entered don't make a triangle." << endl;
    }
}

double middleX(double x1, double x2)
{

    return (x1 + x2) / 2;
}

double middleY(double y1, double y2)
{

    return (y1 + y2) / 2;
}

void equasionOfALineByTwoPoints(double x1, double y1, double x2, double y2)
{
    double A = y2 - y1;
    double B = -(x2 - x1);
    double C = -x1 * (y2 - y1) - (x2 - x1) * (-y1);
    double slope = -A / B;
    double intercept = -C / B;

    cout << "y= " << slope << "x + " << (intercept)<<endl;;
}

void caseMedians(double x1, double y1, double x2, double y2, double x3, double y3)
{
    cout<<"The equasions of the medians are: "<<endl;
    equasionOfALineByTwoPoints(x1, y1, middleX(x2, x3), middleY(y2, y3));
    equasionOfALineByTwoPoints(x2, y2, middleX(x1, x3), middleY(y1, y3));
    equasionOfALineByTwoPoints(x3, y3, middleX(x1, x2), middleY(y1, y2));
}

int main()
{

    cout << "\n Choose a tool:\n"
            "1. Check whether a point lies on a line\n"
            "2. From a line g and a point p , derive an equation of a line that is parallel to g and passes through p\n"
            "3. Given a line g and a point p lying on it, derive an equation of a line perpendicular to g with a fifth at p\n"
            "4. Given two lines, find their intersection if it exists\n"
            "5. By triangle (set by three points) constructs equations of the heights:\n"
            "6. By triangle (set by three points) constructs equations of the medians:\n"
            "7. By triangle (set by three points) constructs equations of the bisectors :\n"

            "8.Exit \n";

    while (true)
    {
        char choice;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case '1':

            if (isPointOnLine(inputPointX(), inputPointY(), inputLineSlope(), inputLineIntercept()) == true)
            {
                cout << "The point lies on the line." << endl;
            }
            else
            {
                cout << "The point does not lie on the line." << endl;
            }

            break;

        case '2':
            parallelLine(inputPointX(), inputPointY(), inputLineSlope(), inputLineIntercept());
            break;

        case '3':

            perpendicularLine(inputPointX(), inputPointY(), inputLineSlope(), inputLineIntercept());
            break;

        case '4':
            intersectionOfTwoLines(inputLineSlope(), inputLineIntercept(), inputLineSlope(), inputLineIntercept());
            break;

        case '5':
            caseHeights(inputPointX(), inputPointY(), inputPointX(), inputPointY(), inputPointX(), inputPointY());
            break;

        case '6':
        caseMedians(inputPointX(), inputPointY(), inputPointX(), inputPointY(), inputPointX(), inputPointY());
            break;

        case '8':
            return 0;
        }
    }
}
