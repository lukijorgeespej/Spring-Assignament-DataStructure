#include "NodeList.h"
#include <stdlib.h>	



NodeList::NodeList(UserData* value, NodeList* next)  //Constructor
{

	this->value = value;
	this->next = next;

}
NodeList::NodeList()//Constructor Vacio
{

	this->next = NULL;
	this->value = NULL;
	

}

void NodeList::setNext(NodeList* node)			//Indicar cual va ser el siguiente nodo, le dices a quien tiene que apuntar
{


	next = node;


}
void NodeList::setValue(UserData* valor)			//Le metemos el valor
{


	value = valor;


}

NodeList* NodeList::getNext()
{

	return next;

}
UserData* NodeList::getValue()
{
	return value;

}


