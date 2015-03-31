#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
#ifdef DEBUG
	//freopen("1069.txt", "r", stdin);
#endif
	char num[5];
	int big, small, res;
	scanf("%d", &res);
	do {
		sprintf(num, "%04d", res);
		sort(num, num+4);
		small = num[0]*1000 + num[1]*100 + num[2]*10 + num[3] - '0'*1111;
		sort(num, num+4, greater<char>());
		big = num[0]*1000 + num[1]*100 + num[2]*10 + num[3] - '0'*1111;
		res = big - small;
		printf("%04d - %04d = %04d\n", big, small, res);
	}while(res!=6174 && res!=0);

	return 0;
}
