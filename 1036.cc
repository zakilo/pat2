#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

struct Stud {
	char name[12], gend, id[12];
	int sc;
};

int main(void)
{
#ifdef DEBUG
	freopen("1036.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	Stud maxf={"",'F',"",-1}, minm={"",'M',"",101};
	while(n--) {
		Stud st;
		scanf("%s %c %s %d", st.name, &st.gend, st.id, &st.sc);
		if(st.gend == 'F' && st.sc > maxf.sc)
			maxf = st;
		else if(st.gend == 'M' && st.sc < minm.sc)
			minm = st;
	}
	if(maxf.sc != -1 && minm.sc != 101)
		printf("%s %s\n%s %s\n%d\n",\
				maxf.name, maxf.id, minm.name, minm.id, maxf.sc-minm.sc);
	else if(maxf.sc != -1 && minm.sc == 101)
		printf("%s %s\nAbsent\nNA\n", maxf.name, maxf.id);
	else if(maxf.sc == -1 && minm.sc != 101)
		printf("Absent\n%s %s\nNA\n", minm.name, minm.id);

	return 0;
}
