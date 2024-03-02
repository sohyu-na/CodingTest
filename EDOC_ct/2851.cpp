#include <iostream>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int score = 0;
    for (int i = 0; i < 10; i++) {
        int a; cin >> a;
        if (score+a >= 100) {
            score = (abs(100 - (score + a)) > abs(100 - score) ? score : score + a);
            cout << score;
            return 0;
        }
        score += a;
    }
    cout<<score;
    return 0;
}
