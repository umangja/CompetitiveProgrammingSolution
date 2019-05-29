#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i,a,b) for(long long int i=a;i<b;i++)


string s;
long long int n;
const long long int N = 1e6+5;
vector< long long int > pi(N);

void f()
{
	pi[0]=0;
	rep(i,1,n)
	{
		ll k = pi[i-1];
		while(k>0 && s[k]!=s[i])
		{
			// cout<<"a";
			k=pi[k-1];
		}

		if(s[i]==s[k])
			pi[i]=k+1;
		else
			pi[i]=k;
	}	


	// rep(i,0,n)
		// cout<<pi[i]<<" ";
	// cout<<"\n";
}

int main()
{
	cin>>s;
	n=(long long int)s.size();
	f();

	if(pi[n-1]!=0)
	{
		int f=0;
		rep(i,0,n-1)
		{
			if(pi[i]==pi[n-1])
			{
				cout<<s.substr(0,pi[n-1]);
				f=1;
				return 0;
			}
		}

		if(!f && pi[pi[n-1]-1]!=0)
		{
			cout<<s.substr(0,pi[pi[n-1]-1]);
		}
		else if(!f)
			cout<<"Just a legend";
	}
	else
		cout<<"Just a legend";	
}