#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;
int who_report[1001][1002]; //1002에 1의 개수 (중복x 신고자수 저장)
int num_rept[1002]; //신고 당한 수 저장.
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for (int i = 0; i < id_list.size(); i++)
        answer.push_back(0);
    map<string, int> ma;
    for (int i = 0; i < id_list.size(); i++)
        ma[id_list[i]] = i;// ex) ma[muzi]= muzi가 몇번쨰인지.
    for (int i = 0; i < report.size(); i++) {
        int it = 0, it2 = 0;
        string str1, str2;
        while (report[i][it] != ' ') {
            str1 += report[i][it++];
        }
        it++;
        //신고한 사람
        while (it < report[i].size())
            str2 += report[i][it++];// 이름 2부터 끝까지 넣기
        //신고 당한 사람
        if (who_report[ma[str2]][ma[str1]] == 0) {
            //  cout<<ma[str1]<<" is rt:  "<<ma[str2]<<endl;
            who_report[ma[str2]][ma[str1]] = 1;   
            num_rept[ma[str2]]++; //중복x 신고자수의 수 저장.     
        }
        //신고 당한 사람의 번호 번째 배열에
        //신고자를 1로 표시 (중복 제거)
    }
    for (int i = 0; i < id_list.size(); i++) {
        if (num_rept[i] >= k) {
            for (int j = 0; j < 1001; j++) {
                if (who_report[i][j] == 1) answer[j]++;
            }
        }
    }
    return answer;
}