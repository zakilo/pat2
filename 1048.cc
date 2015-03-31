#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int n, m;
int coin[1003];

int main(void)
{
#ifdef DEBUG
	freopen("1048.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	int val;
	while(n--) {
		scanf("%d", &val);
		++coin[val];
	}
	//
	int idx = 0;
	for(idx=0; idx <= 500; ++idx) {
		if( (idx*2 == m && coin[idx] > 1) || (idx*2 != m && coin[idx] && coin[m-idx]) )
			break;
	}
	//
	if(idx <= 500)
		printf("%d %d\n", idx, m-idx);
	else
		printf("No Solution\n");

	return 0;
}
