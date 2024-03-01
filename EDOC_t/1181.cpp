#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    if (a.length()!= b.length())
        return a.length() < b.length();
    else 
        return a < b;
}
int main()
{
    int n; cin >> n;
    vector <string> v(n);
    int i = 0;
    while (n--) {
        string input;  cin >> input;
        bool check = true;
        for (int j = 0; j < i; j++) {
            if (v[j] == input)
                check = false;
        }
        if (check) {
            v[i] = input; i++;
        }
    }
    v.resize(i); 
    sort(v.begin(), v.end(), cmp);
    for (auto iter=v.begin();iter!=v.end();iter++) {
        cout << *iter <<"\n";
    }
  
}
