#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int cp[100000], pr[100000];

int main(void)
{
#ifdef DEBUG
	freopen("1037.txt", "r", stdin);
#endif
	int nc, np;
	scanf("%d", &nc);
	for(int idx=0; idx < nc; ++idx)
		scanf("%d", cp+idx);
	scanf("%d", &np);
	for(int idx=0; idx < np; ++idx)
		scanf("%d", pr+idx);

	sort(cp, cp+nc);
	sort(pr, pr+np);

	long long sum = 0;
	for(int idxc=0, idxp=0; idxc<nc && idxp<np && cp[idxc]<0 && pr[idxp]<0; ++idxc, ++idxp)
		sum += cp[idxc] * pr[idxp];
	for(int idxc=nc-1, idxp=np-1; idxc>=0 && idxp>=0 && cp[idxc]>0 && pr[idxp]>0; --idxc, --idxp)
		sum += cp[idxc] * pr[idxp];
	printf("%lld\n", sum);

	return 0;
}
