#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
vector<string> cour[2505];

int main(void)
{
#ifdef DEBUG
	freopen("1047.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	char name[5];
	int c, cn;
	string sna;
	while(n--) {
		scanf("%s%d", name, &c);
		sna = name;
		while(c--) {
			scanf("%d", &cn);
			cour[cn].push_back(sna);
		}
	}
	//
	for(int idx=1; idx <= k; ++idx) {
		sort(cour[idx].begin(), cour[idx].end());
		printf("%d %d\n", idx, (int)cour[idx].size());
		for(auto &cm : cour[idx])
			printf("%s\n", cm.data());
	}

	return 0;
}
