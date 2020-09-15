#pragma once
#include"UserData.h"
#include <stdlib.h>	
class NodeList {

	UserData* value;
	NodeList* next;



public:
	NodeList(UserData* value, NodeList* next);   //Constructor
	NodeList();//Constructor Vacio

	void setNext(NodeList* node);			//Indicar cual va ser el siguiente nodo, le dices a quien tiene que apuntar
	void setValue(UserData* value);			//Le metemos el valor

	NodeList* getNext();
	UserData* getValue();

};