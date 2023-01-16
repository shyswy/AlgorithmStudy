#include<iostream>
#include<string>
#include<algorithm>

int dp[1001][1001];
using namespace std;
int bma(int a, int b) {//max
	if (a > b) 
		
		return a;
	
	
	return b;
}
int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	int len1 = str1.length(), len2 = str2.length();
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				
				dp[i][j] = bma(dp[i - 1][j], dp[i][j - 1]);
				
			}
		}

	}
	cout << dp[len1 ][len2 ]<<endl;

}