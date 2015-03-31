#include <iostream>
#include <cstdio>
#include <fstream>
#include <stack>

using namespace std;

int m, n, k;

int main(void)
{
#ifdef DEBUG
	freopen("1051.txt", "r", stdin);
#endif
	scanf("%d%d%d", &m, &n, &k);
	int cur = 0, idx, val;
	stack<int> sk;
	while(k--) {
		cur = 0; idx = n;
		while(!sk.empty()) sk.pop();
		while(idx--) {
			scanf("%d", &val);
			if(val > cur) {
				while(cur < val) {
					if(sk.size() == m) goto PRINT;
					sk.push(++cur);
				}
				sk.pop();
			}
			else if( sk.empty() || val != sk.top() )
				break;
			else if( val == sk.top() )
				sk.pop();
		}
PRINT:
		if(idx >= 0) {
			printf("NO\n");
			while(idx--) scanf("%d", &val);
		}
		else
			printf("YES\n");
	}

	return 0;
}
