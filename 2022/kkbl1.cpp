#include <string>
#include <vector>
#include<iostream>
#include<string.h>
#include<cstdlib>
#include<map>
using namespace std;

int arr[10];
char spl(string str) {
    int tmp = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        int tmp2 = str[i];
        if (i < 4) {//y
            arr[0] += ((tmp2 - 48) * tmp); // char > int
            tmp *= 10;
        }
        else if (4 < i && i < 7) {//m{
            arr[1] += ((tmp2 - 48) * tmp); // char > int
            tmp *= 10;
            if (i == 5) {
                tmp = 1;
            }
        }
        else if (7 < i && i < 10) {//d
            arr[2] += ((tmp2 - 48) * tmp); // char > int
            tmp *= 10;
            if (i == 8) {
                tmp = 1;
            }


        }
    }
    return str[11];// A 같은 타입 리턴 
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int td_y, td_m, td_d, tmp = 0, tens = 1;
    map<char, int> ma;
    for (int i = 0; i < terms.size(); i++) {
        tens = 1;
        tmp = 0;
        for (int j = terms[i].size() - 1; j >= 2; j--) {
            int t_in = terms[i][j] - 48;

            tmp += (t_in * tens);

            tens *= 10;
        }

        ma[terms[i][0]] = tmp;
    }
    spl(today);
    td_y = arr[0];
    td_m = arr[1];
    td_d = arr[2];

    for (int i = 0; i < privacies.size(); i++) {
        for (int i = 0; i <= 2; i++) {
            arr[i] = 0;
        }
        char typ = spl(privacies[i]);// 약관 타입 저장 + arr 배열 갱신 

        int tmp_y = arr[0], tmp_m = arr[1], tmp_d = arr[2];// 보관 가능한 기간 저장


        tmp_m += ma[typ];
        while (tmp_m > 12) {
            tmp_y += 1;
            tmp_m -= 12;
        }

        int over = false;


        if (tmp_y < td_y) over = true;

        if (tmp_y == td_y && tmp_m < td_m) over = true;
        if (tmp_y == td_y && tmp_m == td_m && tmp_d <= td_d)   over = true;


        if (over) {
            answer.push_back(i + 1);
        }



    }











    return answer;
}


