#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    queue <int> s;
    while (n--) {
        string input; cin >> input;
        if (input == "push") {
            int x; cin >> x;
            s.push(x);
        }
        else if (input == "size") {
            cout << s.size()<<"\n";
        }
        else if (input == "empty") {
            /*if (s.empty())
                cout << "1\n";
            else
                cout << "0\n";*/
            cout <<(s.empty()?1:0)<<"\n";
        }
        else {
            if (s.empty())
                cout << "-1\n";
            else {
                if (input == "pop") {
                    cout << s.front() << "\n";
                    s.pop();
                }
                else if(input == "front")
                    cout << s.front() << "\n";
                else if (input == "back")
                    cout << s.back() << "\n";
            }
        }

    }
}
