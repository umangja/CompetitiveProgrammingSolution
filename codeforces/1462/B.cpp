/*input
6
8
20192020
8
22019020
4
2020
5
20002
6
729040
6
200200


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
		string tar = "2020";
		int pos=0;
		for(int L=0;L<=4;L++)
		{
			if(  (L==0 || s.substr(0,L)==tar.substr(0,L)) &&  (L==4 || s.substr( n-4+L,4-L )==tar.substr(L,4-L))) pos=1;
		}

		cout<<(pos?"YES\n":"NO\n");


	}
	return 0;
}
