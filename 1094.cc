#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> ll[100];

int main(void)
{
#ifdef DEBUG
	freopen("1094.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	while(m--) {
		int id, k;
		scanf("%d%d", &id, &k);
		while(k--) {
			int t;
			scanf("%d", &t);
			ll[id].push_back(t);
		}
	}
	// see
	int maxp=1, lvl=1;
	queue<int> qi;
	qi.push(1);
	int tp=1, tl=1;
	int par, cnt=0;
	while(!qi.empty()) {
		cnt = 0;
		while(tp--) {
			par = qi.front(); qi.pop();
			for(int llm : ll[par]) {
				qi.push(llm); ++cnt;
			}
		}
		tp = cnt; ++tl;
		if(tp > maxp) {
			maxp = tp; lvl = tl;
		}
	}
	//
	printf("%d %d\n", maxp, lvl);

	return 0;
}
