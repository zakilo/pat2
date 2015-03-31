#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

bool mark[256];

int main(void)
{
#ifdef DEBUG
	freopen("1050.txt", "r", stdin);
#endif
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for(auto &ch : s2)
		mark[ch] = true;
	for(auto &ch : s1) {
		if(!mark[ch])
			putchar(ch);
	}
	cout << endl;

	return 0;
}
