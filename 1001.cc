#include <iostream>

using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	string sum = to_string(a+b);
	int len = sum.length();
	for(int idx=3; idx < len; idx+=3) {
		sum.insert(len-idx, ",");
	}
	if(sum[0]=='-' && sum[1]==',')
		sum.erase(1, 1);
	cout << sum << endl;

	return 0;
}
