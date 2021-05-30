//Mirror image of Btree.
//M.sreeja Rollno:100519733024
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
void mirrorimage(struct BTnode* root)
{
  if (root != NULL)
    {
        struct BTnode* temp;
        mirrorimage(root->LC);
        mirrorimage(root->RC);
        temp = root->LC;
        root->LC  = root->RC;
        root->RC = temp;

    }
}

int heightoftree(struct BTnode* root)
{
    int max;

    if (root!=NULL)
    {
        /*Finding the height of left subtree.*/
        int leftsubtree = heightoftree(root->LC);

        /*Finding the height of right subtree.*/
        int rightsubtree = heightoftree(root->RC);


        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}

/*
 * Function to print all the nodes left to right of the current level
 */

void currentlevel(struct BTnode* root, int level)
{
    if (root != NULL)
    {
        if (level == 1)
        {
            printf("%d ", root->data);
        }

        else if (level > 1)
        {
            currentlevel(root->LC, level-1);
            currentlevel(root->RC, level-1);
        }
    }

}

int main()
{
   /* Creating first Tree.*/

    struct BTnode *root = new BTnode(1);
    root->LC = new BTnode(2);
    root->RC = new BTnode(3);
    root->LC->LC = new BTnode(4);
    root->LC->RC = new BTnode(5);
    root->RC->LC = new BTnode(6);
    root->RC->RC = new BTnode(7);


    printf("Level Order Traversal of Tree 1 "
           "before creating its mirror image is \n");

    int i;
    int height = heightoftree(root);

    /* calling current level function, by passing levels one by one
     * in an increasing order.
     */

    for(i = 1; i <= height; i++)
    {
        currentlevel(root,i);
    }
    printf("\n\nLevel Order Traversal of Tree 1 "
               "after creating its mirror image is \n");


    height = heightoftree(root);
    mirrorimage(root);

   /* calling current level function, by passing levels one by one
    * in an increasing order.
    */

    for(i = 1; i <= height; i++)
    {
        currentlevel(root,i);
    }

}


