#include <iostream>
#include <cstdio>
#include <fstream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

#define SIZE	175760	// 26*26*26*10
set<int> sc[SIZE];

int namehash(char *s)
{
	return (s[0]-'A')*6760 + (s[1]-'A')*260 + (s[2]-'A')*10 + s[3]-'0';
}

int main(void)
{
#ifdef DEBUG
	freopen("1039.txt", "r", stdin);
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	int kn, kk;
	while(k--) {
		scanf("%d%d", &kn, &kk);
		char name[5];
		while(kk--) {
			scanf("%s", name);
			sc[ namehash(name) ].insert(kn);
		}
	}
	// query
	char name[5];
	while(n--) {
		scanf("%s", name);
		int ha = namehash(name);
		printf("%s %u", name, (unsigned)sc[ha].size());
		for(auto scsm : sc[ha])
			printf(" %d", scsm);
		printf("\n");
	}

	return 0;
}
