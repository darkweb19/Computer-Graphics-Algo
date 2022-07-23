// DDA Algorithm for finding the points :

#include <iostream>
#include <cmath>
using namespace std;
class CG
{
public:
// for DDA ALGORITHM...
    void DDA()
    {
        float x1, x2, y1, y2;
        cout << "Enter x1, y1, x2 and y2 : " << endl;
        cin >> x1 >> y1 >> x2 >> y2;
        float dx = x2 - x1;
        float dy = y2 - y1;
        int step;
        if (dx > dy)
        {
            step = dx;
        }
        else
        {
            step = dy;
        }

        cout << "Steps : " << step << endl;

        float xinC = dx / step;
        cout << "Increment in x : " << xinC << endl;
        float yinC = dy / step;
        cout << "Increment in y : " << yinC << endl;

        cout << "Loop and printing : " << endl;
        for (int i = 0; i <= step; i++)
        {
            cout << "x: " << ceil(x1) << endl; // for rounding off the value...
            x1 = x1 + xinC;
        }

        for (int i = 0; i <= step; i++)
        {
            cout << "  y: " << ceil(y1) << endl; // for rounding off the value...
            y1 = y1 + yinC;
        }

        float slope = dy / dx;
        ;
        cout << "Slope : " << slope << endl;
    }


    //FOR MIDPOINT CIRLCE..
    void Circle(int x_centre, int y_centre, int r)
    {
        int x = r, y = 0;

        // Printing the initial point on the axes
        // after translation
        cout << "(" << x + x_centre << ", " << y + y_centre << ") ";

        // When radius is zero only a single
        // point will be printed
        if (r > 0)
        {
            cout << "(" << x + x_centre << ", " << -y + y_centre << ") ";
            cout << "(" << y + x_centre << ", " << x + y_centre << ") ";
            cout << "(" << -y + x_centre << ", " << x + y_centre << ")\n";
        }

        // Initialising the value of P
        int P = 1 - r;
        while (x > y)
        {
            y++;

            // Mid-point is inside or on the perimeter
            if (P <= 0)
                P = P + 2 * y + 1;
            // Mid-point is outside the perimeter
            else
            {
                x--;
                P = P + 2 * y - 2 * x + 1;
            }

            // All the perimeter points have already been printed
            if (x < y)
                break;

            // Printing the generated point and its reflection
            // in the other octants after translation
            cout << "(" << x + x_centre << ", " << y + y_centre << ") ";
            cout << "(" << -x + x_centre << ", " << y + y_centre << ") ";
            cout << "(" << x + x_centre << ", " << -y + y_centre << ") ";
            cout << "(" << -x + x_centre << ", " << -y + y_centre << ")\n";

            if (x != y)
            {
                cout << "(" << y + x_centre << ", " << x + y_centre << ") ";
                cout << "(" << -y + x_centre << ", " << x + y_centre << ") ";
                cout << "(" << y + x_centre << ", " << -x + y_centre << ") ";
                cout << "(" << -y + x_centre << ", " << -x + y_centre << ")\n";
            }
        }
    }

    // FOR BRESENHAMS ALGORITHM
    void bresenham(int x1, int y1, int x2, int y2)
    {
        int m_new = 2 * (y2 - y1);
        int slope_error_new = m_new - (x2 - x1);
        for (int x = x1, y = y1; x <= x2; x++)
        {
            cout << "(" << x << "," << y << ")\n";

            // Add slope to increment angle formed
            slope_error_new += m_new;

            // Slope error reached limit, time to
            // increment y and update slope error.
            if (slope_error_new >= 0)
            {
                y++;
                slope_error_new -= 2 * (x2 - x1);
            }
        }
    }
};

void menu()
{
    cout << "1. DDA." << endl;
    cout << "2. Circle Drawing " << endl;
    cout << "3. Bresenhams" << endl;
    cout << "4. Exit" << endl;
}

int main()
{
    CG c1;
    int x1 , y1 , x2 , y2 ;
    int p1, p2, r, choice;
    do
    {
        menu();
        cout << "Enter  your choice :  " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            c1.DDA();    // 5 7 12 9
            break;
        case 2:
            cout << "Enter the points  and radius: " << endl;
            cin >> p1 >> p2 >> r;
            c1.Circle(p1, p2, r);   // 0  0 3
            break;
        case 3:
            cout << "Enterr the points : " << endl;
            cin >> x1 >> y1 >> x2 >> y2 ;
            c1.bresenham(x1, y1, x2, y2);   //3 2 15 5
            // cin  >>
            break;
        case 4:
            goto help;
            break;
        default:
            cout << "Not in Option..." << endl;
        }
    } while (choice != 4);
help:
cout << "See Ya" << endl;
    return 0;
}
