//문자열 압축
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    //압축x일때 문자열 길이 
    int answer = s.length();
    //cnt-중복 수, temp-answer대입 전 비교, check-cnt자릿수
    int cnt = 1; int temp = 0; int check = 0;

    //1개 압축 부터 len의 절반까지 
    for (int n = 1; n <= s.length() / 2; n++) {
        for (int i = 0; i < s.length() - (2 * n - 1); i += n) {
            if (s.substr(i, n) == s.substr(i + n, n)) {//중복 o
                cnt++;
            }
            else {
                if (cnt == 1) {//중복 x
                    temp += n; //n개 문자 count
                }
                else {//중복 o->x
                    while (cnt / 10) {//*원인: cnt 자릿수 체크 
                        check++;
                        cnt /= 10;
                    }check++;
                    temp = temp + n + check; //cnt + n개의 문자 count
                    check = 0; cnt = 1; //check, cnt 초기화
                }
            }
        }
        if (cnt == 1) {
            temp += n;
        }
        else {
            while (cnt / 10) {
                check++;
                cnt /= 10;
            }check++;
            temp = temp + n + check;
            check = 0; cnt = 1;
        }
        //마지막 n의 나머지 만큼은 중복 비교 안함, 그냥 더해줌
        temp = temp + s.length() % n;
        if (answer > temp) {
            answer = temp;
        }
        temp = 0;//temp초기화
    }

    return answer;
}
