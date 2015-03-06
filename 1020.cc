#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>

using namespace std;

int n;
int po[30], io[30];
vector<int> lo[30];

void process(int ps, int pe, int is, int ie, int lvl)
{
	if(ps > pe || is > ie) return ;
	lo[lvl].push_back(po[pe]);
	int idx = is;
	while(idx <= ie) {
		if(io[idx] == po[pe])
			break;
		++idx;
	}
	process(ps, ps+idx-is-1, is, idx-1, lvl+1);
	process(ps+idx-is, pe-1, idx+1, ie, lvl+1);
}

int main(void)
{
#ifdef DEBUG
	freopen("1020.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for(int idx=0; idx < n; ++idx)
		scanf("%d", &po[idx]);
	for(int idx=0; idx < n; ++idx)
		scanf("%d", &io[idx]);

	process(0, n-1, 0, n-1, 0);

	printf("%d", lo[0].front());
	int idx = 1;//level
	while(!lo[idx].empty()) {
		for(auto lom : lo[idx])
			printf(" %d", lom);
		++idx;
	}

	return 0;
}
