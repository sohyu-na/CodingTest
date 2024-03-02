#include <iostream>
#include <vector>


using namespace std;
int get_sm(vector <int>& v) {
    auto max_it = v.begin();
    if (v.size() == 0)
        return 0;
    else if(v.size() != 1) {
        for (auto iter = v.begin()+1; iter != v.end(); iter++) {
            if (abs(*iter) < abs(*(max_it))) {
                max_it = iter;
            }
            else if (abs(*iter) == abs(*(max_it))) {
                max_it = (*iter > *(max_it) ? max_it : iter);
            }
        }

    }
    int k = *max_it;
    v.erase(max_it);
    return k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; vector <int> v(0);

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 0) {
            int k = get_sm(v); 
            cout << k << '\n';
        }
        else
            v.push_back(a);
    }

    return 0;
}