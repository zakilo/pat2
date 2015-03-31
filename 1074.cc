#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int head, n, k;
struct Node {
	int addr, data, next;
};

unordered_map<int, Node> umnd;

int main(void)
{
#ifdef DEBUG
	freopen("1074.txt", "r", stdin);
#endif
	scanf("%d %d %d", &head, &n, &k);

	Node nd;
	while(n--) {
		scanf("%d %d %d", &nd.addr, &nd.data, &nd.next);
		umnd.insert(make_pair(nd.addr, nd));
	}

	vector<int> ndlist;
	int ptr = head;
	while(ptr != -1) {
		ndlist.push_back(ptr);
		ptr = umnd[ptr].next;
	}

	ptr = 0;
	while(ndlist.size() - ptr >= k) {
		for(int idx=0; idx < k/2; ++idx)
			swap(ndlist[ptr+idx], ndlist[ptr+k-idx-1]);
		ptr += k;
	}
	//
	printf("%05d %d", umnd[ ndlist[0] ].addr, umnd[ ndlist[0] ].data);
	for(int idx=1; idx < ndlist.size(); ++idx)
		printf(" %05d\n%05d %d", umnd[ ndlist[idx] ].addr, umnd[ ndlist[idx] ].addr, umnd[ ndlist[idx] ].data);
	printf(" -1\n");
	

	return 0;
}
