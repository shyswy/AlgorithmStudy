#include <string>
#include <vector>
#include<map>
using namespace std;
map<string, int> ma;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (auto cloth : clothes) {
        string name = cloth[0], kind = cloth[1];
        ma[kind]++;
    }

    for (auto m : ma) {
        answer *= (m.second + 1); //옷 종류별 가짓수 +1 (안입기)
    }
    answer--;//아무것도 안입는 경우는 제외한다.

    return answer;
}