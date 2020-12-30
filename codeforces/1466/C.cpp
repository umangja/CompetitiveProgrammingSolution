/*input
7
babba
abaac
codeforces
zeroorez
abcdcba
bbbbbbb
a

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		string s;cin>>s;
		int n = (int)s.size();
		int ans=0;
		for(int i=1;i<n;i++)
		{
			int ch = 0;
			if(s[i]==s[i-1]) ch=1;
			if(i-2>=0 && s[i]==s[i-2]) ch=1;

			if(ch==1)
			{
				for(int j=0;j<26;j++)
				{
					int pos=1;
					if(s[i]-'a'==j) pos=0;
					if(i-1>=0 && s[i-1]-'a'==j) pos=0;
					if(i-2>=0 && s[i-2]-'a'==j) pos=0;
					if(i+1<n && s[i+1]-'a'==j) pos=0;
					if(i+2<n && s[i+2]-'a'==j) pos=0;
					if(pos==1)
					{
						ans++;
						s[i] = (char)('a'+j);
						// cout<<"i is "<<i<<" "<<s[i]<<"\n";
						break;
					}
				}
			}
		}

		cout<<ans<<"\n";


	}
	return 0;
}
