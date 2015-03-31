#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Man {
	char id[10];
	int vg, tg;
};
bool cmp(const Man &m1, const Man &m2)
{
	if(m1.vg+m1.tg != m2.vg+m2.tg)
		return m1.vg+m1.tg > m2.vg+m2.tg;
	else if(m1.vg != m2.vg)
		return m1.vg > m2.vg;
	else
		return strcmp(m1.id, m2.id)<0;
}

vector<Man> sage, noble, fool, rest;

int main(void)
{
#ifdef DEBUG
	freopen("1062.txt", "r", stdin);
#endif
	int n, l, h;
	scanf("%d%d%d", &n, &l, &h);
	Man tm;
	while(n--) {
		scanf("%s %d %d", tm.id, &tm.vg, &tm.tg);
		if(tm.vg >= h && tm.tg >= h)
			sage.push_back(tm);
		else if(tm.vg >= h && tm.tg >= l)
			noble.push_back(tm);
		else if(tm.vg >= l && tm.tg >= l && tm.vg >= tm.tg)
			fool.push_back(tm);
		else if(tm.vg >= l && tm.tg >= l)
			rest.push_back(tm);
	}
	sort(sage.begin(), sage.end(), cmp);
	sort(noble.begin(), noble.end(), cmp);
	sort(fool.begin(), fool.end(), cmp);
	sort(rest.begin(), rest.end(), cmp);
	//
	printf("%d\n", sage.size()+noble.size()+fool.size()+rest.size() );
	for(auto &sm : sage)
		printf("%s %d %d\n", sm.id, sm.vg, sm.tg);
	for(auto &nm : noble)
		printf("%s %d %d\n", nm.id, nm.vg, nm.tg);
	for(auto &fm : fool)
		printf("%s %d %d\n", fm.id, fm.vg, fm.tg);
	for(auto &rm : rest)
		printf("%s %d %d\n", rm.id, rm.vg, rm.tg);

	return 0;
}
