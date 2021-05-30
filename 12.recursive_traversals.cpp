//Recursive Btree traversal.
////M.sreeja Rollno:100519733024
#include <bits/stdc++.h>
using namespace std;
struct BTnode
{
 int data;
 struct BTnode *LC;
 struct BTnode *RC;
 BTnode(int data)
 {
 this->data = data;
 LC = RC = NULL;
 }
};

void preorder(struct BTnode * root)
{
  if (root==NULL)
  return;
  cout<<root->data<<" ";
  preorder(root->LC);
  preorder(root->RC);

}
void postorder(struct BTnode * root)
{
 if (root == NULL)
 return;
 postorder(root->LC);
 postorder(root->RC);
 cout<<root->data<<" ";
}
void inorder(struct BTnode *root)
{
 if (root == NULL)
 return;
 inorder(root->LC);
 cout<<root->data<<" ";
 inorder(root->RC);
}

int main()
{
 struct BTnode *root = new BTnode(1);
 root->LC = new BTnode(2);
 root->RC = new BTnode(3);
 root->LC->LC = new BTnode(4);
 root->LC->RC = new BTnode(5);
 cout<<"Pre-Order traversal of the Binary Search Tree is: ";
 preorder(root);
 cout<<endl;
 cout<<"IN-Order traversal of the Binary Search Tree is: ";
 inorder(root);
 cout<<endl;
 cout<<"Post-Order traversal of the Binary Search Tree is: ";
 postorder(root);
 return 0;
}

