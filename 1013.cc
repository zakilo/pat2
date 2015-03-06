#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct Way {
	int f, t;
};

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1013.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	int n, m, k;
	cin >> n >> m >> k;
	vector<Way> vw;
	while(m--) {
		Way wt;
		cin >> wt.f >> wt.t;
		vw.push_back(wt);
	}
	while(k--) {
		int us[1002];
		for(int idx=1; idx <= n; ++idx)
			us[idx] = idx;
		int ct;
		cin >> ct;

		for(auto vwm : vw) {
			if(vwm.f == ct || vwm.t == ct)
				continue;
			if(us[vwm.t] == vwm.t)
				us[vwm.t] = us[vwm.f];
			else
				us[vwm.f] = us[vwm.t];
		}

		int cnt = 0;
		for(int idx=1; idx <= n; ++idx)
			if(us[idx] == idx)
				++cnt;
		cout << cnt-2 << "\n";
	}

	return 0;
}
