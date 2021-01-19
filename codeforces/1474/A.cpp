/*input
5
1
0
3
011
3
110
6
111000
6
001011

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
		string s;cin>>s;
		int last=0;
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				cout<<1;
				last = 1+(s[0]-'0');
			}
			else 
			{
				if(s[i]=='0'){
					if(last==1) {cout<<0; last=0;}
					else {cout<<1; last = 1;}
				}
				else
				{
					if(last==2)  {cout<<0;last=1;}
					else {
						cout<<1;
						last=2;
					}
				}

			}
		}	
			cout<<"\n";
	}
	return 0;
}
