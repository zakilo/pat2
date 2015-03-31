#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAX	30100
char nota[MAX];

int main(void)
{
#ifdef DEBUG
	freopen("1073.txt", "r", stdin);
#endif
	memset(nota, '0', sizeof(nota));

	char *pstr = nota+10010;
	scanf("%s", pstr);

	bool flag = (pstr[0]=='+') ? true : false;	// sign
	pstr[0] = '0';

	int idx = 2;
	while(pstr[idx] != 'E') ++idx;
	pstr[idx++] = '0';

	bool flag2 = (pstr[idx]=='+') ? true : false;	// exponent's sign
	int exp = atoi(pstr+idx+1);
	// change chars after 'E' to '0'
	int idx2 = idx - 1;
	while(pstr[idx] != 0)
		pstr[idx++] = '0';
	pstr[idx] = '0';

	// '.' is at pstr+2, end of pstr is at pstr+idx2.
	if(!flag2 && exp >0) {
		pstr[2] = pstr[idx2] = 0;
		if(flag)
			printf("0.%s%s\n", pstr+2-exp, pstr+3);
		else
			printf("-0.%s%s\n", pstr+2-exp, pstr+3);
	} else {	// move '.'
		int idx3;
		for(idx3 = 2; exp--; ++idx3)
			pstr[idx3] = pstr[idx3+1];
		if(idx3 >= idx2-1)
			pstr[idx3] = 0;
		else {
			pstr[idx3] = '.';
			pstr[idx2] = 0;
		}

		if(flag)
			printf("%s\n", pstr+1);
		else
			printf("-%s\n", pstr+1);
	}

	return 0;
}
