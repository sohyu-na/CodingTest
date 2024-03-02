#include <iostream>
#include <map>
#include <set>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;  cin >> a;
    set <int> s;
    for (int i = 0; i < a; i++) {
        int b; cin >> b;
        s.insert(b);
    }
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << "\n";
    }
    

    
}
