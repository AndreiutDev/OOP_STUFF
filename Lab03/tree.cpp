#include "Tree.h"
#include <exception>


Tree::Tree()
{
}

Tree::Tree(int value)
{
	this->root = CreateTreeNode(value);
}

Node* Tree::GetRoot() {
	return this->root;
}

std::string Tree::PostOrder()
{
	std::string s = "";
	s = this->PostOrderPriv(root, s);
	return s;
}

std::string Tree::InOrder()
{
	std::string s = "";
	s = this->InOrderPriv(this->root, s);
	return s;
}

std::string Tree::PreOrder()
{
	std::string s = "";
	s = this->PreOrderPriv(this->root, s);
	return s;
}

Node* Tree::minValue(Node* node) {
	struct Node* current = node;
	while (current != NULL && current->left != NULL) {
		current = current->left;
	}
	return current;
}

Node* Tree::CreateTreeNode(int value) {
	/*
		Creaing a new Node
		and return it!=> functie e de tip Node*
	*/
	Node* temp = new Node();
	temp->left = nullptr;
	temp->right = nullptr;
	temp->info = value;

	return temp;
}

Node* Tree::Insert(int value, Node* node) {

	if (node == NULL) {
		return CreateTreeNode(value);
	}

	if (value < node->info) {
		node->left = Insert(value, node->left);
	}
	else if (value > node->info) {
		node->right = Insert(value, node->right);
	}
	return node;
}

void Tree::InsertNode(int value) {
	Node* node = this->Insert(value, this->root);
}

Node* Tree::Delete(Node* root, int key) {


	if (root == nullptr) {
		return root;
	}

	//pana se ajunge in capete
	if (key < root->info) {
		root->left = Delete(root->left, key);
	}
	else if (key > root->info) {
		root->right = Delete(root->right, key);
	}
	else {
		//cand se gaseste key-ul
		if (root->left == nullptr) {
			Node* temp = root->right;
			delete root; //free
			return temp;

		}
		else if (root->right == nullptr) {
			Node* temp = root->left;
			delete root;
			return temp;
		}

		//Daca Nodul respectiv are ambii fii trebuie sa se
		//stie care detine valoarea mai mica
		Node* temp = this->minValue(root->right);
		root->info = temp->info;
		root->right = Delete(root->right, temp->info);

	}

	return root;
}

std::string Tree::PostOrderPriv(Node* node, std::string s)
{
	if (node->left != nullptr)
		s = InOrderPriv(node->left, s);
	if (node->right != nullptr)
		s = InOrderPriv(node->right, s);
	s = s + " " + std::to_string(node->info);
	return s;
}

std::string Tree::InOrderPriv(Node* node, std::string s)
{
	if (node->left != nullptr)
		s = InOrderPriv(node->left, s);
	s = s + " " + std::to_string(node->info);
	if (node->right != nullptr)
		s = InOrderPriv(node->right, s);
	return s;
}

std::string Tree::PreOrderPriv(Node* node, std::string s)
{
	s = s + " " + std::to_string(node->info);
	if (node->left != nullptr)
		s = InOrderPriv(node->left, s);
	if (node->right != nullptr)
		s = InOrderPriv(node->right, s);
	return s;
}

int Tree::Nodes(Node* node)
{//contorizeaza nr de noduri
	int count = 1;
	if (node == nullptr)
		return 0;
	else
	{
		count += Nodes(node->left);
		count += Nodes(node->right);
	}
	return count;
}

int Tree::CountNodes() {
	return this->Nodes(this->root);
}

int Tree::Edges(Node* node)
{//returneaza nr de margini
	return Nodes(node) - 1;
}

int Tree::CountEdges() {
	return this->Edges(this->root);
}

int max(int a, int b)
{
	if (a < b)
		return b;
	return a;
}

int Tree::Height(Node* node)
{//returneaza inaltimea lui Tree
	if (node == NULL)
		return -1;
	return max(Height(node->left), Height(node->right)) + 1;
}

int Tree::ShowHeight() {
	return this->Height(this->root);
}

Tree::~Tree()
{

}
