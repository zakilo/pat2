#include <iostream>
#include <cstdio>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int addr, val, next;
};
bool cmp_val(const Node &n1, const Node &n2)
{
	return n1.val < n2.val;
}

unordered_map<int, Node> allnode;
vector<Node> vll;

int main(void)
{
#ifdef DEBUG
	freopen("1052.txt", "r", stdin);
#endif
	int n, head;
	scanf("%d%d", &n, &head);
	Node nd;
	while(n--) {
		scanf("%d%d%d", &nd.addr, &nd.val, &nd.next);
		allnode.insert( make_pair(nd.addr, nd) );
	}
	//
	if(head == -1) {
		printf("0 -1\n");
		return 0;
	}
	//
	int llp = head;
	while(llp != -1) {
		vll.push_back( allnode[llp] );
		llp = allnode[llp].next;
	}
	sort( vll.begin(), vll.end(), cmp_val );
	//
	auto it_ll = vll.begin();
	printf("%d %05d\n%05d %d ", static_cast<int>(vll.size()), it_ll->addr, it_ll->addr, it_ll->val);
	while( ++it_ll != vll.end() ) {
		printf("%05d\n%05d %d ", it_ll->addr, it_ll->addr, it_ll->val);
	}
	printf("-1\n");

	return 0;
}
