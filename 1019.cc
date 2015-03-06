#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1019.txt", "r", stdin);
#endif
	int n, b;
	scanf("%d%d", &n, &b);
	int num[32], idx=0;
	if(n==0)
		num[idx++]=0;
	else while(n) {
		num[idx++] = n%b;
		n /= b;
	}
	assert(idx <= 33);
	int i=0, j=idx-1;
	while(i < j)
		if(num[i]!= num[j]) break;
		else ++i, --j;	// ATTENTION !!

	if(i<j)
		printf("No\n%d", num[--idx]);
	else
		printf("Yes\n%d", num[--idx]);

	assert(idx >= 0);
	while(idx)
		printf(" %d", num[--idx]);

	return 0;
}
