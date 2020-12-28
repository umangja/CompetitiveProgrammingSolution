/*input
5
()
(?)
(??)
??()
)?(?


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
		// int L = 0,R=n-1;
		// while(L<n && s[L]!='(') L++; 
		// while(R>=0 && s[R]!=')') R--;

		if(n%2==1 || s[0]==')' || s[n-1]=='(') cout<<"NO\n";
		else cout<<"Yes\n";
	}
	return 0;
}
