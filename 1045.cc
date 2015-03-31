#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m, l;
int eva[201], stripe[10001];
//int dp[201][10001];
int dp[10001];

int main(void)
{
#ifdef DEBUG
	freopen("1045.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for(int idx=1; idx<=m; ++idx)
		scanf("%d", eva+idx);
	scanf("%d", &l);
	for(int idx=1; idx<=l; ++idx)
		scanf("%d", stripe+idx);
	//
	for(int idx1=1; idx1 <= m; ++idx1) {
		for(int idx2=1; idx2 <= l; ++idx2) {
			if(eva[idx1] == stripe[idx2])
				//dp[idx1][idx2] = max(dp[idx1][idx2-1], dp[idx1-1][idx2-1]) + 1;
				dp[idx2] = dp[idx2-1] + 1;
			else {
				//dp[idx1][idx2] = max(dp[idx1][idx2-1], dp[idx1-1][idx2]);
				dp[idx2] = max(dp[idx2], dp[idx2-1]);
			}
#ifdef DEBUG
			printf(" %d", dp[idx2]);
#endif
		}
#ifdef DEBUG
		printf("\n");
#endif
	}
	printf("%d\n", dp[l]);

	return 0;
}
