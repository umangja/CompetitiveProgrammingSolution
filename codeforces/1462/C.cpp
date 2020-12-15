/*input
4
1
5
15
50



*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int x;cin>>x;
		vector<int> a;
		for(int i=9;i>0;i--) if(x>=i) x-=i,a.push_back(i);
		sort(a.begin(), a.end());
		if(x==0) for(int i=0;i<a.size();i++) cout<<a[i]; 
		else cout<<"-1";
		cout<<"\n";
	}
	return 0;
}
