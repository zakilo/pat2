#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Wealth {
	char name[10];
	int age, weal;
};
bool cmp(const Wealth &w1, const Wealth &w2)
{
	if(w1.weal != w2.weal)
		return w1.weal > w2.weal;
	else if(w1.age != w2.age)
		return w1.age < w2.age;
	else
		return strcmp(w1.name, w2.name)<0;
}

int ac[201];	// amount of people excess 100 should be cut off the rest
vector<Wealth> vwtt, vw;

int main(void)
{
#ifdef DEBUG
	freopen("1055.txt", "r", stdin);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	Wealth wl;
	while(n--) {
		scanf("%s %d %d", wl.name, &wl.age, &wl.weal);
		vwtt.push_back(wl);
	}
	sort(vwtt.begin(), vwtt.end(), cmp);
	// filter
	int apcnt = 0;
	for(auto &vwttm : vwtt) {
		if(ac[vwttm.age]++ < 100)
			vw.push_back(vwttm);
	}
	// output
	int am, amin, amax;
	int cnt = 0;
	for(int idx=1; idx <= k; ++idx) {
		scanf("%d %d %d", &am, &amin, &amax);
		cnt = 0;
		printf("Case #%d:\n", idx);
		for(auto &vwm : vw) {
			if(amin <= vwm.age && vwm.age <= amax) {
				printf("%s %d %d\n", vwm.name, vwm.age, vwm.weal);
				if(++cnt == am) break;
			}
		}
		if(cnt == 0)
			printf("None\n");
	}

	return 0;
}
