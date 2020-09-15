#pragma once
#include "NodeBinaryTree.h"
#include "List.h"
#include "Stack.h"
#include <stdlib.h>	
#include <string>

class BinaryTree {


	NodeBinaryTree* root;
	int contador;
	int lenght; //Longitud binary tree

public:

	BinaryTree();

	//OPTION 2
	void searchID(int numberKeyboard, NodeBinaryTree* node, UserData*& result);
	int cutNumber(int numberNode, int numberSearched);

	//OPTION 3

	//PART A OPTION 3
	UserData* search(int value, NodeBinaryTree* node);//Le pasamos el numero de teléfono y nos saca la habitación donde esta el usuario.

	//PART B OPTION 3
	void preorderList(int id, NodeBinaryTree* node, List& list);
	void preorder(NodeBinaryTree* node, List& list);  //root,left,right

	//OPTION 4
	void recover(NodeBinaryTree* node, List& recoverList, Stack& recoverStack);

	//TOOLS
	int getLenght();
	void setRoot(NodeBinaryTree* node);
	NodeBinaryTree* getroot();
	bool isLeaf(NodeBinaryTree* node);   //No tiene hijos
	NodeBinaryTree* insert(NodeBinaryTree* node, UserData* variable);

	
	
	
	
};



