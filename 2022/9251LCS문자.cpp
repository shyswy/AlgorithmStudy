#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int dp[1010][1010];
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int m = 0;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			
			 
			if (s1[i - 1] == s2[j - 1]) {//�� ���ڰ� ���ٸ� LCS�� �����Ѵ�.
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else//�� ���ڰ� �ٸ��ٸ�, ���� LCS ���� �������µ�, �� ū ������ ������!
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			//���� ���� ������, dp[i][j] Ž�� ��, dp[i���� ���ų� ������][j���� ���ų� ������] �� ��� ä�����ִ�. 
			//���� '�̹� �������ִ�' str1�� i°�� ���� �������� ���� Lcs �� str2�� j°�� ���� ���� ���� �� �� LCS �� ū�Ÿ� �����´�.
			
		}
	}

	cout << dp[s1.size()][s2.size()] << endl;




}
