#include <cstdio>

using namespace std;

long long n;
long long nume[101], deno[101];

long long gcd(long long a, long long b)
{
	while(b > 0) {
		a %= b;
		a ^= b; b^=a; a^=b;
	}
	return a;
}

long long lcm_sz(long long sz[], long long len)
{
	long long lcm = sz[0];
	for(long long idx=1; idx < len; ++idx)
		lcm = lcm / gcd(lcm, sz[idx]) * sz[idx];
	return lcm;
}

int main(void)
{
#ifdef DEBUG
	freopen("1081.txt", "r", stdin);
#endif
	scanf("%lld", &n);
	
	for(long long idx=0; idx < n; ++idx)
		scanf("%lld/%lld", nume+idx, deno+idx);

	long long dlcm = lcm_sz(deno, n);

	long long nsum = 0;
	for(long long idx=0; idx < n; ++idx)
		nsum += nume[idx] * (dlcm / deno[idx]);
	
	long long ndcd = gcd(nsum, dlcm);
	nsum /= ndcd; dlcm /= ndcd;

	long long  inte = nsum / dlcm, frac = nsum % dlcm;
	if(nsum == 0)
		printf("0\n");
	else if(inte == 0)
		printf("%lld/%lld\n", frac, dlcm);
	else if(frac == 0)
		printf("%lld\n", inte);
	else
		printf("%lld %lld/%lld\n", inte, frac, dlcm);

	return 0;
}

