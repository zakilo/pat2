#include <iostream>
#include <cstdio>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1014.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	queue<int> que[n];
	int timeque[n], timecus[k], timewind[n], time[k];
	memset(timeque, 0, sizeof(timeque));
	memset(timecus, 0, sizeof(timecus));

	int tf = k > n*m ? n*m : k;
	int idx = 0;
	for(; idx < tf; ++idx) {
		cin >> time[idx];
		que[idx%n].push(time[idx]);
		timeque[idx%n] += time[idx];
		timecus[idx] = timeque[idx%n];
	}
	for(int idx2=0; idx2 < n; ++idx2)
		timewind[idx2] = que[idx2].front(), que[idx2].pop();
	while(idx < k) {
		int min=timewind[0], wind=0;
		cin >> time[idx];
		for(int idx2=1; idx2 < n; ++idx2)
			if(timewind[idx2] < min)
				min = timewind[idx2], wind=idx2;
		que[wind].push(time[idx]);
		timewind[wind] += que[wind].front(), que[wind].pop();
		timeque[wind] += time[idx];
		timecus[idx] = timeque[wind];
		++idx;
	}

	const int deadline = (17-8)*60;
	while(q--) {
		int t;
		cin >> t;
		--t;
		if(timecus[t]-time[t] >= deadline)
			cout << "Sorry\n";
		else
			printf("%02d:%02d\n", timecus[t]/60+8, timecus[t]%60);
	}

	return 0;
}
