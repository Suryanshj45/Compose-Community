#include<bits/stdc++.h> 
using namespace std; 
 
struct Node{ 
    int data; 
    struct Node* parent; 
    struct Node* left; 
    struct Node* right; 
}; 
int c=0; 
void insert(Node* root,int n) 
{ 
    Node* x=root; 
while(root!=NULL) 
{ 
    if(root->data==n) 
    { 
      c++;   
    cout<<"Warning "<<n<<" is repeated"<<endl; 
    break; 
    } 
    else if(root->data>n) 
    { 
        c++; 
        if(root->left!=NULL) 
    root=root->left; 
    else 
    { 
        Node* newnode=new Node(); 
        newnode->data=n; 
        newnode->left=NULL; 
        newnode->right=NULL; 
        root->left=newnode; 
        newnode->parent=root; 
        root=root->left; 
        return; 
    } 
    } 
    else 
   { 
       c++; 
    if(root->right!=NULL) 
    root=root->right; 
    else 
    { 
        Node* newnode=new Node(); 
         newnode->data=n; 
        newnode->left=NULL; 
        newnode->right=NULL; 
        root->right=newnode; 
         newnode->parent=root; 
        root=root->right; 
        return; 
    } 
   } 
 
} 
} 
Node* mini(Node* root) 
{ 
    while(root->left!=NULL) 
        root=root->left; 
    return root; 
} 
Node* maxi(Node* root) 
{ 
    while(root->right!=NULL) 
        root=root->right; 
    return root; 
} 
 
 
Node* search(Node* root,int n) 
{ 
    while(root!=NULL) 
{ 
    
    if(root->data==n) 
    break; 
    else if(root->data>n) 
    root=root->left; 
    else 
    root=root->right; 
} 
if(root==NULL) 
{ 
    cout<<"There is no element with key "<<n<<" in the BST"<<endl; 
} 
else 
cout<<"There is element with key "<<n<<" in the BST"<<endl;
return root; 
} 
 
 
Node* succesor(Node* root,int n) 
{ 
    Node* r=search(root,n); 
    
if(r->right!=NULL) 
return mini(r->right); 
Node* y=r->parent; 
while(y!=NULL && r==y->right) 
{ 
    r=y; 
    y=y->parent; 
} 
return y; 
} 
 
Node* predecesor(Node* root,int n) 
{ 
    Node* r=search(root,n); 
    
if(r->left!=NULL) 
return maxi(r->left); 
Node* y=r->parent; 
while(y!=NULL && r==y->right) 
{ 
    r=y; 
    y=y->parent; 
} 
return y->left; 
} 
 
 
 
bool Path(Node *root, vector<int> &path, int key) 
{ 
   
    if (root == NULL)  
    return false; 
  
    path.push_back(root->data); 
     
    if (root->data == key) 
        return true; 
  
   
    if ( (root->left && Path(root->left, path, key)) || 
         (root->right && Path(root->right, path, key)) ) 
        return true; 
  
   
    path.pop_back(); 
    return false; 
} 
  
 
int findLCA(Node *root, int n1, int n2) 
{ 
   
    vector<int> path1, path2; 
  
    if ( !Path(root, path1, n1) || !Path(root, path2, n2)) 
          return -1; 
  
   
    int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++) 
        if (path1[i] != path2[i]) 
            break; 
    return path1[i-1]; 
} 
 
 
 
void delet(Node* root,int n) 
{ 
Node *r=root; 
while(root!=NULL) 
{ 
    
    if(root->data==n) 
    break; 
    else if(root->data>n) 
    root=root->left; 
    else 
    root=root->right; 
} 
if(root==NULL) 
{ 
    cout<<"There is no element with key "<<n<<" in the BST"<<endl; 
} 
else 
{ 
    if(root->left==NULL && root->right==NULL) 
       { 
        if(root->parent->left!=NULL) 
            root->parent->left=NULL; 
            else 
            root->parent->right=NULL; 
       } 
       else if(root->left!=NULL && root->right!=NULL) 
       { 
         Node* temp=succesor(r,root->data); 
         swap(root->data,temp->data); 
         if(temp->right!=NULL || temp->left!=NULL) 
         delet(r,temp->data); 
         else 
         { 
             if(temp->parent->left==NULL) 
             temp->parent->right=NULL; 
             else 
             temp->parent->left=NULL; 
         } 
          
          
       } 
       else 
       { 
        if(root->left!=NULL) 
        { 
            root->parent->left=root->left; 
        } 
        else 
        { 
           if(root->right->data>root->parent->data) 
           { 
               if(root->parent->right!=NULL) 
               root->parent->left=root->right; 
               else
root->parent->right=root->right; 
           } 
           else 
           root->parent->left=root->right; 
        } 
       } 
} 
} 
 
void preorder(Node* root) 
{ 
    if(root==NULL) 
    return; 
    cout<<root->data<<" "; 
    preorder(root->left); 
    preorder(root->right); 
} 
void postorder(Node* root) 
{ 
    if(root==NULL) 
    return; 
     
    postorder(root->left); 
    postorder(root->right); 
     cout<<root->data<<" "; 
} 
void inorder(Node* root) 
{ 
    if(root==NULL) 
    return; 
     
    inorder(root->left); 
    cout<<root->data<<" "; 
    inorder(root->right); 
} 
int main(){ 
   int n; 
   cin>>n; 
   int ar[n]; 
   
   for(int i=0;i<n;i++) 
   cin>>ar[i]; 
 
   Node* root=new Node(); 
   root->data=ar[0]; 
   root->left=NULL; 
   root->right=NULL; 
   for(int i=1;i<n;i++) 
    { 
        insert(root,ar[i]); 
    } 
    cout<<"preorder traversal is: "; 
    preorder(root); 
    cout<<endl; 
     cout<<endl; 
      
      
    cout<<"postorder traversal is: "; 
    postorder(root); 
    cout<<endl; 
    cout<<endl; 
     
     
    cout<<"inorder traversal is: "; 
    inorder(root); 
    cout<<endl; 
    cout<<endl; 
     
     
    delet(root,2); 
    cout<<"inorder after deleting 2 is: "; 
    inorder(root); 
    cout<<endl; 
    cout<<endl; 
     
     
    Node* a; 
    a=succesor(root,13); 
    cout<<"succesor is: "<<a->data<<endl; 
    cout<<endl; 
     
     
    a=predecesor(root,4); 
    cout<<"predecesor is: "<<a->data<<endl; 
    cout<<endl; 
     
     
    cout<<"COMMON ANCESTOR OF HIGHEST LEVEL OF 2 ANS 9 IS: "; 
     if(findLCA(root,2,9)==-1) 
     cout<<"DOEST NOT EXIST"<<endl; 
     else 
     cout<<findLCA(root,2,9)<<endl; 
      cout<<endl; 
       
       
       
    c=0; 
   int br[]={1,2,3,4,5,6}; 
   int p=0; 
    int ans=0; 
   do 
   { 
       p++; 
       Node* nroot=new Node(); 
   nroot->data=br[0]; 
   nroot->left=NULL; 
   nroot->right=NULL; 
   
   for(int i=1;i<6;i++) 
    { 
        insert(nroot,br[i]); 
        ans=ans+c; 
        c=0; 
    } 
   } 
   while(next_permutation(br,br+6)); 
   cout<<ans<<" "<<p<<endl; 
    cout<<endl; 
     
     
  cout<<"Average numberof comparisons done= "<<(float)ans/p<<endl; 
   
   
}