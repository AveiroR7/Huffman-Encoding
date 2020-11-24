# Huffman-Encoding
Data Structure Mini project using C language.

Declarations:
a. Let n be the total number of symbols in the original alphabet .
b. Let frequency , position ,code be the arrays of size n.
frequency[i] be the relative frequency of ithsymbol. positon[i]
contains a pointer to the node representing the ith symbol. code[i]
will contain code of the ith symbol after the algorithm executes.
c. Let rootnodes be an ascending priority queue which contains
pointers to roots of partially built binary trees. The operation
pqinsert() inserts a pointer at the rear end of the queue &amp; the
operation pqmiddelete() removes from the priority queue a pointer
to the node with smallest relative frequency .
d. Let p=maketree(x) be an operation which creates a node ith value
x and stores its address in pointer p.
e. Let setleft(p,p1) be an operation which makes p1 a left child of
p.Let setright(p,p2) be an operation which makes p2 a right child
of p.
f. Let isleft(p) be an operation which returns TRUE if p is a left
child.
g. Let q=father(p) be an operation which returns the address of
father of p to q.
h. Let info(p) be an operation which returns data part of node
pointed by p.

Actual Algorithm:

I.Let rootnodes= empty ascending priority queue
II.for(i=0;i&lt;n;i++0)
{
p=maketree(frequency[i]);
position[i]=p;
pqinsert(rootnodes,p);
}
III.while(rootnodescontains ,more than one element)
{
p1=pqmindelete(rootnodes);
p2=pqmindelete(rootnodes);
/*Combine p1 &amp; p2 as branches of single tree*/
p=maketree(info(p1)+info(p2));
setleft(p,p1);
setleft(p,p2);
pqinsert(rootnodes);
}
IV.
root=pqmindelete(rootnodes);
for(i=0;i&lt;n;i++)
{
p=position[i];
code[i]=the null bit string;
while(p!=root)
{
if(isleft(p))
code[i]=0 followed by code[i];
else
code[i]=1 followed by code[i];
p=father(p);
}
}
