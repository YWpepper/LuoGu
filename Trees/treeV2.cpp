#include "treeV2.h"

int main()
{

    Tree myTree;
    myTree.createTree();

    // 前序遍历
    cout << " 前序遍历 : " << endl;
    myTree.Preorder(myTree.root);
    cout << endl;

    cout << " 后序遍历 : " << endl;
    myTree.Postorder(myTree.root);
    cout << endl;

    cout << " 中序遍历 : " << endl;
    myTree.Inorder(myTree.root);
    cout << endl;

    return 0;
}