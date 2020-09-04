/*input

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--) {
	    int n,x,y;
	    cin>>n>>x>>y;
	    int dmul = y-x;
	   	int ans = INT_MAX;
	    int dopt=-1;
	    for(int d=1;d<=dmul;d++)
	    {
	    	if(dmul%d==0)
	    	{
	    		int tot = n;

	    		tot-=((y-x)/d +1);
	    		int val = x;
	    		while(tot>0 && val-d>0)
	    		{
	    			tot--;
	    			val-=d;
	    		}

	    		val=y;
	    		while(tot>0) val+=d,tot--; 
	    		if(tot==0)
	    		{
	    			if(val<ans)
	    			{
	    				ans=val;
	    				dopt = d;
	    			}

	    		} 
	    	}
	    }

	    assert(dopt!=-1);
	    for(int i=0;i<n;i++) {cout<<ans<<" "; ans-=dopt; }
    	cout<<"\n";
	}
	return 0;
}
