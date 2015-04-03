#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1084.txt", "r", stdin);
#endif
	char str1[82], str2[82];
	scanf("%s\n%s", str1, str2);

	bool detected[256];
	memset(detected, 0, sizeof(detected));

	int idx1=0, idx2=0;
	while(str1[idx1] != 0) {
		if(str1[idx1] == str2[idx2])
			++idx1, ++idx2;
		else {
			int ch = toupper(str1[idx1]);
			if(!detected[ch]) {
				putchar(ch);
				detected[ch] = true;
			}
			++idx1;
		}
	}
	putchar('\n');

	return 0;
}
