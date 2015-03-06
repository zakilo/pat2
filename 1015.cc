#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX	100001

bool prime[MAX];

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1015.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	for(int idx=2; idx < MAX; ++idx)
		prime[idx] = true;
	for(int idx=2; idx < MAX; ++idx) {
		while(!prime[idx] && idx < MAX) ++idx;
		for(int idx2=2; idx*idx2 < MAX; ++idx2)
			prime[idx*idx2] = false;
	}

	int n, d;
	char buf[40];
	while(cin >> n >> d) {
		if(prime[n]) {
			int idx = 0;
			while(n > 0) {
				buf[idx++] = "0123456789"[n%d];
				n /= d;
			}
			buf[idx]=0;
			if(prime[stoi(string(buf), nullptr, d)])
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		else
			cout << "No\n";
	}

	return 0;
}
