/*input
4
1
2
8
12

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2005;
const ll inf = 1e18+10;
int main()
{
	int T;cin>>T;
	vector<ll> a;
	ll last = 0;
	for(int i=1;;i++)
	{
		if(last<=(inf-2)/2)
		{
			last=2*last+2; 
			a.push_back(last);
		} 
		else break;
		// cout<<a.back()<<" ";
	}

	while(T--)
	{
		ll k;cin>>k;
		// cout<<"ok\n";
		string s = "";
		while(k>1)
		{
			for(int i=0;i<a.size();i++)
			{
				if(i==a.size()-1 || (a[i]<=k && a[i+1]>k))
				{
					s+='1';
					for(int j=0;j<i;j++) s+='0';
					k-=a[i];
					// cout<<k<<" "<<a[i]<<" "<<i<<"\n";
					break;
				}
			}
		}


		if(k==0)
		{
			cout<<s.size()<<"\n";
			for(int i=0;i<s.size();i++) cout<<s[i]<<" ";
			cout<<"\n";
		} 
		else cout<<"-1\n";


	}
	return 0;
}
