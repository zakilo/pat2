#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Station {
	double price, pos;
	Station() = default;
	Station(double pc, double ps) : price(pc), pos(ps) {}
};

bool cmp_pos(const Station &s1, const Station &s2)
{
	return s1.pos < s2.pos;
}

int main(void)
{
#ifdef DEBUG
	freopen("1033.txt", "r", stdin);
#endif
	double mc, dis, avg;
	int n;
	scanf("%lf%lf%lf%d", &mc, &dis, &avg, &n);
	vector<Station> vs;
	double tc, tp;
	while(n--) {
		scanf("%lf%lf", &tc, &tp);
		vs.emplace_back(tc, tp);
	}
	sort(vs.begin(), vs.end(), cmp_pos);
	// 
	double pos = 0, end = 0;	// temp position and max poistion can reach
	double tpc = numeric_limits<double>::max();	// price
	double sum=0, minp = numeric_limits<double>::max();
	vector<Station>::iterator cit;
	for(auto it=vs.begin(); it!=vs.end(); ++it) {
		// find
		minp = numeric_limits<double>::max();
		cit = vs.end();
		for(;it!=vs.end() && it->pos <= end; ++it) {
			if(it->price < tpc) {	// find the first one whose price is cheaper than previous station
				cit = it; break;
			}
			else if(it->price <= minp) {	// find the lowest price
				cit = it; minp = it->price;
			}
		}
		if(cit == vs.end())
			break;
		// cal
		if(cit->price >= tpc) {
			sum += (end-pos)/avg * tpc;
			pos = end;
		}
		else{
			sum += (cit->pos - pos)/avg * tpc;
			pos = cit->pos;
		}
		if(pos >= dis) {	// arrived
			sum -= tpc * (pos - dis)/avg; break;
		}
		tpc = cit->price;
		end = cit->pos + mc * avg;
		it = cit;	// important
	}
	if(pos < dis && end >= dis) {
		sum += (dis-pos)/avg * tpc;
		pos = dis;
	}

	//
	if(end >= dis)
		printf("%.2lf\n", sum);
	else
		printf("The maximum travel distance = %.2lf\n", end);

	return 0;
}
