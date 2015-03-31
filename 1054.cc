#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int m, n;
int image[802][602];

int main(void)
{
#ifdef DEBUG
	freopen("1054.txt", "r", stdin);
#endif
	scanf("%d %d", &m, &n);
	int tt = m*n, val=0, dom=-1, cnt=0;
	while(tt--) {
		scanf("%d", &val);
		if(val == dom) ++cnt;
		else if(--cnt < 0) dom = val;
	}
	printf("%d\n", dom);

	return 0;
}
