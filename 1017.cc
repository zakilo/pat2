#include <iostream>
#include <cstdio>
#include <fstream>
#include <queue>

struct Cust {
	int time, proc;
	Cust(){}
	Cust(int t, int p) : time(t), proc(p){}
};
struct Wind {
	int time;
	Wind(int t): time(t){}
};

bool operator< (const Cust &c1, const Cust &c2)
{
	return c2.time < c1.time;
}
bool operator< (const Wind &w1, const Wind &w2)
{
	return w2.time < w1.time;
}

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1017.txt", "r", stdin);
#endif
	const int deadline = 17*3600;
	int n, m;
	scanf("%d%d", &n, &m);
	priority_queue<Wind> wind;
	priority_queue<Cust> cust;
	while(m--) {
		wind.push(Wind(8*3600));
	}
	int cnt = n;
	while(cnt--) {
		Cust ct;
		int hh, mm, ss;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &ct.proc);
		ct.time = hh*3600 + mm*60 + ss;
		if(ct.time > deadline) {
			--n;
			continue;
		}
		ct.proc *= 60;
		cust.push(ct);
	}
	int sum = 0;
	while(!cust.empty()) {
		Cust ct = cust.top(); cust.pop();
		Wind wt = wind.top(); wind.pop();
		if(wt.time > ct.time) {
			sum += wt.time - ct.time;
			wind.push(Wind(wt.time + ct.proc));
		}
		else
			wind.push(Wind(ct.time + ct.proc));
	}
	printf("%.1f\n", sum/(n*60.0));

	return 0;
}
