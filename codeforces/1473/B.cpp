/*input
3
baba
ba
aa
aaa
aba
ab

*/
#include<bits/stdc++.h>
using namespace std;

string fun(string s)
{
	int n = s.size();
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			string temp = "";
			for(int j=0;j<i;j++) temp+=s[j];
			string ans = "";
			int pos=1;
			for(int j=i;j<n && pos==1;j++)
			{
				ans+=s[j];
				if((j+1)%i==0)
				{
					if(ans!=temp) pos=0;
					else ans = "";
				}
			}
			if(pos) return temp;
		}
	}

	return s;
}

int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		string s,r;cin>>s>>r;

		int n = (int)s.size();
		int m = (int)r.size();

		string ans1 = fun(s);
		string ans2 = fun(r);

		if(ans1==ans2)
		{
			int k = (int)ans1.size();
			n = n/k;
			m = m/k;

			int lcm = (n*m)/__gcd(n,m);
			for(int i=1;i<=lcm;i++) cout<<ans1;
			cout<<"\n";
		}
		else cout<<"-1\n";


	}
	return 0;
}
