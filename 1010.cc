#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <unordered_map>

using namespace std;

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1010.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	char num1[12], num2[12], flag;
	int rad;
	unsigned long long sum1=0, sum2=0;
	unsigned long long rt;
	cin >> num1 >> num2 >> flag >> rad;

	if(strcmp(num1, num2)==0) { // a bug of PAT1010 here
		printf("%d\n", rad);
		return 0;
	}
	char *pn1 = num1, *pn2 = num2;
	if(flag == '2')
		pn1 = num2, pn2 = num1;
	// caculate pn1 by radix 10
	for(int idx=strlen(pn1)-1, rt=1; idx >= 0; --idx) {
		if(pn1[idx] >= '0' && pn1[idx] <= '9')
			sum1 += (pn1[idx]-'0') * rt;
		else
			sum1 += (pn1[idx]-'a' + 10) * rt;
		rt *= rad;
	}
	
	// find minimum possible radix of pn2
	unsigned long long minr = 1;
	for(int idx=0; pn2[idx] != 0; ++idx) {
		if(pn2[idx] >= '0' && pn2[idx] <= '9')
			rt = pn2[idx]-'0' + 1;
		else
			rt = pn2[idx]-'a' + 11;
		
		if(rt > minr) minr = rt;
	}
	// binary search test !!
	unsigned long long maxr = sum1+1, testr, minrad = 0;
	while(maxr >= minr) {
		testr = maxr/2 + minr/2;
		if((maxr%2) && (minr%2))
			++testr;

		// test
		rt=1, sum2=0; 
		for(int idx=strlen(pn2)-1; idx >= 0; --idx) {
			if(pn2[idx] >= '0' && pn2[idx] <= '9')
				sum2 += (pn2[idx]-'0') * rt;
			else
				sum2 += (pn2[idx]-'a' + 10) * rt;

			if(sum2 > sum1) break;	// IMPORTANT!!
			rt *= testr;
		}

		// check
		if(sum2 == sum1) {
			minrad = testr;
			maxr = testr - 1;
		}
		else if(sum2 > sum1)
			maxr = testr - 1;
		else
			minr = testr + 1;
	}
	if(minrad != 0)
		cout << minrad << endl;
	else
		cout << "Impossible\n";

	return 0;
}
