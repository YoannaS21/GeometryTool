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
    std::cout << "Enter slope: ";
    std::cin >> l.slope;
    std::cout << "Enter intercept: ";
    std::cin >> l.intercept;
    return l;
}

bool isPointOnLine(Point p, Line l)
{
    double calculation = std::abs(p.y - (l.slope * p.x + l.intercept));
    return calculation < std::numeric_limits<double>::epsilon();
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

void intersectionOfTwoLines(Line l1, Line l2)
{
    if (std::abs(l1.slope - l2.slope) < std::numeric_limits<double>::epsilon())
    {
        std::cout << "The two lines don't intersect.\n";
    }
    else
    {
        double x = (l2.intercept - l1.intercept) / (l1.slope - l2.slope);
        double y = l1.slope * x + l1.intercept;
        std::cout << "The intersection point of the two lines is: x=" << x << " y=" << y << "\n";
    }
}

double distanceBetweenTwoPoints(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool isTriangle(double a, double b, double c)
{
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
    double a = distanceBetweenTwoPoints(p1, p2);
    double b = distanceBetweenTwoPoints(p2, p3);
    double c = distanceBetweenTwoPoints(p1, p3);

    if (isTriangle(a, b, c))
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
    std::cout << "The equations of the medians are:\n";
    equationOfALineByTwoPoints(p1, middlePoint(p2, p3));
    equationOfALineByTwoPoints(p2, middlePoint(p1, p3));
    equationOfALineByTwoPoints(p3, middlePoint(p1, p2));
}

void caseBisectors(Point p1, Point p2, Point p3)
{
    double slopeOfA = slopeOfLineByTwoPoints(p1, p2);
    double slopeOfB = slopeOfLineByTwoPoints(p2, p3);
    double slopeOfC = slopeOfLineByTwoPoints(p3, p1);
    std::cout << "The equations of the bisectors are:\n";
    constructHeightEquation(slopeOfA, middlePoint(p1, p2));
    constructHeightEquation(slopeOfB, middlePoint(p2, p3));
    constructHeightEquation(slopeOfC, middlePoint(p3, p1));
}

int main()
{
    std::cout << "\n Choose a tool:\n"
                 "1. Check whether a point lies on a line\n"
                 "2. From a line g and a point p, derive an equation of a line that is parallel to g and passes through p\n"
                 "3. Given a line g and a point p lying on it, derive an equation of a line perpendicular to g with a fifth at p\n"
                 "4. Given two lines, find their intersection if it exists\n"
                 "5. By triangle (set by three points) constructs equations of the heights:\n"
                 "6. By triangle (set by three points) constructs equations of the medians:\n"
                 "7. By triangle (set by three points) constructs equations of the bisectors :\n"
                 "8.Exit \n";

    while (true)
    {
        char choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
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
        case '2':
        {
            Point p = inputPoint();
            Line l = inputLine();
            parallelLine(p, l);
            break;
        }
        case '3':
        {
            Point p = inputPoint();
            Line l = inputLine();
            perpendicularLine(p, l);
            break;
        }
        case '4':
        {
            Line l1 = inputLine();
            Line l2 = inputLine();
            intersectionOfTwoLines(l1, l2);
            break;
        }
        case '5':
        {
            Point p1 = inputPoint();
            Point p2 = inputPoint();
            Point p3 = inputPoint();
            caseHeights(p1, p2, p3);
            break;
        }
        case '6':
        {
            Point p1 = inputPoint();
            Point p2 = inputPoint();
            Point p3 = inputPoint();
            caseMedians(p1, p2, p3);
            break;
        }
        case '7':
        {
            Point p1 = inputPoint();
            Point p2 = inputPoint();
            Point p3 = inputPoint();
            caseBisectors(p1, p2, p3);
            break;
        }
        case '8':
            return 0;
        }
    }
}

