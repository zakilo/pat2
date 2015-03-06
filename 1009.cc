#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>

using namespace std;

map<int, double> poly1, poly_mult;

int main(void)
{
#ifdef DEBUG
	freopen("1009.txt", "r", stdin);
#endif
	int k;
	scanf("%d", &k);
	while(k--) {
		int n;
		double a;
		scanf("%d%lf", &n, &a);
		poly1.insert(make_pair(n, a));
	}
	scanf("%d", &k);
	while(k--) {
		int n;
		double a;
		scanf("%d%lf", &n, &a);
		for(auto pelem : poly1) {
			auto got = poly_mult.find(pelem.first+n) ;
			if(got == poly_mult.end())
				poly_mult.insert(make_pair(pelem.first+n, pelem.second*a));
			else {
				got->second += pelem.second * a;
				if(got->second >= -0.001 && got->second <= 0.001)	// ATTENTION !
					poly_mult.erase(got);
			}
		}
	}
	printf("%u", (unsigned)poly_mult.size());
	for(auto pelem = poly_mult.rbegin(); pelem != poly_mult.rend(); ++pelem)
		printf(" %d %.1lf", pelem->first, pelem->second);
	printf("\n");

	return 0;
}
