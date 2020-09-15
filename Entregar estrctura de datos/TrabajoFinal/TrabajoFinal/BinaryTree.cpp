#include "BinaryTree.h"
#include <iostream>
using namespace std;
BinaryTree::BinaryTree()
{
	this->root = NULL;
	this->contador = 1;
	this->lenght = 0;
}



//OPTION 2
UserData* BinaryTree::search(int numberKeyboard,NodeBinaryTree* node )//
	//Al ser recursivo tenemos que meter un nodo por parámetro para que cuando llamemos a la función SEARCH() se quede con el ultimo nodo que ha leido	
	//Busca los phonenumbers y nos saca el userdata
{
	int cutted;//Cortado

	if (node != NULL)//Si el nodo no esta vacio podemos ejecutar la busqueda
	{
		int phone = node->getValue()->getPhoneNumber();//Sacamos al nodo que le introcimos por parámmetro el telefono para buscarlo
		 cutted = cutNumber(phone, numberKeyboard);//Cortamos el número del nodo al tamaño del número introducido por teclado   Ej:Introducido por teclado->1243, Cortamos los numeros de los nodos  a 4 cifras 

	}
	
	if (node == NULL) //Si el nodo que es el root "en la primera vuelta" esta vacio , se retornada un userdata vacio
	{
		UserData* emptynode = new UserData();
		return emptynode;

	}
	

	

		else if (cutted == numberKeyboard) {//Comprobamos si el valor del nodo cortado es igual que  el int que le metemos

			return node->getValue();//Retornamos el userData con el valor coincidente
		}

		else if (cutted > numberKeyboard) {//Comparamos si el valor del nodo es mayor que el int
			search(numberKeyboard, node->getLeftChild());
		}

		else if (cutted < numberKeyboard) {//Comparamos si el valor del nodo es menor que el int
			search(numberKeyboard, node->getRightChild());
		}


	
	
}

int BinaryTree::cutNumber(int numberNode, int numberSearched) {//Metemos por parametro el numero de telefono de un nodo y el numero introducido por teclado
	string  NodeToString = to_string(numberNode); //Pasamos a String el numero de telefono de un nodo
	string SearchedToString = to_string(numberSearched); //Pasamos a String  el numero introducido por teclado
	int size = SearchedToString.size();	//Calculamos la longitud de el numero introducido por teclado 


	NodeToString = NodeToString.substr(0, size);//Cortamos el numero de telefono de un nodo con la longitud calculada anteriormente. Ej:Introducido por teclado->1243 (4 cifras), Cortamos  numero de telefono de un nodo a 4 cifras 

	int result = stoi(NodeToString);//Pasamos a int el numero de telefono de un nodo, ya que anteriormente lo pasamos a String

	return result; //Retornamos el numero de telefono de un nodo cortado y en formato int
}

//OPTION 3

//PART A OPTION 3
void BinaryTree::searchID(int idKeyboard, NodeBinaryTree* node,UserData* &result )//
		//Con esta función buscaremos el userdata que tenga ese id introducido en el árbol,devolvemos el userdata que lo pasamos por referencia  
	//ya que al hacer return anteriormente nos cogia el ultima valor que se leia
{
	int idphone;

	
	
	if (node != NULL) //Si el nodo que es el root "en la primera vuelta" no esta vacio 
	{
		idphone = node->getValue()->getId();//Cogemos el id que tiene el nodo que le pasamos
		
		if (idphone == idKeyboard) {//Comparamos si los id son iguales, si son iguales "devolvemos" el userdata
			result = node->getValue();
			
			
		}
		//Si no son iguales, buscamos por busqueda lineal ya que la key del arbol son los numeros de telefono

			searchID(idKeyboard, node->getLeftChild(), result);

			searchID(idKeyboard, node->getRightChild(), result);
			
		
	}

}

//PART B OPTION 3
void BinaryTree:: preorderList(int id, NodeBinaryTree* node,List &list) { //Buscamos el id en el arbol binario, hicimos una copia del search id ua que en search id no podemos llamar a preorder
	int idphone;
	if (node != NULL) //Si el nodo que es el root "en la primera vuelta" no esta vacio 
	{
		idphone = node->getValue()->getId();//Cogemos el id que tiene el nodo que le pasamos
		if (idphone == id) {//Comparamos si los id son iguales, si son iguales "devolvemos" el userdata
			
			 preorder(node, list);//LLamamos a la funcion preorder para rellenar una lista con 100 id

		}
		else {//Si no son iguales, buscamos por busqueda lineal ya que la key del arbol son los numeros de telefono

			preorderList(id, node->getLeftChild(), list);

			preorderList(id, node->getRightChild(), list);

		}
	}

}

void BinaryTree::preorder(NodeBinaryTree* node, List& list) { //rellenar una lista con 100 id
	//root,left,right  Ademas metemos un int ya que se pide que busquemos por id

	NodeList* nodeList = new NodeList();

	if (node != NULL) {
		if (list.lengthList() <= 100) {//Como son 100 numeros, se para al tener 100 en la lista
			nodeList->setValue(node->getValue());//Cogemos el valor del nodoBinary y se lo introducimos en el nodo list
			list.insert(nodeList);
			
			preorder(node->getLeftChild(), list);
			preorder(node->getRightChild(), list);
		}


	}


}

//OPTION 4
void BinaryTree::recover(NodeBinaryTree* nodeBinary, List  &recoverList, Stack  &recoverStack) {//Método que ira rellenando la lista y el stack "Opcion 4"

	
	UserData* result = new UserData();
	bool condition=true;

	searchID(contador, nodeBinary, result);//Reutilizamos dicho método, contador seran los id, y dentro del while se ira incrementando. Nos encontrara el userdata con este id que le introducimos
	
	while (condition) {

		
		NodeList* nodeList = new NodeList();
		NodeStack* nodeStack = new NodeStack();
		
		nodeList->setValue(result); //el result (variable global) le vamos sacando a traves del while el userdata y se lo insertamos en la lista y el stack
		recoverList.insert(nodeList);//Inserta Lista
		
		nodeStack->setValue(result);
		recoverStack.push(nodeStack);//Inserta Stack
		
		
		contador = contador + 1;//Este contador sera nuestro id, esta variable esta en el constructor y empieza en 1 ya que los id empiezan en 1

		if (contador == getLenght()) {

			condition = false;//Si  la longitud del binary tree es igual a la longitud del contador entonces eso indica que la lista y el stack estan llenos y ya podemos finalizar el while
		}
		searchID(contador, nodeBinary, result);
	}
	

}

//TOOLS

int BinaryTree::getLenght() {//Nos la la longitud del arbol binario
	return lenght;
}

void BinaryTree::setRoot(NodeBinaryTree* node) {//Esto hace que el node que le pasamos se quede como root 
	if (root == NULL) {//Si el root en nullo, el root va a ser node
		root = node;
	}

}

NodeBinaryTree* BinaryTree::getroot() {//Nos devuelve el root de el árbol


	return root;
}

bool BinaryTree::isLeaf(NodeBinaryTree* node) {//No es recursiva, metemos nodo y comprobamos is tienes hijos o no

	bool variable;
	if (((node->getRightChild()) == NULL) && ((node->getLeftChild()) == NULL))

	{

		variable = false;

	}
	else
	{

		variable = true;

	}
	return variable;
}

NodeBinaryTree* BinaryTree::insert(NodeBinaryTree* node, UserData* variable)

//Al ser recursivo el node de primeras siempre va a ser el root, y luego ya la propia función va abriendo el árbol
{
	int phoneNumber = variable->getPhoneNumber();//
	if (node == NULL) { //Si el nodo esta vacio se retorna el nodo, antes de retornarlo le metemos el userdata
		NodeBinaryTree* node = new NodeBinaryTree(variable);
		lenght = lenght + 1;
		return node;
	}

	else if (node->getValue()->getPhoneNumber() == phoneNumber) {    // En el caso de que tengamos dos nodos con numeros de telefonos iguales, se remplaza el nuevo por anterior
		node->setValue(variable);//Metemos el userdata dentro del nodo, para modificar o remplazar su valor
		return node;

	}

	else if (phoneNumber < node->getValue()->getPhoneNumber()) {//Comprobamos si el numero de letefono del User Data es menor que el numero de telefono del nodo del arbol

		node->setLeftChild(insert(node->getLeftChild(), variable));//Al ser menor, nos dirigimos al hijo izquierdo del nodo y le insertamos el nodo izquierdo y el mismo userdata
		return node;
	}

	else if (phoneNumber > node->getValue()->getPhoneNumber()) {

		node->setRightChild(insert(node->getRightChild(), variable));//Al ser mayor, nos dirigimos al hijo derecho del nodo y le insertamose el nodo derecho y el mismo userdata
		return node;
	}



}