/*input
4
3
1 5 3
5
2 2 2 2 2
6
1 6 2 5 2 10
5
1 6 2 5 1

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int mn;
vector<ll> a;
vector<int> dp;
int n;
int check2(int i)
{
	if(i-1>=0 && i+1<n)
	{
		if( (a[i+1]>a[i] && a[i-1]>a[i]) || (a[i+1]<a[i] && a[i-1]<a[i]) ) return 1;
		else return 0;
	}
	return 0;
}

int check(int i)
{
	int ans = mn;
	ans-=dp[i]+dp[i+1]+dp[i-1];
	ans+=check2(i)+check2(i+1)+check2(i-1);
	return ans;
}


int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		cin>>n;	
		a.clear(); a.resize(n);
		dp.clear(); dp.assign(n,0);
		for(int i=0;i<n;i++) cin>>a[i];

		mn = 0;
		for(int i=1;i<n-1;i++)
		{
			if(a[i]>a[i+1] && a[i]>a[i-1]) dp[i]=1;
			else if(a[i]<a[i+1] && a[i]<a[i-1]) dp[i]=1;
			mn+=dp[i];
		}

		int ans = mn;

		for(int i=1;i<n-1;i++)
		{
			int temp = mn;
			int temp2 = a[i];

			if(i-1>=0){
				a[i] = a[i-1];
				temp=min(temp,check(i));				
			}

			if(i+1<n){
				a[i] = a[i+1];
				temp=min(temp,check(i));
			}
			a[i] = temp2;
			ans=min(ans,temp);
		}

		// change a[0] and a[n-1]

		cout<<ans<<"\n";


	}
	return 0;
}
