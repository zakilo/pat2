#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Player {
	int at, h, m, s; // arrived time
	int pt; // playing time
};
struct Table {
	int id, ft; // free time
	bool vip;
	Table():id(0), ft(0), vip(false) {}
	Table(int id, int ft, bool vip) : id(id), ft(ft), vip(vip) {}
};
bool operator< (const Player &p1, const Player &p2)
{
	return p1.at < p2.at;
}
vector<Player> vpy, vvippy;
vector<Table> vt;
bool vipt[101]; // vip tables
int csp[101]; // count the number of served players by each table
const int OPEN_TIME=8*3600, CLOSED_TIME=21*3600, TIME_LIMIT=2*3600;
void process(void)
{
	vector<Player>::iterator plyit, vpyit=vpy.begin(), vvippyit=vvippy.begin();
	vector<Table>::iterator vtit, vtvipit, tblit;
	int timenow;
	while(vpyit != vpy.end() || vvippyit != vvippy.end()) {
		// update tables' time
		if(vpyit != vpy.end() && (vvippyit == vvippy.end() || vpyit->at < vvippyit->at))
			timenow = vpyit->at;
		else
			timenow = vvippyit->at;
		vtit = vtvipit = vt.end();
		for(auto tit=vt.begin(); tit!=vt.end(); ++tit) {
			if(tit->ft < timenow)
				tit->ft = timenow;
			if(!tit->vip && (vtit==vt.end() || tit->ft < vtit->ft)) vtit = tit;
			if(tit->vip && (vtvipit==vt.end() || tit->ft < vtvipit->ft)) vtvipit = tit;
		}
		if(vtit->ft >= CLOSED_TIME && vtvipit->ft >= CLOSED_TIME)
			break;
		// choose a table and a player
		/* Actually, the branches should be parted like this:
		 * 1. both normal tables and vip tables are free now
		 * 2. only vip tables are free now
		 * 3. only normal tables are free now
		 */
		if(vvippyit != vvippy.end() && vvippyit->at <= vtvipit->ft		// players should not arrived after table is free
				&& vtit->ft == vtvipit->ft && vtit->id < vtvipit->id) {	// a special case
			plyit = vvippyit++; tblit = vtvipit;
		}
		else {
			if(vtit->ft > vtvipit->ft || (vtit->ft==vtvipit->ft && vtit->id > vtvipit->id))
				tblit = vtvipit;
			else
				tblit = vtit;
			if(vvippyit!=vvippy.end() && (vpyit==vpy.end() || vpyit->at > vvippyit->at\
						|| (tblit==vtvipit && vvippyit->at <= tblit->ft) ))
				plyit = vvippyit++;
			else
				plyit = vpyit++;
		}
		++csp[tblit->id];
		// print records
		if(tblit->ft > plyit->at) {
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", plyit->h, plyit->m, plyit->s,\
					tblit->ft/3600, tblit->ft%3600/60, tblit->ft%60, (tblit->ft - plyit->at + 30)/60);
			tblit->ft += plyit->pt;
		}
		else {
			printf("%02d:%02d:%02d %02d:%02d:%02d 0\n", plyit->h, plyit->m, plyit->s,\
					plyit->h, plyit->m, plyit->s);
			tblit->ft = plyit->at + plyit->pt;
		}
	}
}
int main(void)
{
#ifdef DEBUG
	freopen("1026.txt", "r", stdin);
#endif
	int n, k, m;
	// read players
	scanf("%d", &n);
	Player py;
	int vip;
	while(n--) {
		scanf("%d:%d:%d %d %d", &py.h, &py.m, &py.s, &py.pt, &vip);
		py.at = py.h*3600 + py.m*60 + py.s;
		if(py.at >= CLOSED_TIME) continue;
		py.pt *= 60;
		if(py.pt > TIME_LIMIT) py.pt = TIME_LIMIT;
		if(vip) vvippy.push_back(py);
		else vpy.push_back(py);
	}
	sort(vpy.begin(), vpy.end());
	sort(vvippy.begin(), vvippy.end());
	// read tables
	scanf("%d%d", &k, &m);
	int t;
	while(m--) {
		scanf("%d", &t);
		vipt[t] = true;
	}
	for(int idx=1; idx <= k; ++idx)
		vt.push_back(Table(idx, OPEN_TIME, vipt[idx]));
	// in case there's no non-vip table or vip table
	vt.push_back(Table(0, CLOSED_TIME, false));
	vt.push_back(Table(0, CLOSED_TIME, true));
	process();
	printf("%d", csp[1]);
	for(int idx=2; idx<=k; ++idx)
		printf(" %d", csp[idx]);
	return 0;
}
