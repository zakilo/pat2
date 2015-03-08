// double dfs or bfs
#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <stack>
#include <cassert>
#include <set>

using namespace std;

int n;
vector<int> list[10001];
int unit[10001];
int md=0;	// max depth
set<int> dr, res;	// deepest roots
bool visit[10001];

int unit_find(int x)
{
	if(unit[x] == x) return x;
	else return unit[x] = unit_find(unit[x]);
}
void comb(int x, int y)
{
	int z = unit_find(x);
	unit[z] = unit_find(y);
}

int dfs(int root, int dp)
{
	stack<pair<int, vector<int>::iterator> > sk;
	int rt; // root
	vector<int>::iterator it;
	sk.push(make_pair(root, list[root].begin()));
	for(int idx=1; idx<=n; ++idx)
		visit[idx] = false;
	visit[root] = true;
	while(!sk.empty()) {
		rt = sk.top().first;
		it = sk.top().second;
		if(it == list[rt].end()) {
			if(dp > md) {
				md = dp; dr.clear(); dr.insert(rt);
			}
			else if(dp == md) {
				dr.insert(rt);
			}
			sk.pop(); --dp;
			if(sk.empty()) break;
			else ++sk.top().second;
		}
		else if(!visit[*it]) {
			++dp; sk.push(make_pair(*it, list[*it].begin()));
			visit[*it] = true;
		}
		else
			++sk.top().second;
	}
}

int main(void)
{
#ifdef DEBUG
	freopen("1021.txt", "r", stdin);
#endif
	scanf("%d", &n);
	if(n==1) {
		printf("1\n"); return 0;
	}
	for(int idx=1; idx<=n; ++idx)
		unit[idx] = idx;
	for(int idx=n-1; idx > 0; --idx) {
		int x, y;
		scanf("%d%d", &x, &y);
		comb(x, y);
		list[x].push_back(y);
		list[y].push_back(x);
	}
	// check components
	int cnt=0;
	for(int idx=1; idx<=n; ++idx)
		if(unit[idx] == idx)
			++cnt;
	if(cnt > 1) {
		printf("Error: %d components\n", cnt);
		return 0;
	}
	// double dfs
	dfs(1, 1);
	res.insert(dr.begin(), dr.end());
	dr.clear();
	dfs(*res.begin(), 1);
	res.insert(dr.begin(), dr.end());
	// print
	for(int resm : res)
		printf("%d\n", resm);

	return 0;
}
