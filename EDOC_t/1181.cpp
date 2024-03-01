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
    /*
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
    }*/
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) {
        //중복제거 - 정렬된 후엔 앞뒤비교만 하면 됨
        if (i!=0 and v[i-1] == v[i])
            continue;
        else
            cout << v[i]<<"\n";
    }
  
}
