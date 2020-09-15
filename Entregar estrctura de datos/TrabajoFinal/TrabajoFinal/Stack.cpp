#include "Stack.h"
#include <iostream>


using namespace std;
Stack::Stack() {

	this->top = NULL;   //De origen el top es nullo, ya que esta vacio
	this->lenght = 0;
}



//TOOLS
UserData* Stack::searchId(int id, Stack& recoverStack) {

	Stack copy = Stack();//Stack donde se  guardaran todos  los nodos que no condidan con el id que metemos
	UserData* result = new UserData();

	while (!recoverStack.isEmpty()) {//Mientras el stack(este stack siempre estara completo) no este vacio

		UserData* ud = recoverStack.pop();//Sacamos del stack el userdata
		NodeStack* node = new NodeStack(ud, NULL);//Metemos al nodo el userdata 
		if (ud->getId() == id) {//Si el id = que el id pasado por parametro

			result = ud;//Igualamos los userdatas
			copy.push(node);//Puseamos el nodo que buscamos en la copia, ya que al llamar a la función otra vez tenemos que tener el stack completo (stack original)


			while (!copy.isEmpty()) {//Mientras el stack  no este vacio

				NodeStack* n = new NodeStack(copy.pop(), NULL);//Sacamos todos   nodos de la copia 
				recoverStack.push(n);//Y los metemos en el stack
			}
			return result;
		}
		else {

			copy.push(node);//Todos quellos nodos que no son los que buscamos, se meten en la copia
		}
	}
}


//PUSH,POP,EMPTY
void Stack::push(NodeStack* node) //Meter node en el stack, se mete el primero
{
	if (isEmpty()) {  //Si esta vacio
		
		this->top = node;
		
	}
	else {//Si no esta vacio
		
		node->setNext(top); //Le decimos al nodo que vamos a introducir que apunte al top anterior
		
		this->top = node;  //Y luego al nodo que acabamos de introducir le asignamos el valor top
	}
	lenght++;//Al ir insertando la longitud de del stack amplia
}

UserData* Stack::pop() {

	NodeStack* n;
	UserData* ud;

	if (isEmpty())//Si esta vacio
	{
		n = NULL;
		ud = new  UserData();//devuelve  el userdata vacio
		
	}
	else
	{
		lenght--;
		n = top; //nodo=top
		top = n->getNext();// hacemos que el top sea el siguente nodo
		ud = n->getValue();//le damos el valor del userdata del nodo al ud
		delete n;
		
	}
	return ud;

}

bool Stack::isEmpty()				//Si esta vacio o no
{
	bool variable;
	if (top==NULL) {  //Si el top es nullo, significa que el stack esta vacio y por lo tanto se cumple

		variable = true;
	}
	
	else {
		variable = false;
	}
		
	return variable;
	
}


//GETTERS
UserData* Stack::getTop()		//Me devuelve el userdata del top
{
	return top->getValue(); //Le decimos que coga el valor del top y te lo retorne

}

NodeStack* Stack::getTopOfStack()//Primer nodo
{
	return top;
}

int Stack::getlenght() {


	return lenght;

}



