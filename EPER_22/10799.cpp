#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    string str; 
    getline(cin, str);
    int cnt = 0; int answer = 0;
    for (int i = 0; i<str.length(); i++) {
        if (str[i] == '(') {
            if (str[i + 1] == ')') {
                answer += cnt;
            }
            cnt++;
        }
        else {
            if (str[i - 1] == ')') {
                answer++;
            }
            cnt--;
        }
    }

    cout << answer;

    return 0;
}

