#include <cstdio>
#include <cstring>

using namespace std;

char *str1[] = {"", " Shi", " Bai", " Qian"};	// mind the front ' '
char *str2[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char *str3[] = {"", "Wan", "Yi"};

int main(void)
{
#ifdef DEBUG
	freopen("1082.txt", "r", stdin);
#endif
	char str[11];
	scanf("%s", str);

	int pos = strlen(str) - 1;
	int idx = 0;
	bool first = false;

	if(str[idx]=='-') {
		printf("Fu");
		++idx; --pos;
		first = true;
	}
	
	while(str[idx]=='0') ++idx, --pos;		// trim front '0's
	if(pos < 0) {
		printf("ling\n");
		return 0;
	}
	for(; pos >= 0; ++idx, --pos) {
		if(str[idx] != '0') {
			if(first)
				printf(" %s%s", str2[ str[idx]-'0' ], str1[pos%4]);	// #1
			else {
				first = true;
				printf("%s%s", str2[ str[idx]-'0' ], str1[pos%4]);		// #2
			}
		} else {	// deal with '0'
			if(str[idx+1] != 0 && str[idx+1] != '0')
				printf(" ling");
		}

		if(pos % 4 == 0 && pos != 0)
			printf(" %s", str3[pos/4]);	// the front ' ' will be print at line #1 or #2
	}
	printf("\n");

	return 0;
}
