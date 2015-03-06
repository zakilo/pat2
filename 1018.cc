#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

vector<pair<int, int> > gr[501];
int bike[501];

vector<int> pre[501];

int main(void)
{
#ifdef DEBUG
	freopen("1018.txt", "r", stdin);
#endif
	int cmax, n, sp, m;
	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
	for(int idx=1; idx <= n; ++idx)
		scanf("%d", &bike[idx]);
	for(int idx=0; idx < m; ++idx) {
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		gr[x].push_back(make_pair(y, d));
		gr[y].push_back(make_pair(x, d));
	}

	// dijkstra
	bool visit[n];
	int dis[n];
	for(int idx=0; idx<=n; ++idx)
		visit[idx] = false, dis[idx] = 0;
	int s = 0;
	while(s != sp) {
		visit[s] = true;
		int next,rmin = 0;
		for(auto grm : gr[s]) {
			if(visit[grm.first]) continue;
			if(dis[grm.first]==0 || dis[s]+grm.second < dis[grm.first]) {
				dis[grm.first] = dis[s] + grm.second;
				pre[grm.first].clear();
				pre[grm.first].push_back(s);
			}
			else if(dis[s] + grm.second == dis[grm.first]) {
				pre[grm.first].push_back(s);
			}
		}
		for(int idx=1; idx<=n; ++idx)
			if(!visit[idx] && dis[idx]!=0 && (rmin==0 || dis[idx] < rmin))
				rmin = dis[idx], next = idx;
		s = next;
	}

	// minimum path check
	stack<pair<int, vector<int>::iterator> > sk;
	vector<int> path, bestp;
	int bc;	// bike counter
	sk.push(make_pair(sp, pre[sp].begin()));
	path.push_back(sp);
	int minsd=INT_MAX, mintb=INT_MAX;
	int halfc = cmax / 2;
	int ci;
	vector<int>::iterator it;
	while(!sk.empty()) {
		ci = sk.top().first;
		it = sk.top().second;
		if(it == pre[ci].end()) {	// must before the "else if" below
			sk.pop();
			path.pop_back();
			if(!sk.empty())
				++sk.top().second;
		}
		else if(*it == 0){
			int sd=0, tb = 0;
			for(auto itp=path.rbegin(); itp != path.rend(); ++itp) {
				if(bike[*itp] >= halfc) {
					tb += bike[*itp] - halfc;
				}
				else {
					tb -= halfc - bike[*itp];
					if(tb < 0)
						sd -= tb, tb = 0;
				}
			}
			if(sd < minsd || (sd==minsd && tb<mintb))
				minsd = sd, mintb = tb, bestp = path;
			++sk.top().second;
		}
		else {
			path.push_back(*it);
			auto vp = pre[*it].begin();
			sk.push(make_pair(*it, vp));
		}
	}
	
	// output
	printf("%d 0", minsd);
	for(auto it=bestp.rbegin(); it!=bestp.rend(); ++it)
		printf("->%d", *it);
	printf(" %d\n", mintb);

	return 0;
}
