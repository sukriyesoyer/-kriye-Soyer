//Þükriye SOYER 150116010
//This program purpose is builds a binary search tree (BST) from a given sequence and attemps to find other sequences that yield the same BST topology.
// C++ program to check if two BSTs 
// are identical 
  
#include <iostream> 
#include<stdio.h>
#include<stdlib.h>
using namespace std; 
void next(struct Node *tree) ;
int n =0;
  
// BST node 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
};

  
// Utility function to create a new Node 
struct Node* newNode(int data) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
} 
  
// Function to perform inorder traversal 
void inorder(Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    inorder(root->left); 
  
    cout << root->data << " "; 
  
    inorder(root->right); 
} 
Node *insert(Node *tree,int x){
 	
 	if(tree==NULL){
 		Node *root=(Node*)malloc(sizeof(Node));
 		root->left=NULL;
 		root->right=NULL;
 		root->data=x;
 		return root;
	 }
	 
	if(tree->data<x){
	 	tree->right=insert(tree->right,x);
        	return tree;
	 }
 	 
	  tree->left=insert(tree->left,x);
 	return tree;
 }
  void sort(Node *tree){
 	if(tree==NULL)
 		
	 return ;
	 
	 sort(tree->left);
	  printf("%d ",tree->data);
     sort(tree->right);

 }
 void sort1(Node *tree){
 	if(tree==NULL)
 		
	 return ;
	 printf("%d ",tree->data);
	 sort1(tree->left);
     sort1(tree->right);

           
 }
 void sort2(Node *tree){
 	if(tree==NULL)
 		
	 return ;
	sort2(tree->left);
    sort2(tree->right);
     printf("%d ",tree->data);
	
 }
  


  
// Function to check if two BSTs 
// are identical 
int isIdentical(Node* root1, Node* root2) 
{ 
    // Check if both the trees are empty 
    if (root1 == NULL && root2 == NULL) 
        return 1; 
    // If any one of the tree is non-empty 
    // and other is empty, return false 
    else if (root1 != NULL && root2 == NULL) 
        return 0; 
    else if (root1 == NULL && root2 != NULL) 
        return 0; 
    else { // Check if current data of both trees equal 
        // and recursively check for left and right subtrees 
        if (root1->data == root2->data && isIdentical(root1->left, root2->left) 
            && isIdentical(root1->right, root2->right)) 
            return 1; 
        else
            return 0; 
    } 
} 
int size(struct Node* tree) {
  if (tree==NULL) {
    return(0);
  } else {
    return(size(tree->left) + 1 + size(tree->right));
  }
}
 
void replaceNode(struct Node *tree) 
{
struct Node* temp;
int temp1;
    // Base Case 
    if (tree== NULL) 
        return ; 
    // swap the pointers in this node
    temp1 = tree->left->data;
    tree->left->data = tree->right->data;
    tree->right->data = temp1;
	
	 
}


void mirror(struct Node* tree)  
{ 
    if (tree == NULL)  
        return;  
    else
    { 
        struct Node* temp; 
          
        /* do the subtrees */
        mirror(tree->left); 
        mirror(tree->right); 
      
        /* swap the pointers in this node */
        temp     = tree->left; 
        tree->left = tree->right; 
        tree->right = temp; 
    } 
}  
void mirror1(struct Node* tree)  
{ 
    if (tree == NULL)  
        return;  
    else
    { 
        struct Node* temp; 
          
        /* do the subtrees */
    
        mirror1(tree->right->left); 
        mirror1(tree->left->right);
       
      
        /* swap the pointers in this node */
        temp     = tree->left->left; 
        tree->left->left = tree->right->right; 
        tree->right->right = temp; 
        
    } 
}  
bool convertToMirror(Node *root)
{
    // base case: if tree is empty
    if (root == NULL)
        return true;

    // convert left subtree
    convertToMirror(root->left);

    // convert right subtree
    convertToMirror(root->right);

    // swap left subtree with right subtree
    swap(root->left, root->right);
}
void print(Node *tree){
	if(size(tree)==3){
		printf("1)");
		sort1(tree);
		mirror(tree);
		printf("\n2)");
		sort1(tree);
		
	}
	else if(size(tree)==4){
		printf("\n1)");
		sort1(tree);
		mirror(tree);
		printf("\n2)");
		sort1(tree);
	}
	else if(size(tree)==5||size(tree)==6){
	 	printf("\n1)");
		sort1(tree);
		 convertToMirror(tree->left);
		printf("\n2)");
		sort1(tree);
		 printf("\n3)");
		 mirror(tree);
		  sort1(tree);
		convertToMirror(tree->right);
		   printf("\n4)");
		  sort1(tree); 
	
	}
	else if(size(tree)>6)
	{
		printf("\n1) ");
		 sort1(tree);
		  convertToMirror(tree->left);
		   printf("\n2) ");
		  sort1(tree); 
		 convertToMirror(tree->right);
		   printf("\n3) ");
		  sort1(tree); 
		  convertToMirror(tree->left);
		   printf("\n4) ");
		  sort1(tree);
		  printf("\n5) ");
		 mirror(tree);
		  sort1(tree);
		  convertToMirror(tree->left);
		   printf("\n6) ");
		  sort1(tree); 
		 convertToMirror(tree->right);
		   printf("\n7) ");
		  sort1(tree); 
		  printf("\n8) ");
		   mirror(tree->left);
		  sort1(tree);
		  
		 
		 
		   
		 
		 }
	
}

int binarytree_count_recursive(struct Node *root)
{
    int count = 1;
    if (root->left != NULL) {
       count += binarytree_count_recursive(root->left);
    }
    if (root->right != NULL) {
        count += binarytree_count_recursive(root->right);
    }
    return count;
}

double fac (double n){
 	double ans=1;
 	for(int i=1;i<n+1;i++){
 		ans *=i;
	 }
	 return ans;
 }

 double countt (struct Node *root){
int a;
 	int b;
 	int c;
    double t;
 		a=binarytree_count_recursive(root->right);
	    b=binarytree_count_recursive(root->left);
	    c=a+b;
	    t+= a*b*(fac(c)/(fac(b)*fac(a)));
	     
 	if(root==NULL){
 		return 1;
	 }
	 if (root->left != NULL&&root->right != NULL) {
    t+= binarytree_count_recursive(root->right)*binarytree_count_recursive(root->left)*(fac(binarytree_count_recursive(root->right)+binarytree_count_recursive(root->left))/fac(binarytree_count_recursive(root->right))*fac(binarytree_count_recursive(root->left)));
}
   	
	return t; }
// Driver code 
int main() 

{ 
    Node*tree=NULL;
 	int N;
 	int item;
 	double a;
 	double b;
 	double c;
 	double totall;
 	
 	printf ("Insert the number of nodes :\n");
 	scanf("%d",&N);
 	for(int i=0;i<N;i++){
 		printf("Insert value stored into the node %d:\n",i+1);
 		scanf("%d",&item);
 		tree=insert(tree,item);
 	
		 }
		  a=binarytree_count_recursive(tree->right);
	      b=binarytree_count_recursive(tree->left);
	      c=a+b;
		  
		  totall=fac(c)/(fac(b)*fac(a));
	printf("\nIn_order:");
 	sort(tree);
 	printf("\nPre_order:");
 	sort1(tree);
 	printf("\nPost_order:");
 	sort2(tree);
 	printf("\nTotal sequences :%f",countt(tree));
	    printf("\nThe sequences:\n");
	     print(tree);

} 
