#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, l, k;
vector<int> fw[1010];
bool vis[1010];

int bfs(int peop)
{
	queue<int> que;

	int sum = 0, lvl = 0;
	que.push(peop);
	vis[peop] = true;
	int lvlcnt = 1, tmp;	// cnt people amount of each level
	while(!que.empty()) {
		int pe;
		tmp = 0;
		while(lvlcnt--) {
			pe = que.front();
			que.pop();

			for(int fwm : fw[pe])
				if(!vis[fwm]) {
					que.push(fwm);
					++tmp;
					vis[fwm] = true;
				}
		}
		lvlcnt = tmp;
		sum += lvlcnt;
		if(++lvl == l)
			break;
	}

	return sum;
}

int main(void)
{
#ifdef DEBUG
	freopen("1076.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &l);
	
	for(int idx=1; idx <= n; ++idx) {
		int m, t;
		scanf("%d", &m);

		while(m--) {
			scanf("%d", &t);
			fw[t].push_back(idx);
		}
	}
	//
	scanf("%d", &k);
	int t;
	while(k--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d", &t);
		printf("%d\n", bfs(t));
	}

	return 0;
}
