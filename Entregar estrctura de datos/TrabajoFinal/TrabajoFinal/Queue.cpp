#include "Queue.h"
#include <stdio.h> 
#include <iostream> 



using namespace std;

Queue::Queue() //Constructor
{
	this->front = NULL;
	this->rear = NULL;
}

//ENQUEUES
void Queue::enqueue(char letter) //Mete char
{
	NodeQueue* node =  new NodeQueue(letter,NULL);
	
	
	
	if (rear )  //Si el rear  es nullo,NO ENTRA EN EL IF
	{
		rear->setNext(node);
	}
	rear = node;
	if (!front)//Si el front  NO es nullo NO ENTRA
	{
		front = node;
	}
}

void Queue::enqueue(int value) //Mete int
{
	NodeQueue* node = new NodeQueue(value, NULL);



	if (rear)  //Si el rear  es nullo,NO ENTRA EN EL IF
	{
		rear->setNext(node);
	}
	rear = node;
	if (!front)//Si el front  NO es nullo NO ENTRA
	{
		front = node;
	}
}


// DEQUEUES
char Queue::dequeueChar()
{
	NodeQueue* variable = new NodeQueue();
	variable = front;
	char final;


	if (variable==NULL)//Si variable es nullo,  entra en el if
	{   
		return 0;

	}
		
	//Si no esta vacio
		
	front = front->getNext();//Al sacar el front tenemos que volver a asginarle a la queue un nuevo front, que sera el sigueinte nodo
	 
	final=variable->getLetter();
	delete variable;
		
	if (front == NULL) {//Este if hace que si hemos sacado el ultimo nodo, debemmos asignarle null al rear
		rear = NULL;
	}


	return final;
	
}

int Queue::dequeueInt()
{
	NodeQueue* variable = new NodeQueue();
	variable = front;
	int final;


	if (variable == NULL)//Si variable es nullo,  entra en el if
	{
		return 0;

	}

	//Si no esta vacio

	front = front->getNext();//Al sacar el front tenemos que volver a asginarle a la queue un nuevo front, que sera el sigueinte nodo

	final = variable->getValue();
	delete variable;

	if (front == NULL) {//Este if hace que si hemos sacado el ultimo nodo, debemmos asignarle null al rear
		rear = NULL;
	}


	return final;

}


//FRONTS 
int Queue::frontint()
{
	int variable;
	if (isEmpty()) {
		variable = -1;
	}
	else{
		variable = front->getValue();

	}
	return variable;
}

char Queue::frontchar()
{
	char variable;
	if (isEmpty()) {
		variable = NULL;
	}
	else {
		variable = front->getLetter();

	}
	return variable;
}


bool Queue::isEmpty()
{
	bool variable;
	if (front==NULL ) {

		variable = true;
	}
	else {

		variable = false;
	}
	return variable;
}

int Queue::lenghtQueue()
{
	int contador = 0;
	NodeQueue* recorrer;
	recorrer = front;
	while (recorrer != NULL) {
		contador = contador + 1;
		recorrer = recorrer->getNext();
	}
	return contador;
}