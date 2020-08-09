/*input
 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,D;cin>>n>>D;
  	int ans=0; 
  	for(int i=0;i<n;i++)
    {
      long long int x,y;cin>>x>>y;
      ans+=((x*x+y*y)<=D*D);
    }
  	cout<<ans<<"\n";
	return 0;
}
