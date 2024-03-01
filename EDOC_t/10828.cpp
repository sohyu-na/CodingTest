#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    stack <int> s;
    while (n--) {
        string input; cin >> input;
        if (input == "push") {
            int x; cin >> x;
            s.push(x);
        }
        else if (input == "pop") {
            if (s.empty())
                cout << "-1\n";
            else {
                cout << s.top()<<"\n";
                s.pop();
            }
        }
        else if (input == "size") {
            cout << s.size()<<"\n";
        }
        else if (input == "empty") {
            if (s.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (input == "top") {
            if (s.empty())
                cout << "-1\n";
            else
                cout << s.top()<<"\n";
        }
    }
    
  
}
