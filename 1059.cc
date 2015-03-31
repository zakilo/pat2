#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>

using namespace std;

bool isprimer(int n)
{
	if(n==2) return true;
	for(int idx=sqrt(n)+1; idx>=2; --idx)
		if(n%idx==0) return false;
	return true;
}

int countMult(int &x, int p)
{
	int cnt = 0;
	while(x % p == 0) {
		++cnt; x /= p;
	}
	return cnt;
}

int main(void)
{
#ifdef DEBUG
	freopen("1059.txt", "r", stdin);
#endif
	int num;
	scanf("%d", &num);
	if(num==1 || num==2) {
		printf("%d=%d\n", num, num);
		return 0;
	}
	printf("%d=", num);
	int stop = num, cnt;
	for(int idx=2; idx<=stop; ++idx) {
		if( isprimer(idx) && num%idx==0 ) {
			cnt = countMult(num, idx);
			if(cnt == 1)
				printf("%d", idx);
			else
				printf("%d^%d", idx, cnt);

			stop = num;	// ATTENTION
			if(num == 1) break;
			else printf("*");
		}
	}
	printf("\n");

	return 0;
}
