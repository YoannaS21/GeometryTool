/**
 *
 * Solution to course project # <8>
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2023/2024
 *
 * @author <Yoanna Stoeva>
 * @idnumber <3MI0600342>
 * @compiler <VC>
 *
 * <main file >
 *
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double EPSILON = 1e-9;

struct Point
{
    double x;
    double y;
};

struct Line
{
    double slope;
    double intercept;
};

struct Parabola
{
    double a;
    double b;
    double c;
};

double getDoubleInput(const char *text)
{
    // This function checks if the user's input is correct
    double value;
    cout << text;

    do
    {
        if (!(cin >> value))
        {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear(); // clears errors flags from the cin
            cin.sync();  // discard unread characters from the input buffer
            cin.ignore();
            cin >> value;
        }

    } while (!cin);

    return value;
}

Parabola inputParabola()
{
    Parabola par;
    par.a = getDoubleInput("Enter a coordinate of the parabola: ");
    par.b = getDoubleInput("Enter b coordinate of the parabola: ");
    par.c = getDoubleInput("Enter c coordinate of the parabola: ");

    return par;
}

Point inputPoint()
{
    Point p;
    p.x = getDoubleInput("Enter x coordinate of the point: ");
    p.y = getDoubleInput("Enter y coordinate of the point: ");
    return p;
}

Line inputLine()
{
    Line l;
    l.slope = getDoubleInput("Enter slope of the line: ");
    l.intercept = getDoubleInput("Enter intercept of the line: ");
    return l;
}

bool compareTwoDoubleNums(double num1, double num2)
{
    return abs(num1 - num2) < EPSILON;
}

bool isPointOnLine(Point p, Line l)
{
    double calculation = abs(p.y - (l.slope * p.x + l.intercept));
    return compareTwoDoubleNums(calculation, 0);
}

void parallelLine(Point p, Line l)
{
    // This function contsruct a line parallel to the other
    // that passes through the given point
    Line parallelLine;
    parallelLine.slope = l.slope;
    parallelLine.intercept = p.y - parallelLine.slope * p.x;

    if (!compareTwoDoubleNums(parallelLine.intercept, l.intercept))
    {
        std::cout << "The equation of the parallel line is: y=" << setprecision(2) << parallelLine.slope
                  << "x+(" << parallelLine.intercept << ")\n";
    }
    else
    {
        std::cout << "The two lines coincide.\n";
    }
}

void perpendicularLine(Point p, Line l)
{
    // The function constructs a line perpendicular to the given that passes through a certain point
    // it's said that the point lies on the given line, so we check that
    if (isPointOnLine(p, l))
    {
        if (!compareTwoDoubleNums(l.slope, 0))
        {
            Line perpendicularLine;
            perpendicularLine.slope = -1 / l.slope;
            perpendicularLine.intercept = p.y - (perpendicularLine.slope * p.x);
            cout << "Equation of the perpendicular line: y=" << setprecision(2) << perpendicularLine.slope
                 << "x+(" << perpendicularLine.intercept << ")\n";
        }
        else
        {
            cout << " The equasion of the perpendicular line is: x=" << p.x << endl;
        }
    }
    else
    {
        cout << "The point that you entered does not lie on the line.\n";
    }
}

Point intersectionOfTwoLines(Line l1, Line l2)
{
    Point intersection;

    intersection.x = (l2.intercept - l1.intercept) / (l1.slope - l2.slope);
    intersection.y = l1.slope * intersection.x + l1.intercept;
    return intersection;
}

double distanceBetweenTwoPoints(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool isTriangle(Point p1, Point p2, Point p3)
{
    double a = distanceBetweenTwoPoints(p1, p2);
    double b = distanceBetweenTwoPoints(p2, p3);
    double c = distanceBetweenTwoPoints(p1, p3);
    return a < (b + c) && b < (c + a) && c < (a + b);
}

double slopeOfLineByTwoPoints(Point p1, Point p2)
{
    // we get the slope of the line, constructed by two points, which we need in another function
    // if the line doesn't have a slope (its only x=number)
    // we give it infinity and we handle in anotherv function
    double A = p2.y - p1.y;
    double B = -(p2.x - p1.x);
    if (!compareTwoDoubleNums(A, 0) && !compareTwoDoubleNums(B, 0))
    {
        return -A / B;
    }
    else if (compareTwoDoubleNums(A, 0) && !compareTwoDoubleNums(B, 0))
    {
        return 0;
    }
    else
    {
        return INFINITY;
    }
}

void constructHeightEquation(double slope, Point p)
{
    if (!compareTwoDoubleNums(slope, 0) && slope != INFINITY)
    {
        Line heightLine;
        heightLine.slope = -1 / slope;
        heightLine.intercept = p.y - (heightLine.slope * p.x);
        cout << "y=" << setprecision(2) << heightLine.slope << "x+(" << heightLine.intercept << ")\n";
    }
    else if (compareTwoDoubleNums(slope, 0))
    {
        cout << "x=" << p.x << endl;
    }
    else if (slope == INFINITY)
    {
        cout << "y=" << p.y << endl;
    }
}

void caseHeights(Point p1, Point p2, Point p3)
{

    if (isTriangle(p1, p2, p3))
    {
        double slopeOfA = slopeOfLineByTwoPoints(p1, p2);
        double slopeOfB = slopeOfLineByTwoPoints(p2, p3);
        double slopeOfC = slopeOfLineByTwoPoints(p3, p1);
        std::cout << "The equations of the heights are:\n";
        constructHeightEquation(slopeOfA, p3);
        constructHeightEquation(slopeOfB, p1);
        constructHeightEquation(slopeOfC, p2);
    }

    else
    {
        cout << "The points you entered don't make a triangle.\n";
    }
}

Point middlePoint(Point p1, Point p2)
{
    Point middle;
    middle.x = (p1.x + p2.x) / 2;
    middle.y = (p1.y + p2.y) / 2;
    return middle;
}

void equationOfALineByTwoPoints(Point p1, Point p2)
{
    double A = p2.y - p1.y;
    double B = -(p2.x - p1.x);
    double C = -p1.x * (p2.y - p1.y) - (p2.x - p1.x) * (-p1.y);

    if (!compareTwoDoubleNums(B, 0))
    {

        double slope = -A / B;
        double intercept = -C / B;

        cout << "y=" << setprecision(2) << slope << "x + " << intercept << "\n";
    }

    else
    {
        cout << A << "x +" << B << "y+" << C << "= 0\n";
    }
}

void caseMedians(Point p1, Point p2, Point p3)
{
    if (isTriangle(p1, p2, p3))
    {

        std::cout << "The equations of the medians are:\n";
        equationOfALineByTwoPoints(p1, middlePoint(p2, p3));
        equationOfALineByTwoPoints(p2, middlePoint(p1, p3));
        equationOfALineByTwoPoints(p3, middlePoint(p1, p2));
    }

    else
    {
        cout << "The points you entered don't make a triangle.\n";
    }
}

void caseBisectors(Point p1, Point p2, Point p3)
{
    if (isTriangle(p1, p2, p3))
    {
        double slopeOfA = slopeOfLineByTwoPoints(p1, p2);
        double slopeOfB = slopeOfLineByTwoPoints(p2, p3);
        double slopeOfC = slopeOfLineByTwoPoints(p3, p1);

        cout << "The equations of the bisectors are:\n";
        constructHeightEquation(slopeOfA, middlePoint(p1, p2));
        constructHeightEquation(slopeOfB, middlePoint(p2, p3));
        constructHeightEquation(slopeOfC, middlePoint(p3, p1));
    }

    else
    {
        cout << "The points you entered don't make a triangle.\n";
    }
}

void tangentOfParabolaEquasion(Parabola par, Point p)
{
    // the point is on the real line, so p.y should be 0
    //  ax^2 +bx+c=0 for x=p.x if the point is on the line
    double result = par.a * pow(p.x, 2) + par.b * p.x + par.c;
    if (compareTwoDoubleNums(result, 0) && compareTwoDoubleNums(p.y, 0))
    {

        // first derative
        double slope = 2 * par.a * p.x + par.b;
        // the eqasion is going to be in the form y=kx+m
        double k = slope;
        double m = p.y - k * p.x;
        cout << "The eqasion of the tangent is: y = " << setprecision(2) << k << "x + "
             << "(" << m << ")"
             << "\n ";
    }

    else
    {
        cout << "The point is not on the parabola or the point is not on the real line\n";
    }
}

void intersectonPointsParabolaAnbLine(Parabola par, Line l)
{
    // we solve the eqasion
    // ax^2+bx+c=kx+m
    // so we have ax^2+(b-k)x+c-m=0
    double A = par.a;
    double B = par.b - l.slope;
    double C = par.c - l.intercept;

    double discriminant = B * B - 4 * A * C;

    if (discriminant < 0)
    {
        cout << "No real roots.The parabola and the line don't intersect.\n";
    }

    else if (discriminant > 0)
    {
        double x1 = (-B + sqrt(discriminant)) / (2 * A);
        double x2 = (-B - sqrt(discriminant)) / (2 * A);

        double y1 = l.slope * x1 + l.intercept;
        double y2 = l.slope * x2 + l.intercept;

        cout << "The insertion points are: \n";
        cout << "(" << setprecision(2) << x1 << ", " << y1 << ")\n";
        cout << "(" << x2 << ", " << y2 << ")\n";
    }

    else if (compareTwoDoubleNums(discriminant, 0))
    {
        double x = -B / 2 * A;
        double y = l.slope * x + l.intercept;

        cout << "The insertion point is: ";
        cout << "(" << x << ", " << y << ")\n";
    }
}

bool areLinesParallel(Line l1, Line l2)
{
    return compareTwoDoubleNums(l1.slope, l2.slope);
}

bool doTheLinesMakeAQuadrilateral(Line l1, Line l2, Line l3, Line l4)
{
    // Check for equal lines
    if ((compareTwoDoubleNums(l1.slope, l2.slope) && compareTwoDoubleNums(l1.intercept, l2.intercept)) ||
        (compareTwoDoubleNums(l2.slope, l3.slope) && compareTwoDoubleNums(l2.intercept, l3.intercept)) ||
        (compareTwoDoubleNums(l3.slope, l4.slope) && compareTwoDoubleNums(l3.intercept, l4.intercept)) ||
        (compareTwoDoubleNums(l1.slope, l4.slope) && compareTwoDoubleNums(l1.intercept, l4.intercept)))
    {
        return false;
    }

    // check for three parallel lines
    if ((areLinesParallel(l1, l2) && areLinesParallel(l2, l3)) ||
        (areLinesParallel(l2, l3) && areLinesParallel(l3, l4)) ||
        (areLinesParallel(l1, l2) && areLinesParallel(l2, l4)) ||
        (areLinesParallel(l1, l3) && areLinesParallel(l3, l4)))

    {
        return false;
    }

    return true;
}

void typeOfQuadrilateral(double AB, double BC, double CD, double AD, Line l, Line m)
{
    // we check if all the sides are equal
    if (compareTwoDoubleNums(AB, BC) && compareTwoDoubleNums(BC, CD) && compareTwoDoubleNums(CD, AD))
    {
        // if the lines are perpendicular, it's a square
        if (compareTwoDoubleNums(l.slope, -1 / m.slope))
        {
            cout << "It's a square.\n";
        }
        // if they aren't it'a a rombus
        else
        {
            cout << "It's a rhombus.\n";
        }
    }

    // we check if the sides 2 by 2 equal
    else if (compareTwoDoubleNums(AB, CD) && compareTwoDoubleNums(BC, AD))
    {
        if (compareTwoDoubleNums(l.slope, -1 / m.slope))
        {
            cout << "It's a rectangle.\n";
        }
        else
        {
            cout << "It's a parallelogram.\n";
        }
    }
}

void quadrilateralFormedByLines(Line l1, Line l2, Line l3, Line l4)
{
    // at first we need to know if two by two of the sides are parallel
    if (areLinesParallel(l1, l2) || areLinesParallel(l3, l4))
    {
        Point A = intersectionOfTwoLines(l1, l3);
        Point B = intersectionOfTwoLines(l1, l4);
        Point C = intersectionOfTwoLines(l2, l4);
        Point D = intersectionOfTwoLines(l2, l3);

        double AB = distanceBetweenTwoPoints(A, B);
        double BC = distanceBetweenTwoPoints(B, C);
        double CD = distanceBetweenTwoPoints(C, D);
        double AD = distanceBetweenTwoPoints(A, D);

        // if they are both parallel we go to a function
        if (areLinesParallel(l1, l2) && areLinesParallel(l3, l4))
        {
            typeOfQuadrilateral(AB, BC, CD, AD, l3, l1);
        }
        // if only one pair is parallel so it's trapezoid
        else
        {
            cout << "It's a trapezoid\n";
        }
    }

    // we repeat the same logic for different configurations of the lines, because we don't
    // know the order in which the users enters them

    else if (areLinesParallel(l1, l3) || areLinesParallel(l2, l4))
    {
        Point A = intersectionOfTwoLines(l1, l2);
        Point B = intersectionOfTwoLines(l1, l4);
        Point C = intersectionOfTwoLines(l3, l4);
        Point D = intersectionOfTwoLines(l2, l3);

        double AB = distanceBetweenTwoPoints(A, B);
        double BC = distanceBetweenTwoPoints(B, C);
        double CD = distanceBetweenTwoPoints(C, D);
        double AD = distanceBetweenTwoPoints(A, D);

        if (areLinesParallel(l1, l3) && areLinesParallel(l2, l4))
        {
            typeOfQuadrilateral(AB, BC, CD, AD, l1, l2);
        }
        else
        {
            cout << "It's a trapezoid\n";
        }
    }

    else if (areLinesParallel(l1, l4) || areLinesParallel(l2, l3))
    {
        Point A = intersectionOfTwoLines(l1, l2);
        Point B = intersectionOfTwoLines(l1, l3);
        Point C = intersectionOfTwoLines(l3, l4);
        Point D = intersectionOfTwoLines(l2, l4);

        double AB = distanceBetweenTwoPoints(A, B);
        double BC = distanceBetweenTwoPoints(B, C);
        double CD = distanceBetweenTwoPoints(C, D);
        double AD = distanceBetweenTwoPoints(A, D);

        if (areLinesParallel(l1, l4) && areLinesParallel(l2, l3))
        {
            typeOfQuadrilateral(AB, BC, CD, AD, l1, l2);
        }
        else
        {
            cout << "It's a trapezoid\n";
        }
    }
    else
    {
        cout << "It's an arbitrary quadrilateral.\n";
    }
}

void printText()
{
    cout << "\n Choose a tool:\n"
            "0. Check whether a point lies on a line\n"
            "1. From a line g and a point p, derive an equation of a line that is parallel to g and passes through p\n"
            "2. Given a line g and a point p lying on it, derive an equation of a line perpendicular to g with a fifth at p\n"
            "3. Given two lines, find their intersection if it exists\n"
            "4. By triangle (set by three points) constructs equations of the heights:\n"
            "5. By triangle (set by three points) constructs equations of the medians:\n"
            "6. By triangle (set by three points) constructs equations of the bisectors :\n"
            "7. From a given equation of a parabola and a poit on the real line derive the equation of the tangent:\n"
            "8. From given equations of parabola and line to derive their insertion points:\n"
            "9. Given four equations of lines, determine the type of quadrilateral they form when they intersect:\n"

            "10.Exit \n";
}

int main()
{

    printText();

    while (true)
    {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
        {
            Point p = inputPoint();
            Line l = inputLine();
            if (isPointOnLine(p, l))
            {
                cout << "The point lies on the line.\n";
            }
            else
            {
                cout << "The point does not lie on the line.\n";
            }
            break;
        }
        case 1:
        {
            Point p = inputPoint();
            Line l = inputLine();
            parallelLine(p, l);
            break;
        }
        case 2:
        {
            Point p = inputPoint();
            Line l = inputLine();
            perpendicularLine(p, l);
            break;
        }
        case 3:
        {
            Line l1 = inputLine();
            Line l2 = inputLine();
            if (compareTwoDoubleNums(l1.slope, l2.slope))
            {
                cout << "The two lines don't intersect.\n";
            }
            else
            {
                Point intersection = intersectionOfTwoLines(l1, l2);
                cout << "The intersection point of the two lines is:( x=" << intersection.x << " y=" << intersection.y << ")"
                     << "\n";
            }
            break;
        }
        case 4:
        {
            Point p1 = inputPoint();
            Point p2 = inputPoint();
            Point p3 = inputPoint();
            caseHeights(p1, p2, p3);
            break;
        }
        case 5:
        {
            Point p1 = inputPoint();
            Point p2 = inputPoint();
            Point p3 = inputPoint();
            caseMedians(p1, p2, p3);
            break;
        }
        case 6:
        {
            Point p1 = inputPoint();
            Point p2 = inputPoint();
            Point p3 = inputPoint();
            caseBisectors(p1, p2, p3);
            break;
        }
        case 7:
        {
            Parabola par = inputParabola();
            Point p = inputPoint();
            tangentOfParabolaEquasion(par, p);
        }
        break;

        case 8:
        {
            Parabola par = inputParabola();
            if (!compareTwoDoubleNums(par.a, 0))
            {
                Line l = inputLine();
                intersectonPointsParabolaAnbLine(par, l);
            }
            else
            {
                cout << "The coefficients of the parabola should not be zero.\n";
            }
        }
        break;

        case 9:
        {
            Line l1 = inputLine();
            Line l2 = inputLine();
            Line l3 = inputLine();
            Line l4 = inputLine();
            if (!compareTwoDoubleNums(l1.slope, 0) &&
                !compareTwoDoubleNums(l2.slope, 0) &&
                !compareTwoDoubleNums(l3.slope, 0) &&
                !compareTwoDoubleNums(l4.slope, 0))
            {

                if (doTheLinesMakeAQuadrilateral(l1, l2, l3, l4) == false)
                {
                    cout << "The lines don't make a quadrilateral.\n";
                }
                else
                {
                    quadrilateralFormedByLines(l1, l2, l3, l4);
                }
            }
            else
            {
                cout << "The slopes of the lines should not be zero.\n";
            }

            break;
        }
        case 10:
            return 0;

        default:
        {

            cout << "Invalid input. Enter new command from the above.\n";
            break;
        }
        }
    }
}
