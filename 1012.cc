#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Stud {
	int id;
	int c, m, e;
	float a;
	int ra, rc, rm, re;
};

bool cmpa(const Stud &st1, const Stud &st2)
{
	return st1.a > st2.a;
}
bool cmpc(const Stud &st1, const Stud &st2)
{
	return st1.c > st2.c;
}
bool cmpm(const Stud &st1, const Stud &st2)
{
	return st1.m > st2.m;
}
bool cmpe(const Stud &st1, const Stud &st2)
{
	return st1.e > st2.e;
}

int main(void)
{
#ifdef DEBUG
	freopen("1012.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	vector<Stud> vst;
	while(n--) {
		Stud st;
		scanf("%d%d%d%d", &st.id, &st.c, &st.m, &st.e);
		st.a = (st.c + st.m + st.e) / (float)3;
		vst.push_back(st);
	}

	// average
	sort(vst.begin(), vst.end(), cmpa);
	auto vstm = vst.begin(), stpre = vst.begin();
	vstm->ra = 1;
	int cnt = 1;
	for(++vstm; vstm != vst.end(); ++vstm) {
		if(vstm->a == stpre->a)
			vstm->ra = stpre->ra, ++cnt;
		else
			vstm->ra = stpre->ra + cnt, cnt=1, stpre=vstm;
	}
	// computer
	sort(vst.begin(), vst.end(), cmpc);
	vstm = vst.begin(), stpre = vst.begin();
	vstm->rc = 1;
	cnt = 1;
	for(++vstm; vstm != vst.end(); ++vstm) {
		if(vstm->c == stpre->c)
			vstm->rc = stpre->rc, ++cnt;
		else
			vstm->rc = stpre->rc + cnt, cnt=1, stpre=vstm;
	}
	// math
	sort(vst.begin(), vst.end(), cmpm);
	vstm = vst.begin(), stpre = vst.begin();
	vstm->rm = 1;
	cnt = 1;
	for(++vstm; vstm != vst.end(); ++vstm) {
		if(vstm->m == stpre->m)
			vstm->rm = stpre->rm, ++cnt;
		else
			vstm->rm = stpre->rm + cnt, cnt=1, stpre=vstm;
	}
	// English
	sort(vst.begin(), vst.end(), cmpe);
	vstm = vst.begin(), stpre = vst.begin();
	vstm->re = 1;
	cnt = 1;
	for(++vstm; vstm != vst.end(); ++vstm) {
		if(vstm->e == stpre->e)
			vstm->re = stpre->re, ++cnt;
		else
			vstm->re = stpre->re + cnt, cnt=1, stpre=vstm;
	}

	// quary
	unordered_map<int, int> qur;
	int index = 0;
	for(auto vstm : vst) {
		qur.insert(make_pair(vstm.id, index++));
	}
	while(m--) {
		int qid;
		scanf("%d", &qid);
		auto got = qur.find(qid);
		if(got == qur.end())
			printf("N/A\n");
		else {
			Stud sgot = vst[got->second];
			if(sgot.ra <= sgot.rc && sgot.ra <= sgot.rm && sgot.ra <= sgot.re)
				printf("%d A\n", sgot.ra);
			else if(sgot.rc <= sgot.ra && sgot.rc <= sgot.rm && sgot.rc <= sgot.re)
				printf("%d C\n", sgot.rc);
			else if(sgot.rm <= sgot.rc && sgot.rm <= sgot.ra && sgot.rm <= sgot.re)
				printf("%d M\n", sgot.rm);
			else if(sgot.re <= sgot.rc && sgot.re <= sgot.rm && sgot.re <= sgot.ra)
				printf("%d E\n", sgot.re);
		}
	}

	return 0;
}
