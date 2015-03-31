#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int n, sum[100005];

int main(void)
{
#ifdef DEBUG
	freopen("1046.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for(int idx=1; idx <= n; ++idx) {
		scanf("%d", sum+idx);
		sum[idx] += sum[idx-1];
	}
	//
	int k;
	scanf("%d", &k);
	int l, r;
	int sh1, sh2;
	while(k--) {
		scanf("%d%d", &l, &r);
		if(l > r) {
			l^=r; r^=l; l^=r;
		}
		sh1 = sum[r-1] - sum[l-1];
		sh2 = sum[n] - sh1;
		if(sh1 < sh2)
			printf("%d\n", sh1);
		else
			printf("%d\n", sh2);
	}

	return 0;
}
