#include "treeV3.h"

int main()
{

    // Tree myTree;
    // myTree.createTree();

    // // 前序遍历
    // cout << " 前序遍历 : " << endl;
    // myTree.Preorder(myTree.root);
    // cout << endl;

    // cout << " 后序遍历 : " << endl;
    // myTree.Postorder(myTree.root);
    // cout << endl;

    // cout << " 中序遍历 : " << endl;
    // myTree.Inorder(myTree.root);
    // cout << endl;


    // cout << "counting node is " << endl;
    // cout << myTree.countNode(myTree.root) << endl;

    // 二叉树的插入
    Tree myTree;
    // myTree.insertBinary(myTree.root,1);
    // myTree.insertBinary(myTree.root,2);
    // myTree.insertBinary(myTree.root,3);
    // myTree.Inorder(myTree.root);
    // cout << endl;

    myTree.root = myTree.RInsert(myTree.root,10);
    myTree.RInsert(myTree.root, 5);
    myTree.RInsert(myTree.root, 15);
    myTree.RInsert(myTree.root, 3);
    myTree.RInsert(myTree.root, 7);
    myTree.RInsert(myTree.root, 12);
    myTree.Inorder(myTree.root);
    cout << endl;
    cout << "Start Deleting" << endl;
    myTree.deleteBinary(myTree.root,15);
    myTree.Levelorder(myTree.root);
    cout <<endl;
    return 0;
}