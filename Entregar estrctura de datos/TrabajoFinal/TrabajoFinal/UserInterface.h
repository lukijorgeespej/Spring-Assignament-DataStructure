#pragma once
#include "Stack.h"
#include "List.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "Logic.h"
#include <string>
#include <time.h>

class UserInterface {
	Logic logic;
public:
	UserInterface();
	//(Recogida y ejecuci�n de la opci�n del usuario)
	void printMenu();
	void readOption();   //Usuario elige la opci�n del a 1 al 6 (6->Salir del programa)
	void executeOption(int option);   //Ejecuta la opci�n seleccionada

	//OPCION 1
	void StartSimulation();//Empieza la simulaci�n

	//OPTION 2
	void searchPhone();
	
	//OPTION 3
	void searchPhoneID();

	//OPTION 4
	void recoverListStack();

	//OPTION 5
	void print555();

	//PRINTERS
	void printList(List list);
	void printStack(Stack nodestack);
	void printUserData(UserData* userData);
	

	

};