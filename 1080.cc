#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

struct Appl {
	int id;
	int ge, gi;
	int gt;		// ge+gi
	int scho[5];

	bool operator== (const Appl &a) {
		return (this->ge==a.ge && this->gi==a.gi);
	}
}appl[40010];

bool cmp(const Appl &a1, const Appl &a2) {
	if(a1.gt != a2.gt)
		return a1.gt > a2.gt;
	else
		return a1.ge > a2.ge;
}

int quota[110];
vector<int> admi[110];	// save admissions' position of appl, not ids!

bool cmp_admi(int a1, int a2)
{
	return appl[a1].id < appl[a2].id;
}

int main(void)
{
#ifdef DEBUG
	freopen("1080.txt", "r", stdin);
#endif
	scanf("%d %d %d", &n, &m, &k);

	for(int idx=0; idx < m; ++idx)
		scanf("%d", quota+idx);
	
	for(int idx=0; idx < n; ++idx) {
		scanf("%d %d", &appl[idx].ge, &appl[idx].gi);
		for(int idx2=0; idx2 < k; ++idx2)
			scanf("%d", &appl[idx].scho[idx2]);

		appl[idx].id = idx;
		appl[idx].gt = appl[idx].ge + appl[idx].gi;
	}
	sort(appl, appl+n, cmp);

	//
	int idx, idx2;
	for(idx=0; idx < n; ++idx) {
		for(idx2=0; idx2 < k; ++idx2) {
			int school = appl[idx].scho[idx2];
			if( quota[school] > 0 || \
					(!admi[school].empty() &&
					 appl[idx] == appl[ admi[school].back() ]) ) {
				admi[school].push_back(idx);
				quota[school]--;
				break;
			}
		}
	}
	
	//
	for(idx=0; idx < m; ++idx) {
		if(admi[idx].size() > 0) {
			sort(admi[idx].begin(), admi[idx].end(), cmp_admi);

			for(idx2=0; idx2 < admi[idx].size()-1; ++idx2)
				printf("%d ", appl[ admi[idx][idx2] ].id);
			printf("%d\n", appl[ admi[idx][idx2] ].id);
		}
		else putchar('\n');
	}

	return 0;
}
