#include <iostream>
#include <cstdio>
#include <fstream>
#include <limits>
#include <vector>
#include <stack>

using namespace std;

struct Road {
	int to, dis, co;
};
vector<Road> rd[502];
bool vis[502];
int dist[502], cost[502], path[502];

int main(void)
{
#ifdef DEBUG
	freopen("1030.txt", "r", stdin);
#endif
	int n, m, s, d;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	while(m--) {
		int tf, tmp;
		Road tr;
		scanf("%d%d%d%d", &tf, &tr.to, &tr.dis, &tr.co);
		rd[tf].push_back(tr);
		tmp = tf; tf = tr.to; tr.to = tmp;
		rd[tf].push_back(tr);
	}
	int start = s, dmin, cmin, next;
	while(start != d) {
		vis[start] = true;
		for(auto it=rd[start].begin(); it!=rd[start].end(); ++it) {
			if(vis[it->to]) continue;
			int tmp = dist[start] + it->dis;
			if((dist[it->to]==0 || dist[it->to] > tmp) ||\
				(dist[it->to] == tmp && (cost[it->to]==0 || cost[it->to] > cost[start]+it->co))) {
				dist[it->to] = tmp;
				cost[it->to] = cost[start] + it->co;
				path[it->to] = start;
			}
		}
		dmin = cmin = numeric_limits<int>::max();
		for(int idx=0; idx<n; ++idx) {
			if(vis[idx] || dist[idx]==0) continue;
			if((dist[idx] < dmin) || (dist[idx]==dmin && cost[idx] < cmin))
				dmin = dist[idx], cmin = cost[idx], next=idx;
		}
		start = next;
	}

	stack<int> sk;
	int end = d;
	while(end != s)
		sk.push(end), end=path[end];
	sk.push(s);
	while(!sk.empty()) {
		printf("%d ", sk.top()); sk.pop();
	}
	printf("%d %d\n", dist[d], cost[d]);

	return 0;
}
