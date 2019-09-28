
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int ex,ey,n,m;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
struct Node{
	int x,y;
	int step;          //走到当前点的步数
}S;
char map[105][105];
int vis[105][105];
queue<Node>  q;
int fun(int x,int y)          //判断这个点是否能走
{
	if((x>=0&&x<n&&y>=0&&y<m)&&vis[x][y]==0&&map[x][y]!='*') return 1;
	else return 0;
//	if(x<0||x>=n||y<0||y>=m) return 0;
//	if(map[x][y]=='*') return 0;
//	if(vis[x][y]==1) return 0;
//	return 1;

}
int bfs()
{
	q.push(S);
	vis[S.x][S.y]=1;
	while(!q.empty())
	{
		Node top;
		top=q.front();
		q.pop();
		if(top.x==ex&&top.y==ey)
		{
			return top.step;
		}
		for(int i=0;i<4;i++)
		{
			int xx=top.x+dx[i];
			int yy=top.y+dy[i];
			if(fun(xx,yy)==1)
			{
				vis[xx][yy]=1;
				Node node;
				node.x=xx,node.y=yy,node.step=top.step+1;
				q.push(node);
			}
		}
	}
}

int main()
{
	memset(vis,0,sizeof(vis));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	scanf("%s",map[i]);
	scanf("%d %d %d %d",&S.x,&S.y,&ex,&ey);
	S.step=0;
	printf("%d",bfs());
	return 0;
}
