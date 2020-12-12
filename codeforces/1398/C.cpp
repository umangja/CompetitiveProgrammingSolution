/*input
3
3
120
5
11011
6
600005


*/
#include<bits/stdc++.h>
using namespace std;
#define S second
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		string s;cin>>s;

		vector<int> pf(n);
		for(int i=0;i<n;i++) pf[i]+=(i-1>=0?pf[i-1]:0)+(s[i]-'0');

		map<int,long long int> m;
		for(int i=0;i<n;i++) m[pf[i]-i-1]++;

		m[0]++;

		long long int ans=0;
		for(auto it = m.begin();it!=m.end();it++)
		{
			long long int temp = (it->S*(it->S-1))/2;
			ans+=temp;
		}

		cout<<ans<<"\n";


	}
	return 0;
}
