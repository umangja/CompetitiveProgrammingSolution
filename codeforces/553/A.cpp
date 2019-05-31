#include<bits/stdc++.h>
using namespace std;

const long long int N = 1e3+5;
const long long int mod = 1000000007;
long long int comb[N][N];

void fun()
{
	for(long long int n=0;n<N;n++)
		for(long long int r=0;r<N;r++)
			comb[n][r]=0;
		
	comb[0][0]=1;
	for(long long int n=1;n<N;n++)
	{
		comb[n][0]=1;
		for(long long int r=1;r<=n;r++)
			comb[n][r]=(comb[n-1][r]+comb[n-1][r-1])%mod;
	}
	return ;
}

int main()
{
	fun();
	long long int k;cin>>k;
	long long int ans=1,total=0;
	for(long long int i=0;i<k;i++)
	{
		int x;cin>>x;
		ans=(ans*(comb[total+x-1][x-1]))%mod;
		total+=x;
	}

	cout<<ans;
	return 0;
}