#pragma once
#include "NodeStack.h"
#include <stdlib.h>	

class Stack 
{
	NodeStack* top;     //Introducimos var<iable top
	int lenght;

public:
	Stack();

	
	//TOOLS
	UserData* searchId(int id, Stack& recoverStack);
	
	//PUSH,POP,EMPTY
	void push(NodeStack* node); //Meter node en el stack, se mete el primero
	UserData* pop();			//Sacar el primero del stack
	bool isEmpty();				//Si esta vacio o no

	//GETTERS
	UserData* getTop();		//Me devuelve el userdata del top
	NodeStack* getTopOfStack(); //Primer nodo
	int getlenght();
};