#include "Logic.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Logic::Logic() {
	this->inf=10000;		//inferior
	this->sup=50000;		//superior
	this->aTOz;  //A TO Z Q1
	this->ZTOa;	//Z TO A Q2  

	this->idcontador = 1;//UserData counter que sirve para saber cuantos id hay que hacer
	this->binarytreeStore;//binary tree que rellenamos desde el principio
	this->numberStack  ;//Creamos el stack de 555
	this->recoverStack;//Creamos el stack, donde se almacenaran todos los userdataras del arbol binario
	this->recoverList;//Creamos la lista, lista donde se almacenaran todos los userdataras del arbol binario
	inicializateQueue();//Rellenamos las colas ZTOa y aTOz
}

//OPTION 1

//CREATE SIMULATION
void Logic::newSimulation()				//Ejercicio 1
{
	int UserDataTotal = randomNumber(inf, sup);//Creamos entre 10000 y 50000 user datas

	UserData* userData = new UserData();

	for (int i = 0; i < UserDataTotal; i++) { //el numero que salga en el Random, sera el número de veces qeu se ejecute la llamada a create UserDate. 


		userData = createUserData();

		binarytreeStore.setRoot(binarytreeStore.insert(binarytreeStore.getroot(), userData));//Metemos en el arbol binario el nodo  que sera root y el user data
		
	}


}



//CREATE USERDATA
UserData* Logic::createUserData() {

	bool numberPhoneStack = false;
	int numberphone = createnumberPhone(); //Creamos un número de teléfono
	numberPhoneStack = number555(numberphone);//Llamamos a la función que nos retortnada un true o un false dependiendo si el número empieza por 555 o no



	char MMR = MMRAssignRoom();//Creamos un MMR
	 

	UserData* userData = new UserData(numberphone, MMR, idcontador);
	increaseCounter();//CREAMOS id
	if (numberPhoneStack == true) {//Comprobamos si los 3 primeros números son 555

		numberStackComplete(userData);//Mandamos dicho número a la función stack formado por nodos que contienes numeros

	}
	return userData;

}

int Logic::createnumberPhone() {//Genera 1 número de telefono aleatorios del 0 al 9


	string finalString = "";

	int completeNumber;//Este lo utilizaremos para meter el string de nuevo al int con el numero entero

	for (int contador = 0; contador < 9; contador++) { //Este for genera un solo móvil
		int numberphone;
		if (contador == 0) {//El primer numero de telefono no puede ser 0 
			numberphone = randomNumber(1, 9);
		}
		else {
			numberphone = randomNumber(0, 9);
		}

		string numberString; //Creamos el string donde se van a almacenar cada número
		stringstream intToString;	// Creamos el stringstream para modificar el int



		intToString << numberphone;//Metemos el int en el stringstream
		intToString >> numberString;//y se va relleando el string

		finalString = finalString + numberString; //Juntamos cada string

	}


	stringstream stringToInt(finalString);//String to int
	stringToInt >> completeNumber;//Int con numero de telefono completo


	return completeNumber;
}

char Logic::MMRAssignRoom() {
	char result;//Letra que vamos a devolver

	bool aTOzChoosen = false;   //Creamos un booleano para saber que cola tiene el choosenqueue

	Queue choosenQueue = Queue();  //Queue elegida por el random 
	Queue noChoosenQueue = Queue();  //Queue no elegida por el random
	int porcent = randomNumber(1, 100);//Porcentaje para ver que letra saca de las 2 queue

	if (porcent <= 40) {// porcentaje maximo del 40%
		result = aTOz.dequeueChar(); //Guardamos la letra de la queue elegida en el char resultado 
		choosenQueue = aTOz;   //Aqui lo que hacemos es si sale elegida la q1 por el random, guardamos la cola elegida en la variable 
		noChoosenQueue = ZTOa; //La cola no elegida en la otra variable
		aTOzChoosen = true;//Ha cogido la cola A to Z
	}
	else {				// porcentaje 60%
		result = ZTOa.dequeueChar();
		choosenQueue = ZTOa;
		noChoosenQueue = aTOz;
	}

	porcent = randomNumber(1, 100);//Porcentaje para ver en que queue mete la letra
	if (porcent <= 30) {//Si el porcentaje es de 30 como maximo, se guardara en la otra cola

		int lenghtQueueNoOriginal = noChoosenQueue.lenghtQueue() / 2;//Metemos la longitud DIVIDIDA ENTRE DOS de la cola no original en la variable, 
		//YA QUE-> si la longitud de la cola original es menor de la mitad de la cola no original, entonces debemos meter la letra en la cola original

		int lenghtQueueOriginal = choosenQueue.lenghtQueue();//Metemos la longitud de la cola original en la variable

		if (lenghtQueueOriginal < lenghtQueueNoOriginal) {//si la longitud de la cola original es menor de la mitad de la cola no original, entonces debemos meter la letra en la cola original
			choosenQueue.enqueue(result);//Metemos la letra en la cola original

		}
		else {
			noChoosenQueue.enqueue(result);//Metemos en la cola copia (noChoosenQueue) la letra 

		}

	}
	else {//Si el porcentaje es de 70 , se guardara en la cola original(misma cola)
		choosenQueue.enqueue(result);
	}



	if (aTOzChoosen == true) {
		aTOz = choosenQueue;
		ZTOa = noChoosenQueue;


	}
	else {

		ZTOa = choosenQueue;
		aTOz = noChoosenQueue;

	}





	return result;
}

void Logic::increaseCounter() {//Esta  función se encarga de incrementar el contador, sera id counter(contador id)

	idcontador++;


}



//CREATE RANDOM NUMBER
int Logic::randomNumber(int inf, int sup)// Numero aleatorio comprendido entre dos numeros
{

	int random = (rand() % (sup-inf)+1) + inf;	//Creando el numero aleatorio,%=modulo, (sup-inf)+1= 40.001, de 40.001 a 1 y luego le suma 10.000 al resultado

	
	return random;
}



//STORE NUMBERPHONE 555
bool Logic::number555(int number) {//Nos dice si el numero es 555 o no
	bool variable = false;
	string numberString;		//Creamos el string donde se van a almacenar cada número
	stringstream intToString;	// Creamos el stringstream para modificar el int
	int contador555 = 0;//sirve para verificar si los 3 primeros numeros son 555


	intToString << number;//Metemos el int en el stringstream
	intToString >> numberString;//y se rellena el string



	for (int i = 0; i < 3; i++) {//Si  los 3 primeros char son 5

		if (numberString[i] == '5' && i == 0 || numberString[i] == '5' && i == 1 || numberString[i] == '5' && i == 2) {

			contador555 = contador555 + 1;

		}

	}
	if (contador555 == 3) {

		variable = true;
	}

	return variable;

}

void  Logic::numberStackComplete(UserData* userdata) {


	NodeStack* node = new NodeStack();//Creamos el Node Stack para introducirle userdatas

	node->setValue(userdata);//Metemos el numero en el nodo

	numberStack.push(node);//Metemos el node en el stack



}



//FILL THE QUEUES(RELLENAR COLAS)
void Logic::inicializateQueue() {//Rellenar las colas, de la A a la Z y Viceversa

	char alfabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };//Array que contiene el alfabeto entero
	char aleman = 'h';
	NodeQueue* node = new NodeQueue();
	for (int contador = 0; contador < 26; contador++) {		//Este for pone una cola de la A a la Z
		aTOz.enqueue(alfabet[contador]); 
		
		
				
	}
	for (int contador = 25; contador > -1; contador--) {		//Este for pone una cola de la Z a la A
		ZTOa.enqueue(alfabet[contador]);
		
	}
	
}


//RESULTS SIMULATION
int Logic::getTotalIdCounter() {

	int contador = idcontador;

	return contador;

}
Stack Logic::getTotalNumber555() {

	
	
	return numberStack;

}

//---------------------------------------------------------------------------------------------------------------------//

//OPTION 2
UserData* Logic::searchPhoneNumber(int answer) {

	UserData* userdata = new UserData();
	userdata = binarytreeStore.search(answer, binarytreeStore.getroot());


	return userdata;
}
//---------------------------------------------------------------------------------------------------------------------//

//OPTION 3
UserData* Logic::searchIdPhoneNumber(int answer) {

	UserData* result = new UserData(); //Creamos un UserData
	 binarytreeStore.searchID(answer, binarytreeStore.getroot(),result);//Buscamos el user data con ese id.
	
	return result;

}

List Logic::List100(int id) {//Retornaremos la lista de los 100 id en busqueda preorder
	//Recibe el id que recibimos
	List list = List();
	binarytreeStore.preorderList(id, binarytreeStore.getroot(), list);//Buscamos el user data con ese id.

	return list;
}
//---------------------------------------------------------------------------------------------------------------------//

//OPTION 4
void Logic::storedListStack() {//Rellenamos la lista y el stack
	
	
	binarytreeStore.recover(binarytreeStore.getroot(), recoverList, recoverStack);// Llamamos al metodo y ese metodo nos dara la lista y el stack llenos (variables globales)
	
	
}

UserData* Logic::searchBinaryTree(int id) {
	UserData* result = new UserData();
	binarytreeStore.searchID(id, binarytreeStore.getroot(), result);
	return result;
}


UserData* Logic::searchList(int id) {
	
	UserData* result = new UserData();
	
	result= recoverList.searchId(id);
	return result;

}

UserData*  Logic::searchStack(int id) {
	UserData* result = new UserData();
	
	
	result = recoverStack.searchId(id,recoverStack);
	
	return result;
}


//OPTION 4  RESULTS
List Logic::getRecoverList() {
	return recoverList;
}
Stack Logic::getRecoverStack() {
	return recoverStack;
}
BinaryTree Logic::getBinaryTree() {

	return binarytreeStore;
}