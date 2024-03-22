#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 9; //스도쿠 한 행 사이즈

bool check_row[MAX][MAX + 1]; //각 행의 숫자 존재 여부 체크
bool check_col[MAX][MAX + 1]; //각 열의 숫자 존재 여부 체크
bool check_3[MAX][MAX + 1]; //각 3x3 사각형의 숫자 존재 여부 체크

//열과 행이 주어졌을때 어떤 사각형 안에 포함되는지 
int get3x3Idx(int row, int col) {
    return (row / 3) * 3 + col / 3;
}
bool fillSudoku(int idx, vector<vector<int>> *sudoku) {
    if (idx == MAX * MAX) {//재귀로 들어가다가 false없이 스도쿠를 다 채웠을때
        return true;
    }
    int row = idx / MAX;
    int col = idx % MAX;

    //이미 값이 존재하면 다음으로 넘어감
    if ((*sudoku)[row][col]) {
        return fillSudoku(idx + 1, sudoku);
    }
    //1~9까지 넣어보고 true check
    for (int i = 1; i <= MAX; i++) {
        //셋 다 false면 
        if (!check_row[row][i] && !check_col[col][i] && !check_3[get3x3Idx(row, col)][i]) {
            check_row[row][i] = true;
            check_col[col][i] = true;
            check_3[get3x3Idx(row, col)][i] = true;

            (*sudoku)[row][col] = i;

            if (fillSudoku(idx + 1, sudoku)) {//재귀로 깊어짐
                return true;//재귀로 끝까지 갓는데도 true면 최종 true 반환
            }
            //true 반환 못했으면 이 숫자가 틀린거임
            check_row[row][i] = false;
            check_col[col][i] = false;
            check_3[get3x3Idx(row, col)][i] = false;

            (*sudoku)[row][col] = 0;
        }
    }
    //다 넣어도 없으면 앞에서부터 잘못된거임 
    //다시 back
    return false;
}
vector<vector<int>> solution(vector<vector<int>> sudoku) {
    vector<vector<int>> answer(MAX, vector<int>(MAX));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            answer[i][j] = sudoku[i][j];
            if (sudoku[i][j]) {
                //i,j가 0이 아닌 값이면
                //check에 해당 값에 true 
                check_row[i][sudoku[i][j]] = true;
                check_col[j][sudoku[i][j]] = true;
                check_3[get3x3Idx(i, j)][sudoku[i][j]] = true;
            }
        }
    }
    if (fillSudoku(0, &answer)) {
        return answer;
    }
    
}
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector <vector<int>> vv(9, vector<int>(9));
    vector<vector<int>> sudoku(MAX, vector<int>(MAX));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> sudoku[i][j];
        }
    }

    auto output = solution(sudoku);
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout<< output[i][j]<<" ";
        }
        cout << "\n";
    }
    return 0;
}


