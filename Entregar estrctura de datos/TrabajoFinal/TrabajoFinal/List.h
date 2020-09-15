#pragma once
#include <stdlib.h>	
#include "NodeList.h"
class List {
	
	NodeList* head;
	NodeList* end;
public:
	List();
	
	// TOOLS
	int lengthList();					//Longitud de la lista
	UserData* searchId(int id);			//Buscar Id en la lista

	//INSERT, PREVIOUS,ISEMPTY
	void insert(NodeList* node);		//Inserta un nodo en el head
	NodeList* previous(NodeList* node);   //Devuelve el nodo anterior
	bool isEmpty();    //Nos muestra si la lista esta vacia

	//GETTERS
	NodeList* getHead();				//Devuelve el nodo head
};
