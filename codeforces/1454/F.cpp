/*input
6
11
1 2 3 3 3 4 4 3 4 2 1
8
2 9 1 7 3 9 4 1
9
2 1 4 2 4 3 3 1 2
7
4 2 1 1 4 1 4
5
1 1 1 1 1
7
4 3 4 3 3 3 4

*/
#include<bits/stdc++.h>
using namespace std;

const int  N = 2e5+5;
long long int seg[4*N];
vector<long long int> a;
int n;

void build(int id,int st,int en)
{

	if(st==en) seg[id] = a[st];
	else
	{
		int mid = (st+en)/2; 
		build(2*id,st,mid);
		build(2*id+1,mid+1,en);
		seg[id]=min(seg[2*id],seg[2*id+1]);
	}
}

long long int query(int node,int s,int e,int l,int r)
{
	if(r<s || l>e) return 1e9+9;
	if(s>=l && e<=r) return seg[node];
	int mid = (s+e)/2;
	long long int v1 = query(2*node,s,mid,l,r);
	long long int v2 = query(2*node+1,mid+1,e,l,r);
	return min(v1,v2);
}


int main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>n;
		a.clear();a.resize(n);
		for(int i=0;i<n;i++) cin>>a[i];

		vector<long long int> mxR(n,-1),mx(n,-1);
		mxR[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--) mxR[i]=max(a[i],mxR[i+1]);
		mx[0]=a[0];
		for(int i=1;i<n;i++) mx[i]=max(a[i],mx[i-1]);


		vector<long long int> prevSmaller(n),nextSmaller(n);
		stack<long long int> st;
		for(int i=0;i<n;i++)
		{
			while(st.size()>0 && a[st.top()]>=a[i]) st.pop();
			if(st.size()>0) prevSmaller[i] = st.top();
			else prevSmaller[i]=-1;
			st.push(i);
			// cout<<prevSmaller[i]<<" ";
		}
		// cout<<"\n";

		while(st.size()>0) st.pop();
		for(int i=n-1;i>=0;i--)
		{
			while(st.size()>0 && a[st.top()]>=a[i]) st.pop();
			if(st.size()>0) nextSmaller[i] = st.top();
			else nextSmaller[i]=n;
			st.push(i);
		}

		build(1,0,n);
		int ok=0;
		for(int y=1;y<n-1;y++)
		{
			int z = nextSmaller[y];
			int x = prevSmaller[y];

			// if(y==6) cout<<x<<" "<<z<<"\n";

			if(x==-1) x++;
			if(z==n) z--;

			if(x<n && z>=0 && x<y && z>y && mx[x]==a[y] && mxR[z]==a[y])
			{
				// cout<<y<<"\n";
				ok=1;
				cout<<"YES\n";
				cout<<x+1<<" "<<n-x-1-n+z<<" "<<n-z<<"\n";
				break;
			}

			if(x+1<n && z>=0 && x+1<y && z>y && mx[x+1]==a[y] && mxR[z]==a[y])
			{
				x++;
				// cout<<y<<"\n";
				ok=1;
				cout<<"YES\n";
				cout<<x+1<<" "<<n-x-1-n+z<<" "<<n-z<<"\n";
				break;
			}

			if(x<n && z-1>=0 && x<y && z-1>y && mx[x]==a[y] && mxR[z-1]==a[y])
			{
				z--;
				// cout<<y<<"\n";
				ok=1;
				cout<<"YES\n";
				cout<<x+1<<" "<<n-x-1-n+z<<" "<<n-z<<"\n";
				break;
			}

			x++,z--;
			if(x<n && z>=0 && x<y && z>y && mx[x]==a[y] && mxR[z]==a[y])
			{
				// cout<<y<<"\n";
				ok=1;
				cout<<"YES\n";
				cout<<x+1<<" "<<n-x-1-n+z<<" "<<n-z<<"\n";
				break;
			}


		}
		if(!ok) cout<<"NO\n";


	}
	return 0;
}
