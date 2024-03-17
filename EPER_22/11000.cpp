#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    multimap <int, int> m;
    int x, y; 
    while (n--) {
        cin >> x >> y;
        m.insert(make_pair(x, y));
    }

    int num = 1; 
    multiset <int> s;
    auto iter = m.begin();
    s.insert(iter->second);
    iter++;
    for (iter; iter != m.end(); iter++) {
        auto s_iter = s.begin();
        if (iter->first >= *s_iter) {
            //s.emplace(s_iter, iter->second);
            s.erase(s_iter);
            s.insert(iter->second);
        }
        else {
            num++;
            s.insert(iter->second);
        }
    }
    cout << num;

    return 0;
}


