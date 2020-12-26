/*input
3
3
777
111
3
314
159
5
09281
09281

0002020232
0002020241
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
		string r;cin>>r;
		string b;cin>>b;

		int cntr=0,cntb=0,cnt=0;
		for(int i=0;i<n;i++)
		{
			if(r[i]<b[i]) cntb++; 
			else if(r[i]>b[i]) cntr++;
			else cnt++;
		} 

		if(cntr>cntb) cout<<"RED\n";
		else if(cntr<cntb) cout<<"BLUE\n";
		else  cout<<"EQUAL\n";

	}
	return 0;
}
