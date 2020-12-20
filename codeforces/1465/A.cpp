/*input
5
2
))
12
gl))hf))))))
9
gege)))))
14
)aa))b))))))))
1
)

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
		int cnt1=0;
		int R = n-1;
		while(R>=0 && s[R]==')') R--;
		cout<<( n-R-1 > R+1 ?"Yes":"No")<<"\n"; 	
	}
	return 0;
}
