#include <iostream>
#include <cstdio>
#include <fstream>
#include <set>
#include <stack>

using namespace std;

stack<int> sk;
multiset<int> mslow, msup;

void update_push(int val)
{
	int maxlow, minup;
	auto itlow = mslow.end();

	if( mslow.size() == msup.size() ) {
		if( mslow.empty() )
			mslow.insert(val);
		else {
			maxlow = *(--itlow);
			if(val <= maxlow)
				mslow.insert(val);
			else {
				minup  = *msup.begin();
				if( val <= minup )
					mslow.insert(val);
				else {
					mslow.insert(minup);
					msup.erase(minup);
					msup.insert(val);
				}
			}
		}
	}
	else {
		if( msup.empty() ) {
			if( val < *mslow.begin() ) {// may be msup has a '3' and the val is '2'
				msup.insert( *mslow.begin() );
				mslow.erase( mslow.begin() );
				mslow.insert(val);
			}
			else
				msup.insert(val);
		}
		else {
			maxlow = *(--itlow);
			if( val >= maxlow )
				msup.insert(val);
			else {
				msup.insert(maxlow);
				mslow.erase(maxlow);
				mslow.insert(val);
			}
		}
	}
}

void update_pop(int val)
{
	auto itlow = mslow.find(val);
	auto itup  = msup.find(val);
	if(itlow != mslow.end() ) {
		if(mslow.size() > msup.size() )
			mslow.erase( itlow );
		else if( itup != msup.end() )
			msup.erase(itup);
		else {
			mslow.erase(itlow);
			mslow.insert(*msup.begin() );
			msup.erase(msup.begin() );
		}
	}
	else {
		msup.erase(itup);
		if( mslow.size() > msup.size()+1 ) {
			itlow = mslow.end(); --itlow;
			msup.insert(*itlow);
			mslow.erase(itlow);
		}
	}
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
