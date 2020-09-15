#pragma once
//#ifndef NODESTACK_HPP    //Librerias N
//#define NODESTACK_HPP
#include <stdlib.h>		//Para imprimir, o para poner Strings
#include "UserData.h"


class NodeStack
{
	UserData* value;
	NodeStack* next;	//El * Define si es memoria dinámica
public:
	NodeStack(UserData* value, NodeStack* next);   //Constructor 
	NodeStack();       //Constructor Vacio
	
	void setNext(NodeStack* node);			//Indicar cual va ser el siguiente nodo, le dices a quien tiene que apuntar
	void setValue(UserData* v);  //Le metemos el valor

	NodeStack* getNext();
	UserData* getValue();
	
};


