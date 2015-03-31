#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1077.txt", "r", stdin);
#endif
	int n;
	char line[260], comm[260];

	scanf("%d%*c", &n);
	n--;
	fgets(comm, 260, stdin);
	reverse(comm, comm+strlen(comm)-1);
	while(n--) {
		fgets(line, 260, stdin);
		reverse(line, line+strlen(line)-1);

		register int idx = 0;
		for(; line[idx]!='\n' && comm[idx] !='\n' && line[idx] == comm[idx]; \
				++idx)
			;
		comm[idx] = 0;
	}
	
	int len = strlen(comm);
	if(len > 0) {
		reverse(comm, comm+len);
		printf("%s\n", comm);
	}
	else
		printf("nai\n");

	return 0;
}
