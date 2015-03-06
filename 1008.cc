#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1008.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	int n;
	cin >> n;
	int start=0, sum=0;
	while(n--) {
		int t;
		cin >> t;
		if(t > start)
			sum += (t-start)*6 + 5;
		else
			sum += (start-t)*4 + 5;
		start = t;
	}
	cout << sum << endl;

	return 0;
}
