#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1027.txt", "r", stdin);
#endif
	cout << "#";
	int n;
	char const *num = "0123456789ABC";
	while(cin >> n) {
		cout << num[n/13] << num[n%13];
	}

	return 0;
}
