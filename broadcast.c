#include<stdio.h>
int a[10][10],n;
void main ()
{
int i,j,root;
printf("enter the number of node");
scanf("%d",&n);
printf("enter the adjacentmatrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
printf("enter the connecting of %d-->%d::", i,j);
scanf("%d",&a[i][j]);
}
printf("enter root node::\n");
scanf("%d",&root);
adj(root);
}
adj(int k)
{
int i,j;
printf("adjacent node of root node%d,:\n,",k);
for(j=1;j<=n;j++)
{
if(a[k][j]==1 || a[j][k]==1)
printf("%d\t",j);
}
printf("\n non adjacent node of root node:\n");
printf("%d\n",k);
for(j=1;j<=n;j++)
{
if(a[k][j]==0 || a[j][k]==0)
printf("%d\t",j);
}
printf("\n");
for(i=1;i<=n;i++)
{
if((a[k]==0) &&(a[i][k]==0) &&(i=k))
printf("%d",i);
}
}