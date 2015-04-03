#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Stud {
	char name[11], id[11];
	short grade;
	bool operator< (const Stud &s) const {
		return this->grade > s.grade;	// here may be a little weird, haha~
	}
};

vector<Stud> vstud;

int main(void)
{
#ifdef DEBUG
	freopen("1083.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);

	Stud st;
	while(n--) {
		scanf("%s %s %hd", st.name, st.id, &st.grade);
		vstud.push_back(st);
	}
	sort(vstud.begin(), vstud.end());

	short g1, g2;
	scanf("%hd %hd", &g1, &g2);
	Stud s1 = {"", "", g1}, s2 = {"", "", g2};

	auto it1 = upper_bound(vstud.begin(), vstud.end(), s1),\
		 it2 = lower_bound(vstud.begin(), vstud.end(), s2);
	if(it1 <= it2)
		printf("NONE\n");
	else {
		while(it2 != it1) {
			printf("%s %s\n", it2->name, it2->id);
			++it2;
		}
	}

	return 0;
}
