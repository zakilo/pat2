// fuck this
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

int n;

int change(char str1[], int &num1)
{
	int i, j;
	str1[0] = '0';
	str1[1] = '.';
	int len1 = strlen(str1);

	for(i=2; i<len1; i++)	// find '.'
		if(str1[i] == '.')
			break;
	for(j=2; j<len1; j++)
		if(str1[j] >= '1' && str1[j] <= '9')
			break;
	if(i >= j)
		num1 = i-j;
	else
		num1 = i-j+1;

	for(i=2; j<len1; ++j)
		if(str1[j] != '.')
			str1[i++] = str1[j];
	if(i==2) {
		num1 = 0;
		for(; i<=n+1; i++)
			str1[i] = '0';
	}
	str1[i] = str1[2+n] = 0;

	return num1;
}

int main(void)
{
#ifdef DEBUG
	freopen("1060.txt", "r", stdin);
#endif
	int i, j;
	char str1[110], str2[100];
	int num1, num2;

	scanf("%d", &n);
	scanf("%s%s", str1+2, str2+2);

	change(str1, num1);
	change(str2, num2);

	if(num1==num2 && strcmp(str1, str2)==0)
		printf("YES %s*10^%d\n", str1, num1);
	else
		printf("NO %s*10^%d %s*10^%d\n", str1, num1, str2, num2);

	return 0;
}
