/*input
3
1
2
30

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		int n;cin>>n;
		cout<<9;
		int cur=8;
		for(int i = n-1;i>0;i--)
		{
			cout<<cur;
			cur++;
			cur%=10;
			
		}	

		cout<<"\n";
	}
	return 0;
}
