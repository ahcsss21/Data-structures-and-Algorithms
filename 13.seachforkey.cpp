//search for key in Binary tree.
//A.Harichandana, Roll no-100519733001,CSE Third SEM.
#include <iostream>
using namespace std;
struct BTNode {
    int data;
    struct BTNode *LC, *RC;
    BTNode(int data)
    {
        this->data = data;
        LC = RC = NULL;
    }
};
bool ifNodeExists(struct BTNode* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    bool res1 = ifNodeExists(root->LC, key);
    if(res1) return true;
    bool res2 = ifNodeExists(root->RC, key);

    return res2;
}

int main()
{
    struct BTNode* root = new BTNode(1);
    root->LC = new BTNode(2);
    root->LC->LC = new BTNode(3);
    root->LC->LC->LC = new BTNode(4);
    root->LC->RC= new BTNode(5);
    root->LC->RC->LC = new BTNode(6);
    root->LC->RC->RC = new BTNode(7);
    root->RC = new BTNode(8);
    root->RC->LC = new BTNode(9);
    root->RC->RC = new BTNode(10);

    int key = 12;

    if (ifNodeExists(root, key))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
