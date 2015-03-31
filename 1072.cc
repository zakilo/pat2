// Thank great Ted
#include <cstdio>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define INF	0x6fffffff

int n, m, k, ds;
int mapx[1015][1015];
int distances[1015];
bool flag[1015];

struct point {
	int id;
	double aver, minx;
	
	point(int id, double minx, double aver): id(id), minx(minx), aver(aver) {}
};

vector<point> out;

bool cmp(const point &a, const point &b)
{
	return a.minx==b.minx ?\
		( a.aver==b.aver ? (a.id < b.id) : (a.aver < b.aver) ) :\
		(a.minx > b.minx);
}

void dijkstra(int x)
{
	int idx, minx;
	
	for(int i=0; i < n+m; ++i) {
		distances[i] = mapx[x][i];
		flag[i] = false;
	}
	
	for(int i=0; i < n+m; ++i) {
		minx = INF;
		for(int j=0; j < n+m; ++j)
			if(distances[j] < minx && !flag[j]) {
				minx = distances[j];
				idx = j;
			}

		flag[idx] = true;
		for(int j=0; j < n+m; ++j)
			if(mapx[idx][j] + distances[idx] < distances[j])
				distances[j] = mapx[idx][j] + distances[idx];
	}

	double minDist = INF, total = 0;
	for(int i=0; i < n; ++i)
		if(i != x) {
			if(distances[i] > ds) return;
			
			if(distances[i] < minDist)
				minDist = distances[i];

			total += distances[i];
		}

	point z(x, minDist, total/n);
	out.push_back(z);
}

int check(char ch[])	// classify residential housings and stations
{
	int id = 0, x;
	int len = strlen(ch);

	if(ch[0] == 'G') x=1;
	else x= 0;

	for(; x < len; ++x)
		id = id*10 + ch[x] - '0';

	if(ch[0] == 'G') id += n;

	return id-1;
}

int main(void)
{
#ifdef DEBUG
	freopen("1072.txt", "r", stdin);
#endif
	char a[5], b[5];
	int dist;
	int x, y;
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	for(int i=0; i < n+m; ++i)
		for(int j=0; j< n+m; ++j)
			if(i==j) mapx[i][j] = 0;
			else mapx[i][j] = INF;

	for(int i=0; i<k; ++i) {
		scanf("%s %s %d", a, b, &dist);
		x = check(a);
		y = check(b);
		mapx[x][y] = mapx[y][x] = dist;
	}
	//
	for(int i=n; i< n+m; ++i)
		dijkstra(i);
	//
	if(!out.empty()) {
		sort(out.begin(), out.end(), cmp);
		printf("G%d\n%.1f %.1f\n", out[0].id-n+1, out[0].minx, out[0].aver);
	} else
		printf("No Solution\n");

	return 0;
}
