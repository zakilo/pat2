#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>

using namespace std;

struct User {
	char name[12], pw[12];
};
vector<User> users;

int main(void)
{
#ifdef DEBUG
	freopen("1035.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	bool flag = false;	// not modified
	int nn = n;
	while(nn--) {
		flag = false;
		User us;
		scanf("%s%s", us.name, us.pw);
		for(int idx=0; us.pw[idx] != 0; ++idx) {
			switch(us.pw[idx]) {
				case '1': us.pw[idx] = '@'; flag = true; break;
				case '0': us.pw[idx] = '%'; flag = true; break;
				case 'l': us.pw[idx] = 'L'; flag = true; break;
				case 'O': us.pw[idx] = 'o'; flag = true; break;
			}
		}
		if(flag)
			users.push_back(us);
	}
	if(0 == users.size()) {
		if(n == 1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n", n);
	}
	else {
		printf("%d\n", users.size());
		for(auto um : users)
			printf("%s %s\n", um.name, um.pw);
	}

	return 0;
}
