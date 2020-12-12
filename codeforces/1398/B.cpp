/*input
5
01111001
0000
111111
101010101
011011110111

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		string s;cin>>s;
		int n = (int)s.size();
		int ans = 0;
		vector<int> a;
		for(int i=0;i<n;i++)
		{
			int j=i+1;
			while(j<n && s[j]==s[i]) j++;
			if(s[i]=='1') a.push_back(j-i);
			i=j-1;
		}

		sort(a.begin(), a.end(),greater<int> ());
		for(int i=0;i<a.size();i+=2) ans+=a[i];
		cout<<ans<<"\n";

	}
	return 0;
}
