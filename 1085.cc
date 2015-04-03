#include <cstdio>
#include <algorithm>

using namespace std;

int n, p;
int seq[100010];

int main(void)
{
#ifdef DEBUG
	freopen("1085.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &p);
	for(int idx=0; idx < n; ++idx)
		scanf("%d", seq+idx);
	sort(seq, seq+n);

	int maxlen = 0;
	for(int idx=n-1; idx >= 0; --idx) {
		int mid, low = 0, high = idx;
		long long mult;
		while(low <= high) {
			mid = low + (high-low)/2;

			mult = seq[mid] * (long long)p;
			if(mult < (long long)seq[idx])
				low = mid + 1;
			else
				high = mid - 1;
		}

		if(idx - high > maxlen)
			maxlen = idx - high;
	}
	printf("%d\n", maxlen);

	return 0;
}
