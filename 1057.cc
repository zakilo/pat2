#include <iostream>
#include <cstdio>
#include <fstream>
#include <set>
#include <stack>
#include <cassert>

using namespace std;

stack<int> sk;
multiset<int> mslow, msup;

void adjust()
{
	if(mslow.size()  > msup.size()+1) {
		auto itlow = mslow.end(); --itlow;
		msup.insert(*itlow);
		mslow.erase(itlow);
	}
	else if(mslow.size() < msup.size()) {
		mslow.insert( *msup.begin() );
		msup.erase( msup.begin() );
	}
	else {
		if( !mslow.empty() && !msup.empty() ) {
			auto itlow = mslow.end(); --itlow;
			int minup= *msup.begin(), maxlow = *itlow;
			if( minup < maxlow) {
				mslow.erase(itlow);
				mslow.insert(minup);
				msup.erase( msup.begin() );
				msup.insert(maxlow);
			}
		}
	}
}

void update_push(int val)
{
	mslow.insert(val);
	adjust();
}

void update_pop(int val)
{
	auto itlow = mslow.find(val);
	if(itlow != mslow.end() )
		mslow.erase(itlow);
	else {
		auto itup  = msup.find(val);
		msup.erase(itup);
	}
	adjust();
}

int main(void)
{
#ifdef DEBUG
	freopen("1057.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	char opti[20];
	int val;
	while(n--) {
		scanf("%s", opti);
		switch(opti[1]) {
			case 'u': scanf("%d", &val); sk.push(val);
					  update_push(val);
					  break;
			case 'o': if(sk.empty()) printf("Invalid\n");
					  else {printf("%d\n", sk.top()); update_pop(sk.top()); sk.pop();}
					  break;
			case 'e': if(mslow.empty()) printf("Invalid\n");
					  else { auto it=mslow.end(); --it; printf("%d\n", *it);}
					  break;
		}
	}

	return 0;
}
