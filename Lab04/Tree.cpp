#include "Tree.h"
#include <iostream>
#include <stdio.h>

node::node()
{

}

Tree::Tree()
{
	root = nullptr;
}
/*
========================================================================
=
=                             INSERTING A NODE                         =
=
========================================================================
*/
node* Tree::insert(int key, node* node)
{
    if (node == NULL)
        return createNewTreeNode(key);
    if (key <= node->value)
        node->left = insert( key, node->left );
    else if (key >= node->value)
        node->right = insert(key, node->right);
    return node;
}
/*
========================================================================
=
=                          RETURNING A POINTER TO A NEW NODE           =
=
========================================================================
*/
node* Tree::createNewTreeNode(int value)
{
	node* temp = new node();
	temp->right = nullptr;
	temp->left = nullptr;
	temp->value = value;
	return temp;
}

/*
========================================================================
=
=                     DELETING A NODE                                  =
=
========================================================================
*/

node* minValueNode(node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

node* Tree::deleteNode(node* root, int key)
{
    //There are three special cases
    if (root == NULL) return root;


    if (key < root->value)
        root->left = deleteNode(root->left, key);
    else if (key > root->value)
        root->right = deleteNode(root->right, key);
    else
    {
        // case 1: if it has only a right child, delete the current node and link
        //         the right child to the parent node
        if (root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            // case 2: if it has only a left child, delete the current node and link
            //         the left child to the parent node
            node* temp = root->left;
            free(root);
            return temp;
        }
        // case 3: the node has two children, search the min value of the right branch
        //         and copy it in the current node
        node* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

void Tree::printPostorder(node* node)
{
    if (node == NULL)
        return ;
    printPostorder(node->left);
    printPostorder(node->right);
    std::cout << node->value << " ";
}

void Tree::printInorder(node* node)
{
    if (node == NULL)
        return ;
    printInorder(node->left);
    std::cout << node->value << " ";
    printInorder(node->right);
}

void Tree::printPreorder(node* node)
{
    if (node == NULL)
        return ;
    std::cout << node->value << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
//COUNTS THE NUMBER OF THE NODES
int Tree::countNodes(node *n)
{
    int count = 1;
    if (n == nullptr)
        return 0;
    else
    {
        count += countNodes(n->left);
        count += countNodes(n->right);
    }
    return count;
}
//COUNTS THE NUMBER OF THE EDGES
int Tree::countEdges(node* n)
{
    return countNodes(n) - 1;
}
//THE MAX BETWEEN 2 NUMBERS
int max(int a, int b)
{
    if (a < b)
        return b;
    return a;
}
//THE HEIGHT OF A TREE
int Tree::FindHeight(node *n)
{
    if (n == NULL)
        return -1;
    return max(FindHeight(n->left), FindHeight(n->right)) + 1;
}

int main()
{
    printf("              5          \n");
    printf("           /     \        \n");
    printf("          3      7      \n");
    printf("        /  \    /  \    \n");
    printf("       2   4    6    8  \n");

    Tree tree_root;
	tree_root.root = tree_root.insert(50, tree_root.root);
	tree_root.insert(30, tree_root.root);
	tree_root.insert(20, tree_root.root);
	tree_root.insert(40, tree_root.root);
	tree_root.insert(70, tree_root.root);
	tree_root.insert(60, tree_root.root);
	tree_root.insert(80, tree_root.root);
    tree_root.printInorder(tree_root.root);
    printf("\nThe number of nodes from this tree: \n");
    printf("\n%d \n", tree_root.countNodes(tree_root.root));
    printf("\nThe number of edges from this tree: \n");
    printf("\n%d \n", tree_root.countEdges(tree_root.root));
    printf("\nThe height of the tree: \n");
    printf("\n%d \n", tree_root.FindHeight(tree_root.root));
    return 0;
}