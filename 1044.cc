#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>

using namespace std;

int n, m;
int num[100005];
vector<pair<int, int> > vp;

int main(void)
{
#ifdef DEBUG
	freopen("1044.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for(int idx=1; idx <= n; ++idx)
		scanf("%d", num+idx);
	num[n+1] = 0;
	int idx1=1, idx2=1;
	int sum = num[1], max = 10e8;
	while(idx2 <= n) {
		if(sum == m) {
			if(max > m) {
				vp.clear(); max = m;
			}
			vp.emplace_back(idx1, idx2);
			sum -= num[idx1];
			++idx1; ++idx2;
			sum += num[idx2];
		}
		else if(sum > m) {
			if(sum < max) {
				vp.clear(); max = sum;
				vp.emplace_back(idx1, idx2);
			}
			else if(sum == max)
				vp.emplace_back(idx1, idx2);
			if(idx1 == idx2) {
				++idx1; ++idx2; sum = num[idx2];
			}
			else {
				sum -= num[idx1]; ++idx1;
			}
		}
		else {
			++idx2; sum += num[idx2];
		}
	}
	//
	for(auto &vpm : vp)
		printf("%d-%d\n", vpm.first, vpm.second);

	return 0;
}
