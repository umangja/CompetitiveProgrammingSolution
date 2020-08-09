/*input
999983
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int K;cin>>K;
	set<int> st;
	int ans =1;

	int mod = 7%K;
	st.insert(mod);
	int pos=1;
	
	while(mod!=0 && pos==1)
	{
		mod = (10*mod+7)%K;
		// cout<<mod<<"\n";
		if(st.find(mod)!=st.end()) pos=0;
		else {
			ans++;
			st.insert(mod);
		}
	}

	if(!pos) ans=-1;
	cout<<ans<<"\n";
	return 0;
}
