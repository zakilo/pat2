#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cstring>

using namespace std;

char msg[1050000];

bool is_al_num(char &ch)
{
	static int A_a = 'a'-'A';
	if('0'<=ch && ch<='9')
		return true;
	else if('a'<=ch && ch<='z')
		return true;
	else if('A'<=ch && ch<='Z') {
		ch += A_a;
		return true;
	}
	else
		return false;
}

int main(void)
{
#ifdef DEBUG
	freopen("1071.txt", "r", stdin);
#endif
	fgets(msg, 1050000, stdin);
	unordered_map<string, int> wc;	// I have try unordered_multiset with count() function, but got time out!!
	int maxc=0, tmpc;
	char *maxs;
	int front=0, rear=0;
	while(true) {
		while( !is_al_num(msg[front]) && msg[front] != 0 )
			++front;
		if(msg[front] == 0)
			break;
		rear = front;
		while( is_al_num(msg[rear]) )
			++rear;
		msg[rear] = 0;
		//
		string tmps(msg+front);
		if(wc.find(tmps) != wc.end())
			++wc[tmps];
		else
			wc[tmps] = 1;
		if( (tmpc=wc[tmps]) > maxc || (tmpc==maxc && strcmp(tmps.c_str(), maxs)<0) ) {
			maxc = tmpc; maxs = msg+front;
		}
		//
		front = rear+1;
	}
	//
	printf("%s %d\n", maxs, maxc);

	return 0;
}
