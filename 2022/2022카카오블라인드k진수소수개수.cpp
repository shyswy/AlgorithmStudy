#include <string>
#include <vector>
#include<math.h>
#include<iostream>
using namespace std;

//211 >> 1+3*1+9*2 가 아니라 그냥 211 이다!!!!!

vector<int> v;// 0: true, 나머지: false;
int it = 0; //cvt 이후 arr 의 길이
long long int sum = 0, a = 1;
bool isPrime(long long num) {
    if (num < 2) return false;

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;

}
void cvt(int n, int k) {
    while (n > 0) {
        v.push_back((n % k));
        n /= k;
    }


}

int solution(int n, int k) {
    int answer = 0;

    cvt(n, k);

    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            sum += v[i] * a;
            a *= 10;
        }
        else {

            a = 1;
            if (sum == 0)continue;

            //   cout<<"1: "<<sum<<endl;
            if (isPrime(sum)) {


                answer++;
            }
            sum = 0;

        }



    }
    cout << sum << endl;
    if (sum != 0 && isPrime(sum)) {

        // cout<<sum<<endl;
        answer++;
    }

    return answer;
}