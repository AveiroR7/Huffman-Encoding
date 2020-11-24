#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define NULL 0
struct node
{
int f ;
struct node *left, *right, *father ;
int leftson ;
};
struct node1
{
struct node *data ;
struct node1 *next ;
};
struct node1 *front =NULL, *rear=NULL;
int count = 0 ;
void insert(struct node* x)
{
struct node1 *pnode ;

pnode=(struct node1*)malloc(sizeof(struct node1)) ;
pnode-&gt;data=x ;
pnode-&gt;next=NULL;
if(front==NULL)
front=rear=pnode ;
else

{
rear-&gt;next=pnode ;
rear=pnode ;
}
++count ;
}
struct node* removes()
{
int min ;
struct node1 *follow , *follow1 , *p , *p1 ;
p=p1=front ;
follow=follow1=NULL ;
min=front-&gt;data-&gt;f ;
while(p!=NULL)
{
if(p-&gt;data-&gt;f &lt; min)
{
min=p-&gt;data-&gt;f ;
follow1=follow ;
p1=p ;
}
follow=p ;
p=p-&gt;next ;
}
if(p1==front)
{
front=front-&gt;next ;
if(front==NULL)

rear=NULL ;
}
else if(p1==rear)
{
rear=follow1 ;
rear-&gt;next=NULL ;
}
else
follow1-&gt;next=p1-&gt;next ;

--count ;
return p1-&gt;data ;
}
struct node *root = NULL;
int frequency[100];
struct node* position[100];
void main()
{
struct node *p1, *p2, *p, *pnode ;
int i , j , n , z ;
char code[20];
clrscr();
printf(&quot;Enter the number of symbols: &quot;);
scanf(&quot;%d&quot;,&amp;n) ;
printf(&quot;Enter the frequency of symbols: &quot;);
for(i=0;i&lt;n;i++)
scanf(&quot;%d&quot;,&amp;frequency[i]) ;
for(i=0;i&lt;n;i++)

{
pnode=(struct node*)malloc(sizeof(struct node)) ;
pnode-&gt;f=frequency[i] ;
position[i] = pnode;
insert(pnode);
}
while(count&gt;1)
{
p1=removes();
p2=removes();
p=(struct node*)malloc(sizeof(struct node)) ;
p-&gt;f = p1-&gt;f + p2-&gt;f ;
p-&gt;left=p1;
p-&gt;right=p2;
p1-&gt;father=p;
p1-&gt;leftson=1;
p2-&gt;father=p;
p2-&gt;leftson=0;
insert(p);
}
root=removes();
for(i=0;i&lt;n;i++)
{
p=(struct node*)malloc(sizeof(struct node)) ;p=position[i];
for(z=0;z&lt;20;z++)
code[z]=&#39;\0&#39;;

// Travel up the tree

while(p!=root)
{
if(p-&gt;leftson==1)
strcat(code,&quot;0&quot;) ;
else
strcat(code,&quot;1&quot;) ;
p=p-&gt;father;
}
printf(&quot;\nCode of symbol %d is : &quot;,i+1) ;
for(j=strlen(code)-1;j&gt;=0;j--)
printf(&quot;%c&quot;,code[j]) ;
}
getch();
}
