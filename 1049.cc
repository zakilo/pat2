#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

long long numOf1s(const string &num);

int main(void)
{
#ifdef DEBUG
	freopen("1049.txt", "r", stdin);
#endif
	string num;
	cin >> num;
	cout << numOf1s(num) << endl;

	return 0;
}

long long pow10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

long long numOf1s(const string &num)
{
	if(num.length() == 1) {
		if(num == "0") return 0L;
		else return 1L;
	}
	//
	long long first=0, middle=0, last=0;
	if(num[0] == '1')
		first = stoll(num.substr(1)) + 1;
	else if(num[0] > '1')
		first = pow10[num.length()-1];
	else	// maybe '0'
		first = 0;
	middle = (num[0]-'0') * (num.length()-1) * pow10[num.length()-2];
	last = numOf1s(num.substr(1) );

	return first + middle + last;
}
