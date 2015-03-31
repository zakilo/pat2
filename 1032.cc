#include <iostream>
#include <cstdio>
#include <fstream>
#include <stack>

using namespace std;

int node[100001];

int main(void)
{
#ifdef DEBUG
	freopen("1032.txt", "r", stdin);
#endif
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	int addr, next;
	for(int idx=0; idx < n; ++idx) {
		scanf("%d%*s%d", &addr, &next);
		node[addr] = next;
	}
	//
	int ps1=s1, ps2=s2;
	stack<int> ss1, ss2;
	while(ps1 != -1) {
		ss1.push(ps1); ps1=node[ps1];
	}
	while(ps2 != -1) {
		ss2.push(ps2); ps2=node[ps2];
	}
	// can be optimize: mark visited node in while1,
	// when while2 visit a visited node, we know this is the one
	int com = -1;
	while(!ss1.empty() && !ss2.empty() && ss1.top() == ss2.top()) {
		com = ss1.top();
		ss1.pop(); ss2.pop();
	}
	if(com == -1)
		printf("-1\n");
	else
		printf("%.5d\n", com);

	return 0;
}
