#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    //바퀴의 칸 수 n,바퀴를 돌리는 횟수 k
    int n,k; cin >> n >> k;

    // m개의 칸을 지났을때 글자 x를 가르킴 
    int m; char x;
    vector <char> v(n,0);
    int p = 0; 
    bool check=true;

    for (int i = 0; i < k; i++) {
        cin >> m >> x;
        p = (p + m) % n;
        
        if ((v[p] == 0) or (v[p] == x)) {
            //같은 글자는 두번이상 등장하지 않는다 **테스트케이스로 안걸러짐
            for (int j = 1; j < n; j++) {
                if (v[(p + j) % n] ==x)
                    check = false;
            }
            v[p] = x;
        }
        else
            check = false;
    }
    if (check) {
        for (int i = 0; i < n; i++) {
            if (v[(p - i + n) % n] == 0)
                cout << "?";
            else
                cout << v[(p - i + n) % n];
        }
    }
    else
        cout << "!";
    return 0;
}
