#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Testee {
	string num;
	int score;
	int ln, lr, fr;	// location number, local rank, final rank
};

bool operator< (const Testee &t1, const Testee &t2)
{
	if(t1.score != t2.score)
		return t1.score > t2.score;
	else
		return t1.num < t2.num;
}

int main(void)
{
#ifdef DEBUG
	freopen("1025.txt", "r", stdin);
#endif
	int n, k, cnt=0;
	cin >> n;
	vector<Testee> lr, fr;	// local ranklist, final ranklist
	for(int idx=1; idx <= n; ++idx) {
		cin >> k;
		cnt += k;
		lr.clear();
		Testee tt;
		while(k--) {
			tt.ln = idx;
			cin >> tt.num >> tt.score;
			lr.push_back(tt);
		}
		// check rank
		sort(lr.begin(), lr.end());
		lr.begin()->lr = 1;
		int rk = 2;
		for(auto itp=lr.begin(), it=lr.begin()+1; it != lr.end(); ++itp, ++it, ++rk) {
			if(it->score == itp->score)
				it->lr = itp->lr;
			else
				it->lr = rk;
		}
		fr.insert(fr.begin(), lr.begin(), lr.end());
	}
	// check final rank
	sort(fr.begin(), fr.end());
	fr.begin()->fr = 1;
	int rk = 2;
	for(auto itp=fr.begin(), it=fr.begin()+1; it != fr.end(); ++itp, ++it, ++rk) {
		if(it->score == itp->score)
			it->fr = itp->fr;
		else
			it->fr = rk;
	}
	
	// print
	cout << cnt << "\n";
	for(auto &frm : fr) {
		cout << frm.num << " " << frm.fr << " " << frm.ln << " " << frm.lr << "\n";
	}

	return 0;
}
