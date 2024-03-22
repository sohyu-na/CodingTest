#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> matrix;
int ans = 1e8; // 최댓값 미리 설정 

//재귀로 쓰이므로 void 하고 ans를 전역변수로 
void backtracking(int n, int cnt, int cur_city, int cost, vector<bool> &visited) {
    
    if (cnt == n) { //n개의 도시 순회 했다면 
        if (matrix[cur_city][0] != 0) {//출발 도시(0)으로 돌아올 수 있는 지 확인 
            ans = min(ans, cost + matrix[cur_city][0]);
        }
        return ;
    }
    for (int i = 0; i < n; i++) {//cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) {//길이 있고 방문하지 않았을때
            visited[i] = true;
            //재귀함수 n값 그대로, 방문 도시 수 ++,현재도시 i, i 방문했을때 비용 +, 방문 검사 배열 넘기기
            backtracking(n, cnt + 1, i, cost + matrix[cur_city][i],visited);
            visited[i] = false; //재귀로 한번 끝까지 들어갓다 왔으므로 다시 false로 바꿔줌 
        }

    }
}
int solution(const int n, const vector<vector<int>>& v) {
    vector <bool> visited(n, false);
    
    visited[0] = true;//0에서 시작
    matrix = v;
    backtracking(n, 1, 0, 0,visited);

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    vector <vector<int>> v(n, vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int answer = solution(n,v);
    cout << answer;
    return 0;
}


