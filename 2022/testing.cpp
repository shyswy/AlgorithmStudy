#include<iostream>
using namespace std;
#include <string>
#include <vector>

using namespace std;

int s_a = 'a';
int b_a = 'A';
int num = '0';
string solution(string new_id) {
    string answer = "";
    int i = 0;
    char tmp = new_id[0];
    char prev = 'z';
    int sz = new_id.size();

    while (i < sz) {
        tmp = new_id[i++];
        cout << tmp << " ";


        if ( prev == '.' && (tmp != '.'||i==sz-1)) {
            answer.push_back('.');


        }
        if (b_a <= (int)tmp && (int)tmp < b_a + 26) {
            // cout << tmp << " " << (char) (tmp + 32) << endl;
            answer.push_back(tmp + 32);
        }

        if ((num <= tmp && tmp <= num + 9) ||
            (s_a <= tmp && tmp < s_a + 26)
            || tmp == '-' || tmp == '_' || tmp == '.') {
            if (tmp != '.')
                answer.push_back(tmp);
        }
        int rrr = answer.size();
         cout << answer << endl;

        prev = tmp;

    }


    sz = answer.size();


    int st = 0, ed = answer.size() - 1;
    while (answer[st] == '.')//4
        st++;
    while (answer[ed] == '.' && st < ed)
        ed--;
    answer = answer.substr(st, ed - st + 1);//시작, 길이

    if (answer.size() == 0)//5
        answer.push_back('a');


    answer = answer.substr(0, 15);

    if (answer.back() == '.')//6
        answer.erase(answer.end() - 1);
    while (answer.size() <= 2) {
        answer.push_back(answer[answer.size() - 1]);
    }



    return answer;
}

int main() {
    cout << solution(".......") << endl;
   // cout << '0' << " " << '1' << " " << '9' << endl;
    
}

