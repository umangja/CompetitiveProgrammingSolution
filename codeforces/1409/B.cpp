/*input

*/
#include<bits/stdc++.h>
using namespace std;

long long int fun(int a,int b,int x,int y,int n)
{
	int d = min(a-x,n);
	n-=d;
	a-=d;

	// cout<<a<<"\n";	

	d=min(b-y,n);
	n-=d;
	b-=d;

	return (long long int)a*(long long int)b;
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		int a,b,x,y,n;
		cin>>a>>b>>x>>y>>n;
		
		if(a>b || (a==b && x>y))
		{
			swap(a,b);
			swap(x,y);
		}

		long long int ans = fun(a,b,x,y,n);

		swap(a,b);
		swap(x,y);

		ans=min(ans,fun(a,b,x,y,n));
	
		cout<<ans<<"\n";
	}
	return 0;
}
