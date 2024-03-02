#include <iostream>
#include <map>

using namespace std;

int main() 
{
    map <char, int> m;
    string str; cin >> str;
    //toupper(문자)
    for (int i = 0; i < str.length(); i++) {
        m[toupper(str[i])]++;
    }

    int max = m['A']; char maxChar ='A';
    int cnt = 0;
    for (char i = 'B'; i <= 'Z'; i++) {
        if (max < m[i]) {
            max = m[i]; maxChar=  i;
            cnt = 0;
        }
        else if (max == m[i]) {
            cnt++;
        }
    }
    
    if (cnt > 0)
        cout << "?";
    else
        cout << maxChar;

    return 0;
}