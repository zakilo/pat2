#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int mark[10001], num[100001];

int main(void)
{
#ifdef DEBUG
	freopen("1041.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int idx;
	for(idx=0; idx < n; ++idx) {
		scanf("%d", num+idx);
		++mark[ num[idx] ];
	}
	for(idx=0; idx < n; ++idx)
		if(mark[ num[idx] ] == 1)
			break;
	if(idx < n)
		printf("%d\n", num[idx]);
	else
		printf("None\n");

	return 0;
}
