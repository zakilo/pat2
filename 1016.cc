#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int toll[25];
struct Rec {
	string name, onoff;
	int m, d, hh, mm;
};

bool operator< (const Rec &r1, const Rec &r2)
{
	if(r1.name != r2.name)
		return r1.name < r2.name;
	else if(r1.d != r2.d)
		return r1.d < r2.d;
	else if(r1.hh != r2.hh)
		return r1.hh < r2.hh;
	else
		return r1.mm < r2.mm;
}

int main(void)
{
#ifdef DEBUG
	ifstream ifs("1016.txt");
	cin.rdbuf(ifs.rdbuf());
#endif
	for(int idx=1; idx <= 24; ++idx) {
		cin >> toll[idx];
		toll[idx] *= 60;
		toll[idx] += toll[idx-1];
	}
	int n;
	vector<Rec> vr;
	cin >> n;
	while(n--) {
		Rec rec;
		char ch;
		cin >> rec.name >> rec.m >> ch >> rec.d >> ch >> rec.hh >> ch >> rec.mm >> rec.onoff;
		vr.push_back(rec);
	}
	sort(vr.begin(), vr.end());

	vector<Rec>::iterator it_vrpre = vr.begin(), it_vr = vr.begin()+1;
	double totalamount=0;
	for(; it_vr != vr.end(); ++it_vr) {
		if(it_vrpre->name != it_vr->name) {
			if(totalamount > 0.0001)
				printf("Total amount: $%.2lf\n", totalamount/100);
			totalamount = 0;
			it_vrpre = it_vr;
		}
		else if(it_vr->onoff == "on-line")
			it_vrpre = it_vr;
		else if(it_vrpre->onoff == "on-line" && it_vr->onoff == "off-line") {
			if(totalamount == 0)
				printf("%s %02d\n", it_vr->name.data(), it_vr->m);
			double ttoll = (it_vr->d - it_vrpre->d)*toll[24];
			int time = (it_vr->d - it_vrpre->d)*24*60;
			if(it_vr->hh < it_vrpre->hh || (it_vr->hh == it_vrpre->hh && it_vr->mm < it_vrpre->mm)) {
				int timehead = it_vr->hh*60 + it_vr->mm,\
					timetail = (24-it_vrpre->hh)*60 - it_vrpre->mm;
				double thead_vr = toll[it_vr->hh] + (toll[it_vr->hh+1]-toll[it_vr->hh])*it_vr->mm/60.0,\
					ttail_vrpre = (toll[24]-toll[it_vrpre->hh]) - (toll[it_vrpre->hh+1]-toll[it_vrpre->hh])*it_vrpre->mm/60.0;
				ttoll += thead_vr + ttail_vrpre - toll[24];
				time += timehead + timetail - 24*60;
			}
			else {
				time += (it_vr->hh - it_vrpre->hh)*60 + it_vr->mm - it_vrpre->mm;
				ttoll += (toll[it_vr->hh]-toll[it_vrpre->hh]) -\
						 (toll[it_vrpre->hh+1]-toll[it_vrpre->hh])*it_vrpre->mm/60.0 +\
						 (toll[it_vr->hh+1]-toll[it_vr->hh])*it_vr->mm/60.0;
			}
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", it_vrpre->d, it_vrpre->hh,\
					it_vrpre->mm, it_vr->d, it_vr->hh, it_vr->mm, time, ttoll/100);
			totalamount += ttoll;
			it_vrpre = it_vr;
		}
	}
	if(totalamount > 0.0001)
		printf("Total amount: $%.2lf\n", totalamount/100);

	return 0;
}
