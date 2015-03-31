#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s;
int wt[102];
vector<int> vll[102];
vector< vector<int> > vvpath;

bool cmpwt(int a, int b)
{
	return wt[a] > wt[b];
}

void dfs(int root)
{
	static vector<int> path;
	path.push_back(root);
	static int sumwt = 0;
	sumwt += wt[root];
	//
	if(vll[root].size() == 0 && sumwt == s)
		vvpath.push_back(path);
	else if(sumwt >= s) ;	// cut this branch
	else {
		for(auto &child : vll[root])
			dfs(child);
	}
	//
	sumwt -= wt[root];
	path.pop_back();
}

int main(void)
{
#ifdef DEBUG
	freopen("1053.txt", "r", stdin);
#endif
	scanf("%d %d %d", &n, &m, &s);
	for(int idx=0; idx < n; ++idx)
		scanf("%d", wt+idx);
	int par, k, t;
	while(m--) {
		scanf("%d %d", &par, &k);
		while(k--) {
			scanf("%d", &t);
			vll[par].push_back(t);
		}
		sort( vll[par].begin(), vll[par].end(), cmpwt );	//
	}
	//
	dfs(0);
	//
	for(auto &pathm : vvpath) {
		int last = pathm.size() -2, idx=0;
		for(idx=0; idx <= last; ++idx)
			printf("%d ", wt[ pathm[idx] ]);
		printf("%d\n", wt[ pathm[idx] ]);
	}

	return 0;
}
