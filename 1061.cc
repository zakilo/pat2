#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

const char *daystr[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(void)
{
#ifdef DEBUG
	freopen("1061.txt", "r", stdin);
#endif
	char str[4][66];
	scanf("%s%s%s%s", str[0], str[1], str[2], str[3]);
	// day
	int idx = 0;
	while( !(str[0][idx]==str[1][idx] && str[0][idx]>='A' && str[0][idx]<='G') )
		++idx;
	int day = str[0][idx] - 'A';
	// hour
	++idx;
	while( !(str[0][idx]==str[1][idx] && \
				((str[0][idx]>='0' && str[0][idx]<='9') ||
				(str[0][idx]>='A' && str[0][idx]<='N')) ) )
		++idx;
	int hour = 0;
	if('0' <= str[0][idx] && str[0][idx] <= '9')
		hour = str[0][idx] - '0';
	else
		hour = str[0][idx] - 'A'+10;
	// minute
	idx = 0;
	while( !(str[2][idx] == str[3][idx] && \
			(( str[2][idx] >= 'A' && str[2][idx] <= 'Z' ) || \
			( str[2][idx] >= 'a' && str[2][idx] <= 'z' ) )
			)) ++idx;
	//
	printf("%s %02d:%02d\n", daystr[day], hour, idx);

	return 0;
}
