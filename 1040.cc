#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

char str[1002];

int main(void)
{
#ifdef DEBUG
	freopen("1040.txt", "r", stdin);
#endif
	fgets(str, 1002, stdin);
	int len = strlen(str)-1;
	str[len] = 0;	// '\n'
	int idxl, idxr, range, maxr=1;
	for(int idx=1; str[idx] != 0; ++idx) {
		// maybe the range is an odd
		idxl=idx-1; idxr=idx+1;
		range = 0;
		while(idxl>=0 && idxr < len && str[idxl] == str[idxr]) {
			++range; --idxl; ++idxr;
		}
		range = range*2 + 1;
		if(range > maxr) maxr = range;

		// maybe the range is an even
		idxl=idx-1; idxr=idx;
		range = 0;
		while(idxl>=0 && idxr < len && str[idxl] == str[idxr]) {
			++range; --idxl; ++idxr;
		}
		range *= 2;
		if(range > maxr) maxr = range;
	}
	printf("%d\n", maxr);

	return 0;
}
