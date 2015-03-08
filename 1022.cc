#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Book {
	string id, title, auth, pub, year;
	vector<string> kw;	// key words
};

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1022.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	int n;
	cin >> n;
	multimap<string, string> mm_title, mm_auth, mm_kw, mm_pub, mm_year;
	while(n--) {
		Book bk;
		cin >> bk.id;
		cin.ignore();
		getline(cin, bk.title);
		getline(cin, bk.auth);
		// read key words
		string kws;
		getline(cin, kws);
		istringstream iss(kws);
		while(iss >> kws) {
			bk.kw.push_back(kws);
			// record each keyword
			mm_kw.insert(make_pair(kws, bk.id));
		}
		//
		getline(cin, bk.pub);
		cin >> bk.year;

		// record in multimap
		mm_title.insert(make_pair(bk.title, bk.id));
		mm_auth.insert(make_pair(bk.auth, bk.id));
		mm_pub.insert(make_pair(bk.pub, bk.id));
		mm_year.insert(make_pair(bk.year, bk.id));
	}

	// query
	int m;
	cin >> m;
	vector<string> res;
	while(m--) {
		int opt;
		string cont;
		cin >> opt;
		cin.ignore(2);
		getline(cin, cont);
		cout << opt << ": " << cont << "\n";
		pair<multimap<string, string>::iterator, multimap<string, string>::iterator > range;
		res.clear();
		switch(opt) {
			case 1:
				range = mm_title.equal_range(cont);
				for(auto it=range.first; it!=range.second; ++it)
					res.push_back(it->second);
				break;
			case 2:
				range = mm_auth.equal_range(cont);
				for(auto it=range.first; it!=range.second; ++it)
					res.push_back(it->second);
				break;
			case 3:
				range = mm_kw.equal_range(cont);
				for(auto it=range.first; it!=range.second; ++it)
					res.push_back(it->second);
				break;
			case 4:
				range = mm_pub.equal_range(cont);
				for(auto it=range.first; it!=range.second; ++it)
					res.push_back(it->second);
				break;
			case 5:
				range = mm_year.equal_range(cont);
				for(auto it=range.first; it!=range.second; ++it)
					res.push_back(it->second);
				break;
		}
		sort(res.begin(), res.end());
		if(res.size() == 0)
			cout << "Not Found\n";
		else for(auto resm : res)
			cout << resm << "\n";
	}

	return 0;
}
