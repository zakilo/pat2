#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Record {
	char plate[8];
	int time;
	bool inout;	// true if "in"
};
bool cmprec(const Record &r1, const Record &r2)
{
	int rc = strcmp(r1.plate, r2.plate);
	if(rc != 0)
		return rc < 0;
	else
		return r1.time < r2.time;
}

int n, k;
int mark[24*3600];

int main(void)
{
#ifdef DEBUG
	freopen("1095.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	vector<Record> vr;
	while(n--) {
		Record tr;
		int hh, mm, ss;
		char tp[5];
		scanf("%s%d:%d:%d%s", tr.plate, &hh, &mm, &ss, tp);
		tr.time = hh*3600 + mm*60 + ss;
		if(strcmp(tp, "in")==0) tr.inout = true;
		else tr.inout = false;
		vr.push_back(tr);
	}
	sort(vr.begin(), vr.end(), cmprec);
	//debug
	/*for(auto &vrm : vr) {
		printf("%s %02d:%02d:%02d %s\n",\
				vrm.plate, vrm.time/3600, vrm.time%3600/60, vrm.time%60,\
				vrm.inout ? "in" : "out");
	}*/
	// check cars
	int maxt = 0, stay=0;
	vector<char*> vps;
	for(auto it=vr.begin()+1, preit=vr.begin(); it != vr.end();) {
		if(strcmp(preit->plate, it->plate) != 0) {
			preit = it++;
			stay = 0;
		}
		else if(it->inout)
			preit = it++;
		else if(preit->inout && !it->inout) {
			++mark[preit->time];
			--mark[it->time];
			stay += it->time - preit->time;
			if(maxt < stay) {
				maxt = stay;
				vps.clear(); vps.push_back(it->plate);
			}
			else if(maxt == stay) {
				vps.push_back(it->plate);
			}
			// next
			preit = it++;
		}
		else
			++it;
	}
	//
	for(int idx=1; idx < 24*3600; ++idx)
		mark[idx] += mark[idx-1];
	// query
	while(k--) {
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		printf("%d\n", mark[hh*3600 + mm*60 +ss]);
	}
	for(auto vpsm: vps)
		printf("%s ", vpsm);
	printf("%02d:%02d:%02d\n", maxt/3600, maxt%3600/60, maxt%60);

	return 0;
}
