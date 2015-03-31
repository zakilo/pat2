#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

unordered_map<string, int> weight;
unordered_map<string, string> gang;
unordered_map<string, string> gtoh;		// tree of a gang to its head
struct Info {
	string head;
	int num, wt;
};
unordered_map<string, Info> head;	// this's the top of every gang tree,
				// not the real head, with the number of gang members and
				// total weight

string find(string peop)
{
	if(gang.find(peop)==gang.end())
		return peop;
	else
		return gang[peop] = find(gang[peop]);
}

void merge(string left, string right)
{
	string tl = find(left), tr = find(right);
	if(tl != tr) {
		gang[tl] = tr;
	}
}

int main(void)
{
#ifdef DEBUG
	freopen("1034.txt", "r", stdin);
#endif
	int n, k;
	cin >> n >> k;
	string left, right;
	int time;
	while(n--) {
		cin >> left >> right >>time;
		if(weight.find(left) != weight.end())
			weight[left] += time;
		else weight[left] = time;
		if(weight.find(right) != weight.end())
			weight[right] += time;
		else weight[right] = time;
		merge(left, right);
	}
	// debug
	cout << "weight\n";
	for(auto wm : weight) {
		cout << wm.first << " " << wm.second << "\n";
	}
	cout << "gang\n";
	for(auto gm : gang) {
		cout << gm.first << " " << gm.second << "\n";
	}
	////debug
	// find heads
	int maxp = 0;
	for(auto gm : gang) {	// remind that the tops' info of each gang are not added
		string tmp = find(gm.first);
		if(head.find(tmp) == head.end()) {
			head[tmp].head = tmp;
			head[tmp].num = 1;
			head[tmp].wt = weight[tmp];
		}
		if(weight[head[tmp].head] < weight[gm.first])
			head[tmp].head = gm.first;

		++head[tmp].num;
		head[tmp].wt += weight[gm.first];
	}
	// print
	int cnt = 0;
	map<string, int> realhead;
	for(auto &hm : head) {
		hm.second.wt /= 2;
		if(hm.second.num > 2 && hm.second.wt > k) {
			++cnt;
			realhead.insert(make_pair(hm.second.head, hm.second.num));
		}
	}
	// debug
	cout << "head\n";
	for(auto &hm : head)
		cout << hm.first << " " << hm.second.head << " " << hm.second.wt << "\n";
	////debug
	cout << cnt << "\n";
	for(auto rhm : realhead)
		cout << rhm.first << " " << rhm.second << "\n";

	return 0;
}
