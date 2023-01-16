#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int dp[1001][1001];
string lcs[1001][1001];
int main() {   //더 이쁘게 짠 코드 가져옴. 설명은 아래 내가짠 코드 참고하자!
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str1, str2;

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				lcs[i][j] = lcs[i - 1][j - 1] + str1[i - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				lcs[i][j] = (lcs[i - 1][j].length() > lcs[i][j - 1].length()) ? lcs[i - 1][j] : lcs[i][j - 1];
			}
		}
	}
	if (dp[str1.length()][str2.length()] != 0)
		cout << dp[str1.length()][str2.length()] << '\n' << lcs[str1.length()][str2.length()] << '\n';
	else
		cout << 0;
}


/*

* me
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
pair<int, int> path[1001][1001];
int dp[1001][1001];
int bma(int i,int j,int a, int b) {//max
	if (a > b) {
		path[i][j] = { i - 1,j };  //이전의 위치가 LCS에 포함되지 않는 '거쳐가는' 경로여도, LCS로 향하기 위해 저장해야한다.
		return a;
	}
	path[i][j] = { i,j - 1 };


	return b;
}
//경로 추적 추가!
int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	int len1 = str1.length(), len2 = str2.length();
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				path[i][j] = { i - 1,j - 1 };  //dp가 갱신되는 유일한 케이스 
			}
			else {
				dp[i][j] = bma(i,j,dp[i - 1][j], dp[i][j - 1]);
			}
		}

	}
	cout << dp[len1][len2] << endl;
	int i=len1, j=len2,f,s;
	
	vector<char> v;
	
	while ( 1 ) { //경로추격.
		
		int f = path[i][j].first, s = path[i][j].second;
		
		if (dp[i][j]-1==dp[f][s]) {  //해당 경로가 '거쳐가는' 경로가 아닌, 실제 LCS 경로인가?
			v.push_back(str1[i-1]);
			
		}
		i = f;
		j = s;
		if (i == 0 || j == 0)break;
	}
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i];
	

}

*/