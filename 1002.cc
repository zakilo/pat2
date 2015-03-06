#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1002.txt", "r", stdin);
#endif
	int k, n;
	double a;
	double coe[1001];

	memset(coe, 0, sizeof(coe));
	int loop=2;
	while(loop-- > 0) {
		scanf("%d", &k);
		for(int idx=0; idx < k; ++idx) {
			scanf("%d%lf", &n, &a);
			coe[n] += a;
		}
	}
	int cnt = 0;
	for(int idx=1000; idx >= 0; --idx) {
		if(coe[idx] != 0) {
			++cnt;
		}
	}
	printf("%d", cnt);
	for(int idx=1000; idx >= 0; --idx) {
		if(coe[idx] != 0) {
			printf(" %d %.1lf", idx, coe[idx]);
		}
	}
	printf("\n");
	return 0;
}
