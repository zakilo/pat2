#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Record {
	char id[16];
	int ih, im, is;
	int oh, om, os;
};

struct cmp_in  {
	bool operator() (const Record &res1, const Record &res2)
	{
		if(res1.ih != res2.ih)
			return res1.ih > res2.ih;
		else if(res1.im != res2.im)
			return res1.im > res2.im;
		else
			return res1.is > res2.is;
	}
};

struct cmp_out{
	bool operator() (const Record &res1, const Record &res2)
	{
		if(res1.oh != res2.oh)
			return res1.oh < res2.oh;
		else if(res1.om != res2.om)
			return res1.om < res2.om;
		else
			return res1.os < res2.os;
	}
};

int main(void)
{
#ifdef DEBUG
	freopen("1006.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);

	priority_queue<Record, vector<Record>, cmp_in> pq_in;
	priority_queue<Record, vector<Record>, cmp_out> pq_out;
	for(int idx=0; idx < n; ++idx) {
		Record rec;
		scanf("%s %d:%d:%d %d:%d:%d", rec.id, &rec.ih, &rec.im,\
				&rec.is, &rec.oh, &rec.om, &rec.os);
		pq_in.push(rec);
		pq_out.push(rec);
	}
	printf("%s %s\n", pq_in.top().id, pq_out.top().id);

	return 0;
}
