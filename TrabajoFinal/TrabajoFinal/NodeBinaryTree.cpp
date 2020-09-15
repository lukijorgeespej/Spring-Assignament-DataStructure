#include "NodeBinaryTree.h"


NodeBinaryTree::NodeBinaryTree(UserData* value) 
{
	this->parent = NULL;
	this->leftchild = NULL;
	this->rightchild = NULL;
	
	this->value = value;
}

NodeBinaryTree::NodeBinaryTree()     //Constructor Vacio
{
	this->parent = NULL;
	this->leftchild = NULL;
	this->rightchild = NULL;
	this->value = NULL;
}

NodeBinaryTree* NodeBinaryTree::getParent() {


	return parent;

}
NodeBinaryTree* NodeBinaryTree::getLeftChild() {

	return leftchild;

}
NodeBinaryTree* NodeBinaryTree::getRightChild() {

	return rightchild;
}
UserData* NodeBinaryTree::getValue() {

	return value ;

}

void NodeBinaryTree::setValue(UserData* valor) {

	value = valor;
}

void NodeBinaryTree::setLeftChild(NodeBinaryTree* nod) {

		leftchild = nod;

}
void NodeBinaryTree::setRightChild(NodeBinaryTree* nod) {

		rightchild =nod;

}
