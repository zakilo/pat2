#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n;
double p, r;
bool flag[100010];	// retailer

double lvlscan(vector<int> vec[], int root)
{
	queue<int> que;
	que.push(root);

	double sum = 0, rr = 1;
	int t, len=1, tmp;
	while( !que.empty() ) {
		tmp = 0;

		while(len--) {
			t = que.front();
			que.pop();

			if(!flag[t])
				for(auto mem : vec[t]) {
					que.push(mem);
					++tmp;
				}
			else
				sum += p*rr*vec[t][0];
		}

		rr *= 1+r;
		len = tmp;
	}
	
	return sum;
}

int main(void)
{
#ifdef DEBUG
	freopen("1079.txt", "r", stdin);
#endif
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;

	vector<int> vec[n];
	int k, t;
	for(int idx=0; idx < n; ++idx) {
		scanf("%d", &k);
		if(k == 0) {	// retailer
			flag[idx] = true;
			k = 1;
		}
		while(k--) {
			scanf("%d", &t);
			vec[idx].push_back(t);
		}
	}

	printf("%.1f\n", lvlscan(vec, 0));

	return 0;
}
