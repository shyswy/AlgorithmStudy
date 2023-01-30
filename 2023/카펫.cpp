#include <string>
#include <vector>

using namespace std;


//brown= 2*w + 2(h-2) brown=테두리=가로:w, 세로:h (위아래 가로 1줄씩 제외)
//brown-2*w+4= 2*h >>h=brown/2-w+2
//brown/2=w+h-1
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;
    int ans_w = -1, ans_h = -1;
    for (int i = 1; 2 * i <= brown - 2; i++) {
        int w = i;
        int h = brown / 2 - w + 2;
        if (w * h == area) {
            if (w > h) {
                ans_w = w;
                ans_h = h;
            }
            else {
                ans_w = h;
                ans_h = w;
            }
        }

    }
    answer.push_back(ans_w);
    answer.push_back(ans_h);
    return answer;
}