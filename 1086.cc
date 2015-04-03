#include <cstdio>

using namespace std;

void fun(int x)		// can you write down the code writen by the problem's author ?
{
	static bool first = true;
	char opti[5];
	int val;

	// left
	scanf("%s", opti);
	if(opti[1] == 'u') {	// push
		scanf("%d", &val);
		fun(val);
	}

	// right
	int res = scanf("%s", opti);
	if(res != EOF && opti[1] == 'u') {	// push
		scanf("%d", &val);
		fun(val);
	}

	if(first) {
		printf("%d", x);
		first = false;
	}
	else printf(" %d", x);
}

int main(void)
{
#ifdef DEBUG
	freopen("1086.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);

	char opti[5];
	int val;
	scanf("%s %d", opti, &val);
	fun(val);

	putchar('\n');

	return 0;
}
