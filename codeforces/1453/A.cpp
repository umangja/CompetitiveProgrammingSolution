/*input
3
1 2
1
3 4
3 2
1 3 4
2 4
9 14
2 7 16 28 33 57 59 86 99
3 9 14 19 25 26 28 35 41 59 85 87 99 100

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n,m;cin>>n>>m;
		vector<int> a(n),b(m);
		set<int> st;
		for(int i=0;i<n;i++) cin>>a[i],st.insert(a[i]);
		for(int i=0;i<m;i++) cin>>b[i],st.insert(b[i]);
		cout<<n+m-(int)st.size()<<"\n";
	}
	return 0;
}
