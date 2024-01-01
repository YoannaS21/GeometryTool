#include <iostream>
#include <cmath>

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

Parabola inputParabola()
{
    Parabola par;
    std::cout << "Enter a coordinate of the parabola: ";
    std::cin >> par.a;
    std::cout << "Enter b coordinate of the parabola: ";
    std::cin >> par.b;
    std::cout << "Enter c coordinate of the parabola: ";
    std::cin >> par.c;

    return par;
}

Point inputPoint()
{
    Point p;
    std::cout << "Enter x coordinate of the point: ";
    std::cin >> p.x;
    std::cout << "Enter y coordinate of the point: ";
    std::cin >> p.y;
    return p;
}

Line inputLine()
{
    Line l;
    std::cout << "Enter slope of the line: ";
    std::cin >> l.slope;
    std::cout << "Enter intercept of the line: ";
    std::cin >> l.intercept;
    return l;
}

bool isPointOnLine(Point p, Line l)
{
    double calculation = std::abs(p.y - (l.slope * p.x + l.intercept));
    return calculation < __DBL_EPSILON__;
}

void parallelLine(Point p, Line l)
{
    Line parallelLine;
    parallelLine.slope = l.slope;
    parallelLine.intercept = p.y - parallelLine.slope * p.x;

    if (parallelLine.intercept != l.intercept)
    {
        std::cout << "The equation of the parallel line is: y=" << parallelLine.slope
                  << "x+(" << parallelLine.intercept << ")\n";
    }
    else
    {
        std::cout << "The two lines coincide.\n";
    }
}

void perpendicularLine(Point p, Line l)
{
    if (isPointOnLine(p, l))
    {
        if (l.slope != 0)
        {
            Line perpendicularLine;
            perpendicularLine.slope = -1 / l.slope;
            perpendicularLine.intercept = p.y - (perpendicularLine.slope * p.x);
            std::cout << "Equation of the perpendicular line: y=" << perpendicularLine.slope
                      << "x+(" << perpendicularLine.intercept << ")\n";
        }
    }
    else
    {
        std::cout << "The point that you entered does not lie on the line.\n";
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
    double A = p2.y - p1.y;
    double B = -(p2.x - p1.x);
    return -A / B;
}

void constructHeightEquation(double slope, Point p)
{
    if (slope != 0)
    {
        Line heightLine;
        heightLine.slope = -1 / slope;
        heightLine.intercept = p.y - (heightLine.slope * p.x);
        std::cout << "y=" << heightLine.slope << "x+(" << heightLine.intercept << ")\n";
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
        std::cout << "The points you entered don't make a triangle.\n";
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
    double slope = -A / B;
    double intercept = -C / B;

    std::cout << "y=" << slope << "x + " << intercept << "\n";
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
        std::cout << "The points you entered don't make a triangle.\n";
    }
}

void caseBisectors(Point p1, Point p2, Point p3)
{
    if (isTriangle(p1, p2, p3))
    {
        double slopeOfA = slopeOfLineByTwoPoints(p1, p2);
        double slopeOfB = slopeOfLineByTwoPoints(p2, p3);
        double slopeOfC = slopeOfLineByTwoPoints(p3, p1);
        std::cout << "The equations of the bisectors are:\n";
        constructHeightEquation(slopeOfA, middlePoint(p1, p2));
        constructHeightEquation(slopeOfB, middlePoint(p2, p3));
        constructHeightEquation(slopeOfC, middlePoint(p3, p1));
    }
    else
    {
        std::cout << "The points you entered don't make a triangle.\n";
    }
}

void tangentOfParabolaEquasion(Parabola par, Point p)
{
    // If ax^2 +bx+c=0 for x=p.x
    // because the point is on the real line y should be 0
    if ((par.a * pow(p.x, 2) + par.b * p.x + par.c == 0) && (p.y == 0))
    {

        // first derative
        double slope = 2 * par.a * p.x + par.b;
        // the eqasion is going to be in the form y=kx+m
        double k = slope;
        double m = p.y - k * p.x;
        std::cout << "The eqasion of the tangent is: y = " << k << "x + "
                  << "(" << m << ")"
                  << "\n ";
    }
    else
    {
        std::cout << "The point is not on the parabola or the point is not on the real line";
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
        std::cout << "No real roots.The parabola and the line don't intersect.\n";
    }
    else if (discriminant > 0)
    {
        double x1 = (-B + std::sqrt(discriminant)) / (2 * A);
        double x2 = (-B - std::sqrt(discriminant)) / (2 * A);

        double y1 = l.slope * x1 + l.intercept;
        double y2 = l.slope * x2 + l.intercept;

        std::cout << "The insertion points are: \n";
        std::cout << "(" << x1 << ", " << y1 << ")\n";
        std::cout << "(" << x2 << ", " << y2 << ")\n";
    }
    else if (discriminant == 0)
    {
        double x = -B / 2 * A;
        double y = l.slope * x + l.intercept;

        std::cout << "The insertion point is: ";
        std::cout << "(" << x << ", " << y << ")\n";
    }
}

bool compareTwoDoubleNums(double num1, double num2)
{
    return abs(num1 - num2) < std::numeric_limits<double>::epsilon();
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
    if ((compareTwoDoubleNums(l1.slope, l2.slope) && compareTwoDoubleNums(l2.slope, l3.slope)) ||
        (compareTwoDoubleNums(l2.slope, l3.slope) && compareTwoDoubleNums(l3.slope, l4.slope)) ||
        (compareTwoDoubleNums(l1.slope, l2.slope) && compareTwoDoubleNums(l2.slope, l4.slope)) ||
        (compareTwoDoubleNums(l1.slope, l3.slope) && compareTwoDoubleNums(l3.slope, l4.slope)))

    {
        return false;
    }

    return true;
}

void quadrilateralFormedByLines(Line l1, Line l2, Line l3, Line l4)
{
    Point A = intersectionOfTwoLines(l1, l2);
    Point B = intersectionOfTwoLines(l2, l3);
    Point C = intersectionOfTwoLines(l3, l4);
    Point D = intersectionOfTwoLines(l1, l4);

    double AB = distanceBetweenTwoPoints(A, B);
    double BC = distanceBetweenTwoPoints(B, C);
    double CD = distanceBetweenTwoPoints(C, D);
    double AD = distanceBetweenTwoPoints(A, C);
}

int main()
{
    std::cout << "\n Choose a tool:\n"
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

                 "E.Exit \n";

    while (true)
    {
        char choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case '0':
        {
            Point p = inputPoint();
            Line l = inputLine();
            if (isPointOnLine(p, l))
            {
                std::cout << "The point lies on the line.\n";
            }
            else
            {
                std::cout << "The point does not lie on the line.\n";
            }
            break;
        }
        case '1':
        {
            Point p = inputPoint();
            Line l = inputLine();
            parallelLine(p, l);
            break;
        }
        case '2':
        {
            Point p = inputPoint();
            Line l = inputLine();
            perpendicularLine(p, l);
            break;
        }
        case '3':
        {
            Line l1 = inputLine();
            Line l2 = inputLine();
            if (std::abs(l1.slope - l2.slope) < std::numeric_limits<double>::epsilon())
            {
                std::cout << "The two lines don't intersect.\n";
            }
            else
            {
                Point intersection = intersectionOfTwoLines(l1, l2);
                std::cout << "The intersection point of the two lines is: x=" << intersection.x << " y=" << intersection.y << "\n";
            }
            break;
        }
        case '4':
        {
            Point p1 = inputPoint();
            Point p2 = inputPoint();
            Point p3 = inputPoint();
            caseHeights(p1, p2, p3);
            break;
        }
        case '5':
        {
            Point p1 = inputPoint();
            Point p2 = inputPoint();
            Point p3 = inputPoint();
            caseMedians(p1, p2, p3);
            break;
        }
        case '6':
        {
            Point p1 = inputPoint();
            Point p2 = inputPoint();
            Point p3 = inputPoint();
            caseBisectors(p1, p2, p3);
            break;
        }
        case '7':
        {
            Parabola par = inputParabola();
            Point p = inputPoint();
            tangentOfParabolaEquasion(par, p);
        }
        break;

        case '8':
        {
            Parabola par = inputParabola();
            Line l = inputLine();
            intersectonPointsParabolaAnbLine(par, l);
        }
        break;

        case '9':
        {
            Line l1 = inputLine();
            Line l2 = inputLine();
            Line l3 = inputLine();
            Line l4 = inputLine();
            if (doTheLinesMakeAQuadrilateral(l1, l2, l3, l4) == false)
            {
                std::cout << "The lines don't make a quadrilateral.";
            }
            else
            {
                //quadrilateralFormedByLines(l1, l2, l3, l4);
            }
        }

        break;

        case 'E':
            return 0;
        }
    }
}
