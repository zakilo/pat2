#include <iostream>
#include <cstdio>
#include <fstream>
#include <queue>

using namespace std;

int miceorder[1003];
int prog[1003], micerank[1003];
queue<int> mice;

int main(void)
{
#ifdef DEBUG
	freopen("1056.txt", "r", stdin);
#endif
	int p, g;
	scanf("%d %d", &p, &g);
	for(int idx=0; idx < p; ++idx)
		scanf("%d", prog+idx);
	for(int idx=0; idx < p; ++idx) {
		scanf("%d", &miceorder[idx]);
		mice.push(miceorder[idx]);
	}
	//
	int left = 0, r=0, cnt=0;
	while(mice.size() > 1) {
		left = mice.size(); r = (left-1)/g + 2; cnt=0;	// Attention !! The calculation of r
		int max = -1, pos = -1;
		for(int idx=0; idx<left; ++idx) {
			if(prog[ mice.front() ] > max) {
				max = prog[ mice.front() ]; pos = mice.front();
			}
			micerank[ mice.front() ] = r;
			mice.pop();
			if((++cnt)%g == 0 || cnt == left) {
				mice.push(pos); max = -1;
			}
		}
	}
	micerank[ mice.front() ] = 1;
	//
	for(int idx=0; idx<p-1; ++idx)
		printf("%d ", micerank[idx]);
	printf("%d\n", micerank[p-1]);
	

	return 0;
}
