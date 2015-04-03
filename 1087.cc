#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <climits>

using namespace std;

const int size = 26*26*26;

int n, k, start, rome;
int happ[size];
vector<pair<int, int> > road[size];
vector<int> path[size];
bool vis[size];
int dist[size];

int hashcity(const char city[])
{
	return (city[0] - 'A')*676 + (city[1] - 'A')*26 + city[2] - 'A';
}

char* dishash(const int code)
{
	char *str = new char[5];
	str[0] = code / 676 + 'A';
	str[1] = code % 676 / 26 + 'A';
	str[2] = code % 26 + 'A';
	str[3] = 0;
	return str;
}

void dfs(int n, int &roadcnt, int &maxh, int &maxaver, vector<int> &thepath)
{
	stack< pair<int, int> > stk;	// city id and index of path[city_id]
	vector<int> stkpath;			// record the path in stack
	stk.push( make_pair(rome, 0) );
	stkpath.push_back(rome);

	while( !stk.empty() ) {
		int curcid = stk.top().first, curpos = stk.top().second;
		if(curpos == path[curcid].size() ) {	// no more branch
			stk.pop();
			stkpath.pop_back();
#ifdef DEBUG
			printf("pop %s\n", dishash(curcid));
#endif
			continue;
		}
		++stk.top().second;		// this one is checking, so skip this for next time

		curcid = path[curcid][curpos];

		if(curcid == start) {	// we find one path
			roadcnt++;

			int hapsum = 0;
			for(auto cm : stkpath)
				hapsum += happ[cm];
			int hapaver = hapsum / stkpath.size();
			
			if(hapsum > maxh || (hapsum==maxh && hapaver > maxaver)) {
				maxh = hapsum;
				maxaver = hapaver;
				thepath = stkpath;
			}
		}
		else {		// go foreward
			stk.push( make_pair(curcid, 0) );
			stkpath.push_back(curcid);
#ifdef DEBUG
			printf("push %s\n", dishash(curcid));
#endif
		}
	}
}

int main(void)
{
#ifdef DEBUG
	freopen("1087.txt", "r", stdin);
#endif
	char city[4], city2[4];
	scanf("%d %d %s", &n, &k, city);
	start = hashcity(city);
	rome = hashcity("ROM");

	int ha, dis;
	int cs[n];	// citys
	cs[0] = start;
	for(int idx=1; idx < n; ++idx) {
		scanf("%s %d", city, &ha);
		int t = hashcity(city);
		happ[t] = ha;
		cs[idx] = t;
	}
	int id1, id2;
	for(int idx=0; idx < k; ++idx) {
		scanf("%s %s %d", city, city2, &dis);
		id1 = hashcity(city);
		id2 = hashcity(city2);

		road[id1].push_back(make_pair(id2, dis));
		road[id2].push_back(make_pair(id1, dis));
	}

	// dijkstra
	for(int idx=0; idx < size; ++idx)
		vis[idx] = false, dist[idx] = INT_MAX;

	int maxd, cid = start;
	dist[start] = 0;

	while(cid != rome) {
		maxd = INT_MAX;
		vis[cid] = true;

		for(auto rm : road[cid]) {
			int to = rm.first, rdis = rm.second;
			int newdis = dist[cid] + rdis;

			if(dist[to] > newdis) {
				dist[to] = newdis;
				path[to].clear();
				path[to].push_back(cid);
			}
			else if(dist[to] == newdis)
				path[to].push_back(cid);
		}

		for(int idx=1; idx < n; ++idx)
			if(!vis[ cs[idx] ] && dist[ cs[idx] ] < maxd)
				cid=cs[idx], maxd = dist[ cs[idx] ];
	}
#ifdef DEBUG
	for(int idx = 1; idx < n; ++idx) {
		printf("%s--", dishash( cs[idx] ));
		for(auto pm : path[ cs[idx] ])
			printf("%s ", dishash(pm));
		putchar('\n');
	}
#endif

	// dfs the path
	int roadcnt=0, maxh=0, maxaver=0;
	vector<int> thepath;
	dfs(n, roadcnt, maxh, maxaver, thepath);

	//
	printf("%d %d %d %d\n%s", roadcnt, dist[rome], maxh, maxaver, dishash(start));
	for(auto it=thepath.crbegin(); it != thepath.rend(); ++it)
		printf("->%s", dishash(*it));
	putchar('\n');

	return 0;
}
