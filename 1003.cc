#include <iostream>
#include <fstream>
#include <climits>
#include <cstring>

using namespace std;

int team[501], graph[501][501];

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1003.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	for(int idx=0; idx<n; ++idx)
		cin >> team[idx];
	for(int idx; idx<m; ++idx) {
		int x, y, l;
		cin >> x >> y >> l;
		graph[x][y] = graph[y][x] = l;
	}

	//dijkstra
	int s = c1, min=0, candidate;
	int dis[501], road[501], team_cnt[501];
	bool visit[501];
	memset(visit, 0, sizeof(visit));
	memset(dis,   0, sizeof(dis));
	memset(road, 0, sizeof(road));
	memset(team_cnt, 0, sizeof(team_cnt));
	road[s] = 1;
	team_cnt[s] = team[s];
	for(int idx1=1; idx1 < n; ++idx1) {
		visit[s] = true;
		min = INT_MAX;
		for(int idx2=0; idx2 < n; ++idx2) {
			if(!visit[idx2] && graph[s][idx2] != 0) {
				if(dis[idx2]==0 || dis[idx2] > dis[s]+graph[s][idx2]) {
					dis[idx2] = dis[s] + graph[s][idx2];
					road[idx2] = road[s];
					team_cnt[idx2] = team_cnt[s] + team[idx2];
				}
				else if(dis[idx2] == dis[s]+graph[s][idx2]) {
					road[idx2] += road[s];
					if(team_cnt[s] + team[idx2] > team_cnt[idx2])
						team_cnt[idx2] = team_cnt[s] + team[idx2];
				}
			}
			if(!visit[idx2] && dis[idx2] != 0 && dis[idx2] < min) {
				min = dis[idx2];
				candidate = idx2;
			}
		}
		if(candidate == c2)
			break;
		s = candidate;
	}
	cout << road[c2] << " " << team_cnt[c2] << endl;
	return 0;
}
