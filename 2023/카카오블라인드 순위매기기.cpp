#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;
map<string, vector<int> > ma;

//주어진 string에서 유효한 데이터를 split하여 vector<string>에 저장
vector<string> parser(string list, int bit) { //bit: 0이면 info, 1이면 query
    vector<string> ret;
    string tmp;
    int num = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == ' ') {
            if (bit == 1 && num < 3) {
                num++;
                i += 4;
            }
            ret.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += list[i];
        }

    }
    ret.push_back(tmp);

    return ret;
}

void addPossible(vector<string> tmp) {
    vector<int> ret;

    for (int i = 0; i < 16; i++) {

        string tmp2;
        for (int j = 0; j < 4; j++) {
            tmp2 += (i & (1 << j) ? tmp[j] : "-");
        }

        ma[tmp2].push_back(stoi(tmp[4]));

    }

}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (auto inf : info) {
        vector<string> tmp = parser(inf, 0);

        addPossible(tmp);
    }

    for (auto& m : ma) sort(m.second.begin(), m.second.end());  //lower_bound 사용하려면 정렬해야한다.

    for (int k = 0; k < query.size(); k++) {
        answer.push_back(0);
        vector<string> tmp2 = parser(query[k], 1);
        string str;
        for (int j = 0; j < 4; j++) {
            str += tmp2[j];
        }
        int money = stoi(tmp2[4]);
        if (!ma[str].empty()) {
            answer[k] = ma[str].end() - lower_bound(ma[str].begin(), ma[str].end(), money); //lower_bound>> 위치값. 
            //end() - lower_bound >>> money 이상인 값의 개수
        }

    }
    return answer;
}