#pragma once
#include "NodeQueue.h"
#include <stdlib.h>	

class Queue {

	NodeQueue* front;
	NodeQueue* rear;

public:
	Queue();

	//ENQUEUES
	void enqueue(char letter);//Meter char
	void enqueue(int value);//Meter int

	// DEQUEUES
	char dequeueChar();
	int dequeueInt();

	//FRONTS 
	int frontint();
	char frontchar();

	//TOOLS
	bool isEmpty();
	int lenghtQueue();





};