#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

vector<int> lt[100];

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1004.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	int n, m;
	cin >> n >> m;
	bool broot[n], bleaf[n];
	for(int idx=1; idx <= n; ++idx)
		broot[idx] = bleaf[idx] = true;
	for(int idx=1; idx <= m; ++idx) {
		int id, k, t;
		cin >> id >> k;
		bleaf[id] = false;
		while(k--) {
			cin >> t;
			lt[id].push_back(t);
			broot[t] = false;
		}
	}

	// find root
	queue<int> qi;
	for(int idx=1; idx <= n; ++idx)
		if(broot[idx]) {
			qi.push(idx);
			break;
		}

	// level traverse
	int cnt, leaf_cnt;
	bool bfirst = true;
	while(!qi.empty()) {
		cnt = qi.size();
		leaf_cnt = 0;
		while(cnt--) {
			int par = qi.front();
			qi.pop();
			if(bleaf[par]) ++leaf_cnt;
			for(int chd : lt[par]) {
				qi.push(chd);
			}
		}
		if(bfirst) {
			cout << leaf_cnt;
			bfirst = false;
		}
		else
			cout << " " << leaf_cnt;
	}

	return 0;
}
