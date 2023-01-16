#include<iostream>
using namespace std;
long long int arr[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long int  s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int st = 0, ed = 0,sum=0,ans=100001;
	//2포인터 알고리즘 st로 앞에서 줄이고, ed로 뒤에서 추가하여 연속성 유지
	while (st<=ed) {
		
		if (sum >= s) { //s 이상인거 찾으면, 앞에서 부터 제거해나가며 길이를 줄여보자!

			if (ans > (ed - st)) {
				ans = ed - st;
			}
			sum -= arr[st++];
		}
		else if (ed == n)break;      //종료조건
		else if( sum<s)   //만약 sum 이 S보다 작다면, 뒤에 1개 추가해서 부분합 증가시켜본다.
			sum += arr[ed++];
		
		
		
	}
	if (ans == 100001)
		ans = 0;
	cout << ans;
	
	
}