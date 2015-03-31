#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

char str[100005];
int np[100005], nt[100005];		// number of 'P's and 'T's at each position

int main(void)
{
#ifdef DEBUG
	freopen("1093.txt", "r", stdin);
#endif
	scanf("%s", str);
	// init
	int idx;
	if(str[0] == 'P') np[0] = 1;
	else np[0] = 0;
	for(idx = 1; str[idx] != 0; ++idx) {
		if(str[idx] == 'P')	np[idx] = np[idx-1]+1;
		else np[idx] = np[idx-1];
	}
	--idx;
	if(str[idx] == 'T') nt[idx] = 1;
	else nt[idx] = 0;
	for(; idx >=0; --idx) {
		if(str[idx] == 'T')	nt[idx] = nt[idx+1]+1;
		else nt[idx] = nt[idx+1];
	}
	// cal
	long long sum = 0;
	for(idx=0; str[idx]!=0; ++idx)
		if(str[idx] == 'A')
			sum += np[idx] * nt[idx];
	printf("%lld\n", sum%1000000007);

	return 0;
}
