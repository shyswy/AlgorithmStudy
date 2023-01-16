#include <algorithm>
#include <iostream>
using namespace std;

//vec :   1,2,3
//next_permutation( vec.begin(), vec.end() ) ->  1,2,3 의 모든 순서쌍을 순차적으로 탐색 (nPn), 단 중복은 자동제거
//  미리 오름차순 정렬이 되어있어야한다!!
// ( 중복제거기에 1,0,0 -> 1,0(1th),0(2th)  1,0(2th),0(1th)
//1,2,3
//1,3, 2



int main()
{
    std::string s = "aba";
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << '\n';
    } while (std::next_permutation(s.begin(), s.end()));
}

/* OUTPUT */
/* aab    */
/* aba    */
/* baa    */






int main()  //nCr 구하기 -> 중복값 제거되는 것을 활용
{
    int arr[5] = { 0, 0, 1, 1, 1 };   //ex) 5개중 3개 뽑기.
    sort(arr, arr + 5);
    do {
        for (int elem : arr) {  
            std::cout << elem;
        }
        std::cout << '\n';
    } while (next_permutation(arr, arr + 5));
}

// OUTPUT
// 00111
// 01011
// 01101
// 01110
// 10011
// 10101
// 10110
// 11001
// 11010
// 11100

//->  arr[i]==1 로 각 조합을 구할 수 있다.


//주어진 숫자로 만들 수 있는 모든 숫자. 
sort(v.begin(), v.end());
int val = 0, ten = 1;
do {
    ten = 1;
    val = 0;
    for (int i = v.size() - 1; i >= 0; i--) {//n개의 수
        val += v[i] * ten;// 0개, 1개, ..... n개 선택 
        if (!visit[val]) {// 중복값은 제외
            visit[val] = 1;
            if (prime[val])
                answer++;
        }
        ten *= 10; // 011 -> 마지막에 100*0 이 더해져 11이 된다.
    }

} while (next_permutation(v.begin(), v.end()));