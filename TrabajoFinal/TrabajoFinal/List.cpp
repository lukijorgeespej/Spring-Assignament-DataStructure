
#include "List.h"
#include <iostream>
using namespace std;



	List::List()//Constructor
	{
		
		this->head = NULL; 
		this->end = head;
	}

	
	
	// TOOLS
	int List::lengthList()
	{
		int contador = 0;
		if (isEmpty()) {
			contador = 0;

		}
		else
		{

			NodeList* variable;
			variable = head;
			while (variable != NULL) {
				contador = contador + 1;
				variable = variable->getNext();

			}
		}

		return contador;
	}

	UserData* List::searchId(int id) {
		UserData* userdata = new UserData();
		NodeList* nodo = new NodeList();
		nodo = head;
		while (nodo->getNext() != NULL) {

			if (nodo->getValue()->getId() == id) {
				userdata = nodo->getValue();
				return userdata;
			}

			nodo = nodo->getNext();

		}
	}
	
	

	//INSERT, PREVIOUS,ISEMPTY
	void List::insert(NodeList* node)  //Se inserta en el head
	{
		

		if (isEmpty()) {
			head = node;
			
			
			
			
		}
		else {
			
			 node->setNext(head);
			 
			 head = node;
			 
			 
			
		}
	}

	NodeList* List::previous(NodeList* node)
	{
		NodeList* variable = head;
		if (isEmpty()) {

			variable = NULL;
		}
		else {

			while (variable->getNext() != node && variable->getNext() != NULL) {

				variable = variable->getNext();
			}

		}
		return variable;
	}

	bool List::isEmpty()
	{
		bool variable;
		if (head == NULL) {

			variable = true;
		}
		else {

			variable = false;

		}

		return variable;
	}


	//GETTERS
	NodeList* List::getHead()
	{
		return head;
	}

	

	

	