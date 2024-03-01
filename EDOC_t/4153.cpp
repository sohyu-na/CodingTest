#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    while (true) {
        int a, b, c; cin >> a >> b >> c;
        if (c > a and c > b) {
            if (c * c == a * a + b * b)
                cout << "right" << "\n";
            else
                cout << "wrong" << "\n";
        }
        else if (b > a and b > c) {
            if (b * b == a * a + c * c)
                cout << "right" << "\n";
            else
                cout << "wrong" << "\n";
        }
        else if (a > b and a > c) {
            if (a * a == b * b + c * c)
                cout << "right" << "\n";
            else
                cout << "wrong" << "\n";
        }
        else if (a == 0 and b == 0 and c == 0)
            return 0;
        else
            break;
    }
}
