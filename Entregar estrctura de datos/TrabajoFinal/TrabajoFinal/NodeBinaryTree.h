#pragma once
#include "UserData.h"
#include <stdlib.h>	

class NodeBinaryTree {
	//CADA NODO tiene un padre, y o un hijo o dos hijos
	NodeBinaryTree* parent;			//Padre
	NodeBinaryTree* leftchild;		//Hijo hizquierdo
	NodeBinaryTree* rightchild;		//Hijo derecho
	UserData* value;				//Value de tio UserData


public:

	NodeBinaryTree(UserData* value);
	//Al constructor solo le metemos el value ya que al principio no es necesario decirle que tiene un padre , o hijos, m�s tarde 
	//le diremos cuales son sus hijos(porque el insert lo hace automaticamente seg�n nuestro c�digo)

	NodeBinaryTree();//Constructor Vacio

	NodeBinaryTree* getParent();
	NodeBinaryTree* getLeftChild();
	NodeBinaryTree* getRightChild();
	UserData* getValue();

	void setValue(UserData* valor);
	void setLeftChild(NodeBinaryTree* nod);
	void setRightChild(NodeBinaryTree* nod);
};