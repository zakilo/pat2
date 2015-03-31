#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m;
int coin[10004], dp[10004][102];
bool path[10004][102];

int main(void)
{
#ifdef DEBUG
	freopen("1068.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	for(int idx=1; idx<=n; ++idx)
		scanf("%d", &coin[idx]);
	sort(coin+1, coin+n+1, greater<int>());
	//
	for(int idx=1; idx <= n; ++idx) {
		for(int idx2=coin[idx]; idx2 <= m; ++idx2) {
			if(dp[idx-1][idx2] <= dp[idx-1][ idx2-coin[idx] ]+coin[idx]) {
				dp[idx][idx2] = dp[idx-1][ idx2-coin[idx] ] + coin[idx];
				path[idx][idx2] = true;
			}
			else {
				dp[idx][idx2] = dp[idx-1][idx2];
				path[idx][idx2] = false;
			}
		}
	}
	//
	if(dp[n][m] != m)
		printf("No Solution\n");
	else {
		int tmp = m, idx = n;
		while(tmp > 0) {
			if(path[idx][tmp]) {
				printf("%d", coin[idx]);
				tmp -= coin[idx];
				if(tmp > 0) printf(" ");
			}
			--idx;
		}
		printf("\n");
	}

	return 0;
}
