//Iterative BTree traversal
//M.sreeja Rollno:100519733024
#include <bits/stdc++.h>
using namespace std;
struct BTnode {
int data;
struct BTnode *LC;
struct BTnode *RC;
 BTnode(int data)
 {
 this->data = data;
 LC = RC = NULL;
 }
 };

 void preorderIterative(struct BTnode * root)
 {
 if (root == NULL)
 return;

 stack<BTnode*> st;
 BTnode* curr=root;

while (!st.empty() || curr != NULL) {
 while (curr != NULL) {
 cout << curr->data << " ";

 if (curr->RC)
 st.push(curr->RC);

 curr = curr->LC;
}

 if (!st.empty() ) {
 curr = st.top();
 st.pop();
 }
 }
 }
 void postorderIterative(struct BTnode * root)
 {
 if (root == NULL)
 return;
 stack<struct BTnode *> s1, s2;
 s1.push(root);
 struct BTnode * node;
 while (!s1.empty()) {
 node = s1.top();
 s1.pop();
 s2.push(node);
if (node->LC)
s1.push(node->LC);
if (node->RC)
s1.push(node->RC);
}
 while (!s2.empty()) {
node = s2.top();
s2.pop();
cout << node->data << " ";
}
}

void inorderIterative(struct BTnode *root)
{
stack<BTnode *> s;
BTnode *curr = root;
while (curr != NULL || s.empty() == false)
{
while (curr != NULL)
 {
   s.push(curr);
   curr = curr->LC;
 }
curr = s.top();
s.pop();
cout << curr->data << " ";
curr = curr->RC;
 } /* end of while */
 }

int main() {
struct BTnode *root = new BTnode(1);
root->LC = new BTnode(2);
root->RC = new BTnode(3);
root->LC->LC = new BTnode(4);
root->LC->RC = new BTnode(5);
cout<<"Pre-Order traversal of the Binary Search Tree is: ";
preorderIterative(root);
cout<<endl;
cout<<"IN-Order traversal of the Binary Search Tree is: ";
inorderIterative(root);
cout<<endl;
cout<<"Post-Order traversal of the Binary Search Tree is: ";
postorderIterative(root);
return 0;
}





