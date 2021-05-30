//Binary tree operations.
//A.Harichandana, Roll no-100519733001,CSE Third SEM.
#include <iostream>
using namespace std;
struct BTNode
{
    int data;
    BTNode *LC, *RC;

    BTNode(int data)
    {
        this->data = data;
        this->LC = this->RC = nullptr;
    }
};
void deleteBinaryTree(BTNode* &root)
{
    if (root == nullptr) {
        return;
    }

    deleteBinaryTree(root->LC);
    deleteBinaryTree(root->RC);
    delete root;
    root = nullptr;
}

int main()
{
    BTNode* root = nullptr;

    root = new BTNode(1);
    root->LC = new BTNode(2);
    root->RC = new BTNode(3);
    root->LC->LC = new BTNode(4);
    root->LC->RC = new BTNode(5);
    root->RC->LC = new BTNode(6);
    root->RC->RC = new BTNode(7);

    // delete the entire tree
    deleteBinaryTree(root);

    if (root == nullptr) {
        cout << "Tree Successfully Deleted";
    }

    return 0;
}
