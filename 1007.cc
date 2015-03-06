#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int list[10001];

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1007.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	int n;
	cin >> n;
	int left=0, right=-1, max=-1;
	int sum = 0, tl=0, tr = -1;
	for(int idx=0; idx < n; ++idx) {
		cin >> list[idx];
		sum += list[idx];
		if(sum < 0) {
			sum = 0; tl = idx+1; tr = idx;
		}
		else
			++tr;

		if(sum > max && tl <= tr) {
			max = sum; left = tl; right = tr;
		}
	}
	if(max >= 0)
		printf("%d %d %d\n", max, list[left], list[right]);
	else
		printf("0 %d %d\n", list[0], list[n-1]);

	return 0;
}
