#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

struct User {
	int sc[6];
	bool fpr[6];	// problem marks
	int tsc;
	int perfcnt;
	bool pass;		// can be displayed
}user[10010];

int n, k, m;
int p[6];

bool cmp(int a, int b)
{
	const User &u1 = user[a], &u2 = user[b];
	int res;
	
	if(u1.tsc != u2.tsc)
		return u1.tsc > u2.tsc;
	else if(u1.perfcnt != u2.perfcnt)
		return u1.perfcnt > u2.perfcnt;
	else
		return a < b;
}

void printUser(int id, int rank)
{
	const User &us = user[id];
	printf("%d %05d %d", rank, id, us.tsc);
	for(int idx=1; idx <= k; ++idx)
		if(us.fpr[idx])
			printf(" %d", us.sc[idx]);
		else printf(" -");
	printf("\n");
}

int main(void)
{
#ifdef DEBUG
	freopen("1075.txt", "r", stdin);
#endif
	scanf("%d %d %d", &n, &k, &m);

	for(int idx=1; idx<=k; ++idx)
		scanf("%d", p+idx);

	int id, prob, scor;
	while(m--) {
		scanf("%d %d %d", &id, &prob, &scor);

		user[id].fpr[prob] = true;
		if(scor >= 0) {
			user[id].pass = true;

			if(user[id].sc[prob] < scor) {
				user[id].sc[prob] = scor;

				if(scor == p[prob])		// don't put this out, maybe more than one fullmark
					user[id].perfcnt++;
			}
		}
	}

	vector<int> vus;	// save ids
	for(int idx0=1; idx0 <= n; ++idx0) {
		if(user[idx0].pass) {
			for(int idx=1; idx <= k; ++idx)
				user[idx0].tsc += user[idx0].sc[idx];
			vus.push_back(idx0);
		}
	}
	sort(vus.begin(), vus.end(), cmp);

	printUser(vus[0], 1);
	for(int idx=1, rank=1, pre=0; idx < vus.size(); ++idx, ++pre) {
		if(user[ vus[pre] ].tsc != user[ vus[idx] ].tsc)
			rank = idx+1;

		printUser(vus[idx], rank);
	}

	return 0;
}
