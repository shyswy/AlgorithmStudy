#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
//절반으로 나눠 모든 부분합 구한뒤, 각 그룹별 1개씩 뽑아

//https://blog.naver.com/gmlwo308/222081888774
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, s,tmp;
	cin >> n >> s;
	int m = n / 2;
	vector<int> l, r,la,ra;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		l.push_back(tmp);
		
	      
	}
	for (int i = m ; i < n; i++) {
		cin >> tmp;
		r.push_back(tmp);
	}
	for (int i = 0; i < (1 << l.size());i++) {  //2^n개 모든 부분집합 찾기 시작 
		int sum = 0;
		
		for (int j = 0; j < l.size(); j++) {
			if (   i & 1<<j ) {//해당 비트가 켜저있으면 0 이 아닌 값이 나온다!  ( 1x )
				sum += l[j];
			}
		}
		la.push_back(sum);
	}


	for (int i = 0; i < (1 << r.size()); i++) {  //2^n개 모든 부분집합 찾기 시작 
		int sum = 0;
		
		for (int j = 0; j < r.size(); j++) {
			if ((i & 1<<j) ) {
				sum += r[j];
			}
		}
		ra.push_back(sum);
	}

	sort(ra.begin(), ra.end());// 이진 탐색 위해 오른쪽 집합 정렬

	long long  ans = 0;
	for (long long  i : la) {    //   s-i + i ==s      s-i는   왼쪽 집합과 더해져 S완성되는 수
		auto l = lower_bound(ra.begin(),ra.end(), s - i); //s-i와 같거나 큰 수 가 나오는 첫 위치
		auto u = upper_bound(ra.begin(),ra.end(), s - i); //s-i보다 큰 수 가 나오는 첫위치
		ans += u - l;   //upperbound-lower bound 는 ra에서 값이 s-i인 값의 개수. 
	}
	if (s == 0)
		ans -= 1;
	cout << ans << endl;
	
	
}


//다른방식
	//두 집합으로 2포인트 알고리즘      
	//         -5 -2 0  2 3 6 8    1
	//ex) la에  -2, 0, 2, 5   들어있을 때, 만약  la의 첫째원소(-2) 과 ra의 i째원소 합이 S보다 크다면, la의 둘째원소(0) 과의 합도
	//S보다 크기 때문에 la를 진행시키면서 ra의 원소를 제외 시킬 수 있다( la 의 인덱스가 증가하면서 나오는 값들 이 전부 ra의 해당원소와
	//합쳐지면 S보다 커지기 떄문에 같을 수 없다)