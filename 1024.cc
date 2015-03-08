#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1024.txt", "r", stdin);
#endif
	string num, rnum;
	int k, loop=0;
	cin >> num >> k;
	while(true) {
		rnum = num;
		reverse(rnum.begin(), rnum.end());
		if(num == rnum) {
			cout << num << "\n" << loop << endl;
			return 0;
		}
		if(loop==k) break;
		// addition
		int carry = 0;
		for(auto it=num.rbegin(), itr=rnum.rbegin(); it!=num.rend(); ++it, ++itr) {
			*it += *itr - '0' + carry;
			if(*it > '9') {
				carry = 1; *it -= 10;
			}
			else
				carry = 0;
		}
		if(carry) num.insert(num.begin(), '1');
		++loop;
	}
	
	cout << num << "\n" << k << endl;
	return 0;
}
