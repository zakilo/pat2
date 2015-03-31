#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

char str[82];

int main(void)
{
#ifdef DEBUG
	freopen("1031.txt", "r", stdin);
#endif
	scanf("%s", str);
	int len = strlen(str);
	int sideLen = (len+2)/3-1;	// without the one on the bottom
	int bottLen = len - (sideLen+1)*2;	// without the two on the two ends
	char spaces[30];
	memset(spaces, ' ', bottLen);
	spaces[bottLen] = 0;

	int i=0, j=len-1;
	for(; i<sideLen; ++i, --j)
		printf("%c%s%c\n", str[i], spaces, str[j]);
	str[j+1] = 0;
	printf("%s\n", str+i);

	return 0;
}
