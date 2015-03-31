#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1065.txt", "r", stdin);
#endif
	long long a, b, c;
	int k;
	scanf("%d", &k);
	long long t;
	bool res;
	for(int idx=1; idx <= k; ++idx) {
		scanf("%lld %lld %lld", &a, &b, &c);
		t = a + b;	// if overflow, the sign of t is changed
		if( a<0 && b<0 && t>=0 ) res = false;
		else if( a>0 && b>0 && t<0 ) res = true;
		else if( t > c ) res = true;
		else res = false;

		if(res) printf("Case #%d: true\n", idx);
		else printf("Case #%d: false\n", idx);
	}

	return 0;
}
