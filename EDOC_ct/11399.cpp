#include <iostream>
#include <vector>
#include <map>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    multiset <int> s;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s.insert(a);
    }
    int sum = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        sum += (*iter) * n--;
    }
    cout << sum;
    return 0;
}
