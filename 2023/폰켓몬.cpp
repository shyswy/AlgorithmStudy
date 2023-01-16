#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    map<int, int> hash;

    for (auto num : nums) {
        hash[num] += 1;
    }  
    return min(hash.size(), nums.size() / 2);  //map의 size: key, value 순서쌍의 개수 >>
}