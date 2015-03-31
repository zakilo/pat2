#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int n;
int arr[100005];
bool flag[100005];

int main(void)
{
#ifdef DEBUG
	freopen("1067.txt", "r", stdin);
#endif
	int cnt = 0;
	scanf("%d", &n);
	for(int idx=0; idx < n; ++idx) {
		scanf("%d", arr+idx);
		if(arr[idx] == idx)
			flag[idx] = true;
		else
			cnt++;	// count how many numbers is not at its position
	}
	if(cnt == 0) {
		printf("0\n"); return 0;
	}
	//
	if(flag[0]) cnt += 2;
	int k;
	for(int idx=0; idx < n; ++idx) {
		k = arr[idx];
		if(!flag[k]) {
			++cnt;	// add the count of how many swap loops is there
			while(!flag[k]) {
				flag[k] = true; k = arr[k];
			}
		}
	}
	//
	printf("%d\n", cnt-2);//www.tuicool.com/articles/yaeYNb

	return 0;
}
