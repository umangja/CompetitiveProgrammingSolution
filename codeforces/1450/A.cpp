/*input
3
11
antontrygub
15
bestcoordinator
19
trywatchinggurabruh

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		string s;cin>>s;
		sort(s.begin(),s.end());
		cout<<s<<"\n";
	}
	return 0;
}
