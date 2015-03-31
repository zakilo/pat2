#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1058.txt", "r", stdin);
#endif
	int ag, as, ak, bg, bs, bk;
	scanf("%d.%d.%d %d.%d.%d",\
			&ag, &as, &ak, &bg, &bs, &bk);
	int sk = ak + bk;
	int carry = sk/29;
	sk %= 29;
	int ss = as + bs + carry;
	carry = ss / 17;
	ss %= 17;
	int sg = ag + bg + carry;

	printf("%d.%d.%d\n", sg, ss, sk);

	return 0;
}
