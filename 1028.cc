#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct Stud {
	int id, sc;
	char nm[10];
};

bool cmpid(const Stud &s1, const Stud &s2)
{
	return s1.id < s2.id;
}
bool cmpsc(const Stud &s1, const Stud &s2)
{
	if(s1.sc != s2.sc)
		return s1.sc < s2.sc;
	else
		return s1.id < s2.id;
}
bool cmpnm(const Stud &s1, const Stud &s2)
{
	int res = strcmp(s1.nm, s2.nm);
	if(res != 0)
		return res < 0;
	else
		return s1.id < s2.id;
}

typedef bool (*CmpFun)(const Stud &, const Stud &);

int main(void)
{
#ifdef DEBUG
	freopen("1028.txt", "r", stdin);
#endif
	CmpFun cmp[3] = {cmpid, cmpnm, cmpsc};
	int n, c;
	scanf("%d%d", &n, &c);
	vector<Stud> vs;
	while(n--) {
		Stud ts;
		scanf("%d%s%d", &ts.id, ts.nm, &ts.sc);
		vs.push_back(ts);
	}
	sort(vs.begin(), vs.end(), cmp[c-1]);
	for(const auto &vsm : vs)
		printf("%06d %s %d\n", vsm.id, vsm.nm, vsm.sc);

	return 0;
}
