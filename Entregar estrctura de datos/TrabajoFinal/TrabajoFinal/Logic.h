#pragma once

#include "Stack.h"
#include "List.h"
#include "Queue.h"
#include "BinaryTree.h"
class Logic {

	int inf;
	int sup;
	Queue aTOz;  //A TO Z
	Queue ZTOa;	//Z TO A
	int idcontador ;
	BinaryTree binarytreeStore;
	Stack numberStack ;//Creamos el stack que guardara los numeros de telefono555
	Stack  recoverStack;//Creamos el stack, donde se almacenaran todos los userdataras del arbol binario
	List recoverList;//Creamos la list, donde se almacenaran todos los userdataras del arbol binario

public:
	Logic();
	
	
	
	
	//OPTION 1

	//CREATE SIMULATION
	void newSimulation();//Ejercicio 1

	//CREATE USERDATA
	UserData* createUserData();
	int createnumberPhone();
	char MMRAssignRoom();
	void increaseCounter();
	
	//CREATE RANDOM NUMBER
	int randomNumber(int inf, int sup); // Numero aleatorio comprendido entre dos numeros

	//STORE NUMBERPHONE 555
	bool number555(int number);
	void numberStackComplete(UserData* userdata);

	//FILL THE QUEUES(RELLENAR COLAS)
	void inicializateQueue();

	//RESULTS SIMULATION
	int getTotalIdCounter();
	Stack getTotalNumber555();
	//---------------------------------------------------------------------------------------------------------------------//

	//OPCION 2
	UserData* searchPhoneNumber(int answer);

	//---------------------------------------------------------------------------------------------------------------------//
	
	//OPCION 3
	UserData* searchIdPhoneNumber(int answer);
	List List100(int id);

	//---------------------------------------------------------------------------------------------------------------------//

	//OPCION 4
	void storedListStack();
	UserData* searchBinaryTree(int Id);
	UserData* searchList(int Id);
	UserData* searchStack(int id);
	
	//OPTION 4  RESULTS
	List getRecoverList();
	Stack getRecoverStack();
	BinaryTree getBinaryTree();
	
};



