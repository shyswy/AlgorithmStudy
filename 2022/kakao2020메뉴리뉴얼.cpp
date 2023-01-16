#include<iostream>
#include<algorithm>
#include<cmath> //pow 함수
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<vector<char>> combs;
void Combination(string arr, vector<char> comb, int r, int index, int depth) 
//depth: n개의 목록들 중 몇번째꺼 탐색중?
//index: 현재 몇번째 까지 선택했는가 (총 r개 선택) 
{
    if (r == 0)
    {
        combs.push_back(comb);
       
        
    }
    else if (depth == arr.size())  // depth == n // 계속 안뽑다가 r 개를 채우지 못한 경우는 이 곳에 걸려야 한다.
    {
        return;
    }
    else
    {
        // arr[depth] 를 뽑은 경우
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);

        // arr[depth] 를 뽑지 않은 경우
        Combination(arr, comb, r, index, depth + 1);
    }
}
vector<string> answer;
map<string, int> ma;
vector<string> solution(vector<string> orders, vector<int> course) {
    
    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    vector<string> small_ans;
    for (int i = 0; i < course.size(); i++) { //n개짜리 코스요리
        int r = course[i];
        
        int max = -1;
        combs.clear();
        vector<char>comb(r);
        for(int j=0;j<orders.size();j++)
            Combination(orders[j], comb,r, 0, 0); //combs에 모든 가능한 조합 누적. 
       
        for (int j = 0; j < combs.size(); j++) {
           
            string tmp = "";
            for (int k = 0; k < combs[j].size(); k++) {
                tmp += combs[j][k];
               
            }
           
            ma[tmp]++;//해당 조합 ex) AC 의 개수

            //small_ans에 r개 메뉴 골라서 만들 수 있는 코스 조합중 조건부합하는 거 저장.
            if (max < ma[tmp] && ma[tmp] >= 2) {
                max = ma[tmp];
                small_ans.clear();
                small_ans.push_back(tmp);// 새로운 max 값


            }
            else if (max == ma[tmp]&&ma[tmp]>=2) {
                small_ans.push_back(tmp); //같은 max값은 넣어준다.

            }

        }
        for (int i = 0; i < small_ans.size(); i++) {
            if (small_ans[i] != "done") {   //중복 선별. 
                answer.push_back(small_ans[i]);
                small_ans[i] = "done";
            }
        }
    }
    

    sort(answer.begin(), answer.end());
    return answer;
}

int main() {

    solution({"GBCFA", "AC", "CDE", "ACDE", "BCFG", "ACDEH"
}, { 2,3,4 });
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

}