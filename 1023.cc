#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1023.txt", "r", stdin);
#endif
	char n[22];
	scanf("%s", n);
	
	bool mark1[255];
	for(int idx='0'; idx<='9'; ++idx)
		mark1[idx] = false;
	int len=0;
	for(; n[len]!=0; ++len)
		mark1[n[len]] = true;

	int carry = 0;
	for(int idx=len-1; idx >= 0; --idx) {
		if(n[idx] >= '5') {
			n[idx] = '0' + 2*(n[idx]-'5') + carry;
			carry = 1;
		}
		else {
			n[idx] = '0' + 2*(n[idx]-'0') + carry;
			carry = 0;
		}
	}

	bool mark2[255];
	for(int idx='0'; idx<='9'; ++idx)
		mark2[idx] = false;
	if(carry)
		n[len++] = '0'+carry;
	for(int idx=0; idx<len; ++idx)
		mark2[n[idx]] = true;

	int idx;
	for(idx='0'; idx<='9'; ++idx)
		if(mark1[idx] ^ mark2[idx])
			break;
	if(carry)
		n[--len] = 0;
	if(idx <= '9')
		printf("No\n");
	else
		printf("Yes\n");
	if(carry)
		printf("1");
	printf("%s", n);

	return 0;
}
