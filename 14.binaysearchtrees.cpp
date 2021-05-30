//Binary search trees.
//A.Harichandana, Roll no-100519733001,CSE Third SEM.
#include<bits/stdc++.h>
using namespace std;
struct BTnode
{
        struct BTnode *LC;
        int data;
        struct BTnode *RC;
};

struct BTnode *insert(struct BTnode *ptr, int ikey);
struct BTnode *Min(struct BTnode *ptr);
struct BTnode *Max(struct BTnode *ptr);
struct BTnode *search(struct BTnode *root, int key);
struct BTnode *deleteNode(struct BTnode *root, int key);
int main( )
{
        struct BTnode *root=NULL,*ptr;
        int choice,k,key1,key2;

        while(1)
        {
                cout<<"\n";
                cout<<"1.Insert"<<"\n";
                cout<<"2.Search for given key"<<"\n";
                cout<<"3.Find minimum and maximum"<<"\n";
                cout<<"4.delete node with given key"<<"\n";
                cout<<"5.Quit"<<"\n";
                cout<<"\n"<<"Enter your choice : ";
                cin>>choice;

                switch(choice)
                {
                case 1:
                        cout<<"\n"<<"Enter the key to be inserted : ";
                        cin>>k;
                        root = insert(root, k);
                        break;

                case 2:
                        cout<<"\n"<<"Enter the key to be searched : ";
                        cin>>key1;
                        root = search(root, key1);
                        if(root!=NULL)
                        cout<<"yes!!";
                        break;

                 case 3:
                        ptr = Min(root);
                        if(ptr!=NULL)
                                cout<<"\n"<<"Minimum key is: "<< ptr->data;
                        ptr = Max(root);
                        if(ptr!=NULL)
                                cout<<"\n"<<"Maximum key is: "<< ptr->data ;
                        break;

                 case 4:
                        cout<<"\n"<<"Enter the key to be deleted : ";
                        cin>>key2;
                        root = deleteNode(root, key2);
                        break;

                 case 5:
                        exit(1);

                 default:
                        printf("\nWrong choice\n");
                }/*End of switch */
        }/*End of while */

        return 0;

}/*End of main( )*/


struct BTnode *insert(struct BTnode *ptr, int ikey )
{
        struct BTnode *root;
        if(ptr==NULL)
        {
                ptr = (struct BTnode *) malloc(sizeof(struct BTnode));
                ptr->data = ikey;
                ptr->LC = NULL;
                ptr->RC = NULL;
                root=ptr;
        }
        else if(ikey < ptr->data) /*Insertion in left subtree*/
                ptr->LC = insert(ptr->LC, ikey);
        else if(ikey > ptr->data) /*Insertion in right subtree */
                ptr->RC = insert(ptr->RC, ikey);
        else
                printf("\nDuplicate key\n");

        return ptr;
}/*End of insert( )*/


struct BTnode *Min(struct BTnode *ptr)
{
        if(ptr==NULL)
                return NULL;
        else if(ptr->LC==NULL)
        return ptr;
        else
                return Min(ptr->LC);
}/*End of min()*/

struct BTnode *Max(struct BTnode *ptr)
{
        if(ptr==NULL)
                return NULL;
        else if(ptr->RC==NULL)
        return ptr;
        else
        return Max(ptr->RC);
}/*End of max()*/


struct BTnode *search(struct BTnode* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;

    // Key is greater than root's key
    if (root->data < key)
       return search(root->RC, key);

    // Key is smaller than root's key
    return search(root->LC, key);
}

struct BTnode *deleteNode(struct BTnode* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->LC = deleteNode(root->LC, key);

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->RC = deleteNode(root->RC, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->LC == NULL) {
            struct BTnode *temp = root->RC;
            free(root);
            return temp;
        }
        else if (root->RC == NULL) {
            struct BTnode *temp = root->LC;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct BTnode *temp = Min(root->RC);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->RC = deleteNode(root->RC, temp->data);
    }
    return root;
}

