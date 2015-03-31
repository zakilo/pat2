#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1042.txt", "r", stdin);
#endif
	int k;
	scanf("%d", &k);
	int ord[55], num[3][55];
	for(int idx=1; idx<=54; ++idx) {
		scanf("%d", ord+idx);
		num[1][idx] = num[2][idx] = idx;
	}
	//
	int p1=1, p2=2;
	while(k--) {
		for(int idx=1; idx<=54; ++idx)
			num[p1][ ord[idx] ] = num[p2][idx];
		p1 ^= p2; p2 ^= p1; p1^=p2;
#ifdef DEBUG
		for(int idx=1; idx<=53; ++idx)
			printf("%c%d ", "SHCDJ"[ (num[p1][idx]-1)/13 ], (num[p1][idx]-1)%13+1);
		printf("%c%d\n", "SHCDJ"[ (num[p1][54]-1)/13 ], (num[p1][54]-1)%13+1);
#endif
	}
	//
	for(int idx=1; idx<=53; ++idx)
		printf("%c%d ", "SHCDJ"[ (num[p2][idx]-1)/13 ], (num[p2][idx]-1)%13+1);
	printf("%c%d\n", "SHCDJ"[ (num[p2][54]-1)/13 ], (num[p2][54]-1)%13+1);

	return 0;
}

