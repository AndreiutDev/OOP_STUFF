#include <iostream>
#include "Tree.h"
#include "Node.h"

Tree CreateTree() {

	Tree tree = Tree(20);

	tree.InsertNode(18);
	tree.InsertNode(12);
	tree.InsertNode(10);
	tree.InsertNode(7);
	tree.InsertNode(25);
	tree.InsertNode(35);
	tree.InsertNode(21);
	tree.InsertNode(22);
	tree.InsertNode(29);
	return tree;
}

void CountNodes(Tree tree) {
	std::cout << '\n';
	std::cout << "Nodes: " << tree.CountNodes();
}

void CountEdges(Tree tree) {
	std::cout << '\n';
	std::cout << "Edges: " << tree.CountEdges();
}

void Height(Tree tree) {
	std::cout << '\n';
	std::cout << "Height: " << tree.ShowHeight();
}

void PreOrder(Tree tree) {
	std::cout << '\n';
	std::string s = "Preorder: ";
	s += tree.PreOrder();
	std::cout << s;
}

void InOrder(Tree tree) {
	std::cout << '\n';
	std::string s = "Inorder: ";
	s += tree.InOrder();
	std::cout << s;
}

void PostOrder(Tree tree) {
	std::cout << '\n';
	std::string s = "Postorder: ";
	s += tree.PostOrder();
	std::cout << s;
}



int main()
{
	std::cout << "Lab3!";

	Tree tree;

	tree = CreateTree();
	CountNodes(tree);
	CountEdges(tree);
	Height(tree);
	PreOrder(tree);
	InOrder(tree);
	PostOrder(tree);
}
