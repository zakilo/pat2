#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

char str[1003], need[1003];
int mark[256];

int main(void)
{
#ifdef DEBUG
	freopen("1092.txt", "r", stdin);
#endif
	scanf("%s%s", str, need);
	int idx;
	bool flag = true;	// enough beads
	for(idx=0; str[idx] != 0; ++idx)
		++mark[str[idx]];
	for(idx=0; need[idx] != 0; ++idx) {
		--mark[need[idx] ];
		if(mark[need[idx] ] < 0)
			flag = false;
	}

	// cal
	int cnt = 0;
	if(flag)
		for(idx=0; idx < 256; ++idx)
			cnt += mark[idx];
	else
		for(idx=0; idx < 256; ++idx)
			if(mark[idx] < 0)
				cnt -= mark[idx];
	
	if(flag)
		printf("Yes %d\n", cnt);
	else
		printf("No %d\n", cnt);

	return 0;
}
