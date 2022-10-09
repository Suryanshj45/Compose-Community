#include <bits/stdc++.h>

using namespace std;

struct node
{
	char data;
	
	struct node* first_child;
	struct node* next_child;
	struct node* parent;
	
};

struct node* create_node(char k)
{
	struct node* newnode = new node();
	newnode->data = k;
	newnode->next_child = NULL;
	newnode->parent = NULL;
	newnode->first_child = NULL;
	return newnode;
}

struct node* join_to_leaf(struct node* n,char k)
{
	struct node* newnode=create_node(k);
	n->first_child = newnode;
	newnode->parent = n;
	return newnode;
}
struct node* join_sibling(struct node* n,char k)
{
	struct node* newnode=create_node(k);
	n->next_child=newnode;
	newnode->parent=n->parent;
}
int c=0;
int leaf=0;
int i=0;
void is_root(struct node* n)
{
	if(n->parent==NULL)
		cout<<"Node "<<n->data<<" is root"<<endl;
	else
		cout<<"Node "<<n->data<<" is not a root"<<endl;
		
}
void is_leaf(struct node* n)
{
	if(n->first_child==NULL)
		cout<<"Node "<<n->data<<" is leaf"<<endl;
	else
		cout<<"Node "<<n->data<<" is not a leaf"<<endl;
}
void is_presence(struct node* n)
{
if(n->parent!=NULL || n->first_child!=NULL)
{
	cout<<"Key is present"<<endl;
}	
	else
		cout<<"Ley is not present"<<endl;
}

void preorder(struct node* root)
{
	if(root==NULL)
		return;
	if(root->first_child==NULL)
		leaf++;
	else
		i++;
	cout<<root->data<<" ";
	preorder(root->first_child);
	preorder(root->next_child);
}
void postorder(struct node* root)
{
	if(root==NULL)
		return;
	
	postorder(root->first_child);
	cout<<root->data<<" ";
	postorder(root->next_child);
	
	
}
int mx=INT_MIN;
int k=0;
void hieght(struct node* root)
{
	if(root==NULL)
	{
		mx=max(mx,k);
		return;
	}
	
		k++;
	hieght(root->first_child);
	k--;
	hieght(root->next_child);
}

int main()
{
	struct node* A=create_node('A');
	struct node* B=join_to_leaf(A,'B');
	struct node* C=join_sibling(B,'C');
	struct node* D=join_sibling(C,'D');
	struct node* E=join_to_leaf(B,'E');
	struct node* F=join_sibling(E,'F');
	struct node* G=join_sibling(F,'G');
	struct node* H=join_to_leaf(C,'H');
	struct node* I=join_to_leaf(D,'I');
	struct node* J=join_sibling(I,'J');
	struct node* K=join_to_leaf(I,'K');
	struct node* L=join_sibling(K,'L');
	struct node* M=join_sibling(L,'M');
	
		preorder(A);
		cout<<endl;
		postorder(A);
		cout<<endl;
	cout<<"No of leaf: "<<leaf<<endl;
	cout<<"No of internal: "<<i<<endl;
	cout<<"No of nodes: "<<i+leaf<<endl;
	is_leaf(J);
	is_root(A);
	is_presence(A);
	hieght(A);
	cout<<"height of tree: "<<mx<<endl;
}
