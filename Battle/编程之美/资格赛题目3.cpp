/*
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

int data[101][101];
int v[101];
int fang[101];


int main()
{
    int t,flag;
    int m,n;
    float sum,avg;
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        memset(data,0,sizeof(data));
        memset(v,0,sizeof(data));
        memset(fang,0,sizeof(fang));
        scanf("%d%d", &m,&n);
        for(i=0;i<m;i++)
        {
            sum=avg=0;
            for(j=0;j<n;j++)
            {
                scanf("%d", &data[i][j]);
                sum+=data[i][j];
            }
            avg=sum/(n*1.0);
            for(i=0;i<n;i++)
            {
                fang[i]+=data[i][j];
            }
        }
    }
    return 0;
}
**/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int last;
int boolx[100];
int booly[100];
int m,n;
unsigned int mini;
typedef struct point{
	int v;
	int x;
	int y;
};

bool more(const point &a,const point &b){
	return a.v>b.v;
}
bool lesss(const point &a,const point &b){
	return a.v<b.v;
}
vector<point> all;
vector<point> np;
void delp(int x,int y,int v){//
	if(boolx[x]>1&&booly[y]>1){
		boolx[x]--;
		booly[y]--;
	}else mini += v;
}
void addp(int x,int y){
	if(boolx[x] == 0)last--;
	if(booly[y] == 0)last--;
	boolx[x]++;
	booly[y]++;
}
int main(){
	int i,j,T,t = 1;
	int s;
	cin>>T;
	point p;
	while(T--){
		cin>>m>>n;
		for( i = 0 ;i<m;i++){
			for( j = 0;j<n;j++){
				cin>>s;
				p.x = i;
				p.y = j;
				p.v = s;
				all.push_back(p);
				boolx[i] = 0;
				booly[j] = 0;
			}
		}
		sort(all.begin(),all.end(),lesss);
		last = n + m;
		i = 0;
		while(last > 0){
			addp(all[i].x,all[i].y);
			np.push_back(all[i++]);
		}
		mini = 0;
		sort(np.begin(),np.end(),more);
		for( i =0; i<np.size();i++)
			delp(np[i].x,np[i].y,np[i].v);
		all.clear();
		np.clear();
		printf("Case %d: ",t++);
		cout<<mini<<endl;
	}
	return 0;
}
