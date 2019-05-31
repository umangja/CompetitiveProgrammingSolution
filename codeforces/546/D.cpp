#include<bits/stdc++.h>
using namespace std;

const long long int N = 5e6+6;
vector< long long int > lpf(N,0),npf(N);

void fun()
{
	for(long long int i=2;i<=N;i++)
	{
		if(lpf[i]==0)
		{
			lpf[i]=i;
			for(long long j=i*i;j<=N;j+=i)
				lpf[j]=i;
		}
	}

	npf[1]=0;
	for(long long int i=2;i<=N;i++)
	{
		npf[i]=npf[i/lpf[i]]+1;
	}

	for(long long int i=2;i<=N;i++)
		npf[i]+=npf[i-1];
}
void solve()
{
	long long int a,b;
	scanf("%lld %lld",&a,&b);
	cout<<npf[a]-npf[b]<<"\n";
	return ;
}

int main()
{
	fun();
	// cout<<npf[3]<<" "<<npf[6];
	long long int t;cin>>t;
	while(t--)
		solve();
	return 0;
}