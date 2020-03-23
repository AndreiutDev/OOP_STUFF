#pragma once

class node
{
	public:
		int value;
		node* left;
		node* right;
	public:
		node();
};

class Tree
{
	public:
		Tree();
		node* root;
		node* insert(int v, node* tree);
		node* createNewTreeNode(int value);
		node* deleteNode(node* tree, int value);
		void printPostorder(node* node);
		void printInorder(node* node);
		void printPreorder(node* node);
		int countEdges(node* n);
		int countNodes(node* n);
		int FindHeight(node* n);
};

