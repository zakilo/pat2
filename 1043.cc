#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int n;
int num[1001], postod[1001];

bool checkbst(int left, int right)
{
	static int pos = 0;
	int root = num[left];
	if(left > right) return true;
	int idx = left+1;
	while(idx <= right && num[idx] < root) ++idx;
	int idxr = idx--;
	while(idxr <= right && num[idxr] >= root) ++idxr;

	if(idxr <= right) return false;
	else {
		if(checkbst(left+1, idx) && checkbst(idx+1, right) ) {
			postod[pos++] = root; return true;
		}
		else
			return false;
	}
}
bool checkbst_mirr(int left, int right)
{
	static int pos = 0;
	int root = num[left];
	if(left > right) return true;
	int idx = left+1;
	while(idx <= right && num[idx] >= root) ++idx;
	int idxr = idx--;
	while(idxr <= right && num[idxr] < root) ++idxr;

	if(idxr <= right) return false;
	else {
		if( checkbst_mirr(left+1, idx) && checkbst_mirr(idx+1, right) ) {
			postod[pos++] = root; return true;
		}
		else
			return false;
	}
}

int main(void)
{
#ifdef DEBUG
	freopen("1043.txt", "r", stdin);
#endif
	scanf("%d", &n);
	int idx = 0;
	for(idx=0; idx < n; ++idx)
		scanf("%d", &num[idx]);

	if( checkbst(0, idx-1) || checkbst_mirr(0, idx-1) ) {
		printf("YES\n");
		for(idx=0; idx < n-1; ++idx)
			printf("%d ", postod[idx]);
		printf("%d\n", postod[idx]);
	}
	else
		printf("NO\n");

	return 0;
}
