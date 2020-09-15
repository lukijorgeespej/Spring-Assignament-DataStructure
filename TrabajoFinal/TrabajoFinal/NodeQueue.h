#include <stdlib.h>		//Para imprimir, o para poner Strings

class NodeQueue
{
	int value = 0;;     //Hay colas de numeros y colas de letras, cuando se utilice la cola de numeros pondremos a null las letras
	char letter='a';
	NodeQueue* next;	//El * Define si es memoria dinámica
public:
	NodeQueue(char letter,NodeQueue* next);   //Constructor letras
	NodeQueue(int value, NodeQueue* next);   //Constructor numeros
	NodeQueue();       //Constructor Vacio

	void setNext(NodeQueue* node);			//Indicar cual va ser el siguiente nodo, le dices a quien tiene que apuntar
	void setLetter(char letter);
	void setValue(int value);  //Le metemos el valor

	NodeQueue* getNext();
	int getValue();
	char getLetter();
};

 



