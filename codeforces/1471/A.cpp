/*input
2
3 3
3 6 9
3 3
6 4 11




*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int TC = 1; 
	cin>>TC;
	while(TC--)
	{
		ll n,x;
		cin>>n>>x;
		
		vector<ll> a(n);
		ll sum = 0,mx = 0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			mx+=(a[i]+x-1)/x;
		} 

		cout<<(sum+x-1)/x<<" "<<mx<<"\n";



	}
	return 0;
}
