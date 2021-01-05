/*input
6
a
!a
b
!c
d
!d


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int n;cin>>n;
		set<string> st;
		string ans = "satisfiable";
		for(int i=0;i<n;i++)
		{
			string s;cin>>s;
			if(s[0]=='!' && st.find(s.substr(1,(int)s.size()-1))!=st.end()) ans=s.substr(1,(int)s.size()-1);
			else if(s[0]!='!' && st.find("!"+s)!=st.end()) ans=s;
			st.insert(s);
		}	

		cout<<ans<<"\n";
	}
	return 0;
}
