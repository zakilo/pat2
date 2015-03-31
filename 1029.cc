#include <iostream>
#include <cstdio>
#include <fstream>
#include <climits>

using namespace std;

int sz1[1000001], sz2[1000001];

int main(void)
{
#ifdef DEBUG
	freopen("1029.txt", "r", stdin);
#endif
	int n1, n2;
	scanf("%d", &n1);
	for(int idx=0; idx<n1; ++idx)
		scanf("%d", &sz1[idx]);
	sz1[n1] = INT_MAX;	// important, a whistle
	scanf("%d", &n2);
	for(int idx=0; idx<n2; ++idx)
		scanf("%d", &sz2[idx]);
	sz2[n2] = INT_MAX;

	/*int l1=0, r1=n1-1, m1, l2=0, r2=n2-1, m2;
	while(l1 <= r1 && l2 <= r2) {	// every loop will cut off exact half
		m1 = (l1 + r1) / 2;
		m2 = (l2 + r2) / 2;
		if(sz1[m1] == sz2[m2]) {
			res = sz1[m1]; break;
		}
		else if(n1-1-m1 + n2-1-m2 == m1 + m2) {
			if(sz1[m1] < sz2[m2])
				r2 = m2-1;
			else r1 = m1-1;
		}
		else {	// >
			assert(n1+n2 > (m1+m2)*2+2);
			if(sz1[m1] < sz2[m2])
				l1 = m1+1;
			else l2 = m2+1;
		}
	}
	*/
	int p1=0, p2=0;
	while(p1+p2 < (n1+n2-1)/2) {
		if(sz1[p1] < sz2[p2])
			++p1;
		else ++p2;
	}
	if(sz1[p1] < sz2[p2])
		printf("%d\n", sz1[p1]);
	else
		printf("%d\n", sz2[p2]);

	return 0;
}
