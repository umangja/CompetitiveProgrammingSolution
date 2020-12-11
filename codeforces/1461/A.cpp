/*input
2
3 2
4 1

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n,k;cin>>n>>k;
		for(int i=0;i<k-1;i++) cout<<'a';
		int left = n-k+1;
		for(int i=0;i<left/3;i++) cout<<"abc";
		left%=3;
		if(left==1) cout<<'a';
		else if(left==2) cout<<"ab";
		cout<<"\n";
	}
	return 0;
}
