#include <iostream>
#include <cstdio>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

set<int> numset[52];

int main(void)
{
#ifdef DEBUG
	freopen("1063.txt", "r", stdin);
#endif
	int n, m, k;
	scanf("%d", &n);
	//
	int t;
	for(int idx=1; idx <= n; ++idx) {
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &t);
			numset[idx].insert(t);
		}
	}
	//
	scanf("%d", &k);
	vector<int> res;
	int first, second;
	int nc, nt;
	while(k--) {
		scanf("%d %d", &first, &second);
		res.clear();
		set_intersection( numset[first].begin(), numset[first].end(),\
				numset[second].begin(), numset[second].end(),\
				inserter(res, res.begin()) );
		nc = res.size();
		nt = numset[first].size() + numset[second].size() - nc;
		printf("%.1lf%%\n", (nc*100.0)/nt );
	}

	return 0;
}
