#include <iostream>
#include <fstream>

using namespace std;

const char* print_num(int num)
{
	switch(num) {
		case 0: return "zero";
		case 1: return "one";
		case 2: return "two";
		case 3: return "three";
		case 4: return "four";
		case 5: return "five";
		case 6: return "six";
		case 7: return "seven";
		case 8: return "eight";
		case 9: return "nine";
	}
}

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1005.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	char num[102], buf[20];
	cin >> num;

	int sum = 0;
	int idx=0;
	while(num[idx]!=0)
		sum += num[idx++];
	sum -= idx * '0';

	sprintf(buf, "%d", sum);
	cout << print_num(buf[0]-'0');
	idx = 1;
	while(buf[idx] != 0)
		cout << " " << print_num(buf[idx++]-'0');

	return 0;
}
