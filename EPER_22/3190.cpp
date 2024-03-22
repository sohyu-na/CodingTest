#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> ci;

//함수 쓰기
int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
    //우, 상, 좌 , 하
    int dr[4] = { 0,-1,0,1 };
    int dc[4] = { 1,0,-1,0 };

    //뱀 정보 초기화
    deque <ci> snake;
    snake.push_front(ci(0, 0));
    board[0][0] = 1;

    int t = 0, head = 0; //시간, 뱀의 머리 방향
    while (true) {
        t++;
        //뱀의 머리가 위치하게 될 칸
        int nr = snake.front().first + dr[head];
        int nc = snake.front().second + dc[head];

        //게임 종료 조건
        //벽에 부딪히거나 뱀의 몸과 부딪힐때
        if (nr < 0 or nr >= n or nc < 0 or nc >= n or board[nr][nc] == 1) {
            break;
        }
        
        //사과 x -> 몸 길이를 줄여서 꼬리가 위치한 칸을 비워줌
        if (board[nr][nc] != 2) {
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        //몸길이를 늘려 머리를 다음 칸에 위치시킴
        snake.push_front(ci(nr, nc));
        board[nr][nc] = 1;

        //방향 변환 확인
        if (cmd[t] == 'L') {
            head = (head + 1) % 4;
        }
        if (cmd[t] == 'D') {
            head = (head + 3) % 4;
        }
        return t;
    }
}
int solution(int n, int k, int l, vector<vector<int>>& apple, vector<int>& rotation_t, vector<char>& rotation_d) {
    vector<vector<int>> board(n, vector<int>(n));//n*n 벡터 생성
    map <int, char> cmd;
    //board에 사과 위치 표시
    for (int i = 0; i < k; i++) {
        board[apple[i][0] - 1][apple[i][1] - 1] = 2;
    }
    //시간, 회전 정보 저장
    for (int i = 0; i < l; i++) {
        cmd[rotation_t[i]] = rotation_d[i];
    }
    int answer = playGame(n, board, cmd);
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k; cin >> n>>k; //보드의 크기, 사과 개수 

    //2차원 벡터에 사과 위치 정보 저장
    vector <vector<int>> apple(k, vector<int>(2)); 
    for (int i = 0; i < k; i++) {
        cin >> apple[i][0] >> apple[i][1];
    }
    int l; cin >> l;//뱀의 변환 횟수
 
    vector <int> rotation_t(l); // 시간
    vector <char> rotation_d(l); // 방향
    for (int i = 0; i < l; i++) {
        cin >> rotation_t[i] >> rotation_d[i];
    }
    //함수 쓰고 문제푸는 연습하자 
    //연산
    int answer = solution(n, k, l, apple, rotation_t, rotation_d);
    
    //출력
    cout << answer;
    return 0;

}