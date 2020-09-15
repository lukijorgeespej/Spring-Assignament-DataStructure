#include "NodeStack.h"
#include "UserData.h"
#include <stdlib.h>	

//Constructor
NodeStack::NodeStack(UserData* value, NodeStack* next)
{


	this->value = value;
	this->next = next;
}

//Vacio constructor
NodeStack::NodeStack()
{
	this->value = NULL;
	this->next = NULL;
}


void NodeStack::setNext(NodeStack* node)
{
	next = node;   //Le decimos que tiene al nodo que se pase por parametro
}


void NodeStack::setValue(UserData* v)
{
	value = v;
}

NodeStack* NodeStack::getNext()  
{
	return next;  //Devuelve el nodo entero que le pedimos
}
UserData* NodeStack::getValue()
{
	return value;
}

