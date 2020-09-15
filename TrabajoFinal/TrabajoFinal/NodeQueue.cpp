#include "NodeQueue.h"

NodeQueue::NodeQueue(char letter,NodeQueue* next)   //Constructor  Letras
{
	this->letter = letter;
	this->next = next;
	
}

NodeQueue::NodeQueue(int value, NodeQueue* next)   //Constructor  Letras
{
	this->value = value;
	this->next = next;



}

NodeQueue::NodeQueue()        //Constructor Vacio
{
	this->value = NULL;
	this->next = NULL;
	this->letter = NULL;
}

void NodeQueue::setNext(NodeQueue* node)			//Indicar cual va ser el siguiente nodo, le dices a quien tiene que apuntar
{
	next = node;
}
void NodeQueue::setLetter(char letter)
{
	letter = letter;

}
void NodeQueue::setValue(int value)  //Le metemos el valor{
{
	value = value;
}

NodeQueue* NodeQueue::getNext() {

	return next;
}
int NodeQueue::getValue() {

	return value ;
}
char NodeQueue::getLetter() {

	return  letter;
}

