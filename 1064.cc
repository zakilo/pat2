#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> num;
int tree[1005];

void layer_scan(int root)
{
	static int pos=0;
	if(root >= n) return;
	layer_scan(root*2+1);
	tree[root] = num[pos++];
	layer_scan(root*2+2);
}

int main(void)
{
#ifdef DEBUG
	freopen("1064.txt", "r", stdin);
#endif
	scanf("%d", &n);
	int t, idx=n;
	while(idx--) {
		scanf("%d", &t); num.push_back(t);
	}
	sort(num.begin(), num.end());
	//
	layer_scan(0);
	//
	for(idx=0; idx<n-1; ++idx)
		printf("%d ", tree[idx]);
	printf("%d\n", tree[idx]);

	return 0;
}
