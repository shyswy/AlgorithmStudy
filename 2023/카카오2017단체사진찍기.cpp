#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string str = "ACFJMNRT"; //이미 사전순으로 정렬됨.
map<string, bool> ma; //bool 디폴트= false
int solution(int n, vector<string> data) {
    int answer = 0;
    ma.clear();
    str = "ACFJMNRT";
    vector<map<char, int> >v;
    // sort(str.begin(),str.end());
    int cnt = 0;
    do {
        map<char, int> tmp;
        for (int i = 0; i < str.size(); i++)
            tmp[str[i]] = i;
        v.push_back(tmp);
    } while (next_permutation(str.begin(), str.end()));
    int cnt2 = 0;
    for (int j = 0; j < v.size(); j++) {
        bool chk = true;
        for (int i = 0; i < data.size(); i++) {
            char a = data[i][0], b = data[i][2], cmd = data[i][3];
            int num = (int)data[i][4] - 48;
            int dif = v[j][a] - v[j][b];
            if (dif < 0) dif = (-1) * dif;
            dif--;//차이가 i ==간격이 i-1
            if (cmd == '=') {
                if (dif != num) {

                    chk = false;
                    break;
                }
            }
            else if (cmd == '>') {

                if (dif <= num) {
                    chk = false;
                    break;
                }
            }
            else if (cmd == '<') {

                if (dif >= num) {
                    chk = false;
                    break;
                }
            }
        }
        if (chk == true)
            answer++;
    }
    return answer;
}