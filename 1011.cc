#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main(void)
{
#ifdef DEBUG
	freopen("1011.txt", "r", stdin);
#endif
	float w, t, l, sum=1;
	int games = 3;
	while(games--) {
		scanf("%f%f%f", &w, &t, &l);
		if(w >= t && w >= l) {
			sum *= w;
			cout << "W ";
		}
		else if(t >= w && t >= l) {
			sum *= t;
			cout << "T ";
		}
		else {
			sum *= l;
			cout << "L ";
		}
	}
	printf("%.2f\n", (sum*0.65-1)*2);

	return 0;
}
