#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct MC {
	double am, pr;
	double val;
}mc[1003];
bool cmp(const MC &m1, const MC &m2)
{
	return m1.val > m2.val;
}

int main(void)
{
#ifdef DEBUG
	freopen("1070.txt", "r", stdin);
#endif
	int n, d;
	scanf("%d%d", &n, &d);
	for(int idx=0; idx < n; ++idx)
		scanf("%lf", &mc[idx].am);
	for(int idx=0; idx < n; ++idx)
		scanf("%lf", &mc[idx].pr);
	//
	for(int idx=0; idx < n; ++idx)
		mc[idx].val = mc[idx].pr/mc[idx].am;
	sort(mc, mc+n, cmp);
	//
	double sump = 0;
	for(int idx=0; idx < n; ++idx) {
		if(mc[idx].am <= d) {
			d -= mc[idx].am;
			sump += mc[idx].pr;
		}
		else {
			sump += mc[idx].pr * d / mc[idx].am;
			break;
		}
	}
	printf("%.2f\n", sump);

	return 0;
}
