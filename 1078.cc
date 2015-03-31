#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

bool isprimer(int num)
{
	if(num == 1) return false;
	if(num == 2) return true;

	int sq = sqrt(num)+1;
	register int idx=2;
	for(idx=2; idx <= sq; ++idx)
		if(num % idx == 0)
			break;

	if(idx <= sq) return false;
	else		  return true;
}

int main(void)
{
#ifdef DEBUG
	freopen("1078.txt", "r", stdin);
#endif
	int ms, n;
	scanf("%d %d", &ms, &n);

	while(!isprimer(ms)) ++ms;

	int t, idx, pos;
	bool flag[ms];
	memset(flag, 0, sizeof(flag));

	while(n--) {
		scanf("%d", &t);
		idx = 1;
		pos = t%ms;

		while( flag[pos] && idx < ms ) {
			pos = (t + idx*idx) % ms;
			++idx;
		}

		if(idx < ms) {
			flag[pos] = true;
			if(n == 0) printf("%d", pos);
			else	   printf("%d ", pos);
		} else {
			if(n == 0) putchar('-');
			else	   printf("- ");
		}
	}
	putchar('\n');

	return 0;
}
