#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string &s1, const string &s2)
{
	return s1+s2 < s2+s1;
}

int main(void)
{
#ifdef DEBUG
	freopen("1038.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<string> vs;
	string num;
	while(n--) {
		cin >> num;
		vs.push_back(num);
	}
	sort(vs.begin(), vs.end(), cmp);

	//
	string res;
	for(auto vsm : vs)
		res += vsm;
	res.erase(0, res.find_first_not_of('0'));
	if(res.empty())
		cout << 0 << endl;
	else
		cout << res << endl;

	return 0;
}
