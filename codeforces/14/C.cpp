#include<bits/stdc++.h>
#define p pair<int,int>
using namespace std;
int main()
{
	map<p,int>u;
	int x=0,y=0,x1,y1,x2,y2,a=0;
	for (;a<4;a++)
	{
		cin>>x1>>y1>>x2>>y2;
		x+=((x1==x2)&&(y1!=y2));
		y+=((x1!=x2)&&(y1==y2));
		u[p(x1,y1)]++;u[p(x2,y2)]++;
	}
	a=((x==2)&&(y==2));
	for(auto i:u)a&=(i.second==2);
	cout<<(a==1?"YES":"NO");
}