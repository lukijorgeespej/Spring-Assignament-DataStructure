#include "UserInterface.h"

#include <iostream>
using namespace std;



UserInterface::UserInterface() {
	this->logic = Logic();
	
	
}


//Colection and Execution of User Option   (Recogida y ejecución de la opción del usuario)
void UserInterface::printMenu()  //Printeamos el menú para que el usuario eliga una opción
{
	
	string option1 = "1. Simulate users arriving 1h";
    string option2 = "2. Search a phone number";
    string option3 = "3. List of 100 phone-ID in the tree";
    string option4 = "4. Efficiency comparison";
    string option5 = "5. 555 printing.";
    string option6= "6. Exit the program";
	
    cout << endl /*Bajar de linea*/  << endl << "MENU - CHOOSE AN OPTION:" << endl << endl << option1 << endl << option2 << endl << option3 << endl << option4 << endl << option5 << endl << option6 << endl;
	readOption();



}

void UserInterface::readOption()	//Usuario elige la opción del a 1 al 6 (6->Salir del programa)
{
	int answer;
	cin >> answer;  //Entrada de valor por teclado
	if (answer== 1 || answer == 2 || answer == 3 || answer== 4 || answer == 5 || answer == 6)
	{
		cout << "You selected: " << answer << endl << endl;
		
		executeOption(answer);
	}
	else
	{
		printMenu();
	}
}

void UserInterface::executeOption(int answer)//Ejecuta la opción seleccionada
{
	
	bool exit = false;
	if (answer== 1)
	{
		// 1. Simulate users arriving 1h
		StartSimulation();
		
	}
	else if (answer== 2)
	{
		// 2. Search a phone number
		searchPhone();
	}
	else if (answer== 3)
	{
		// 3. List of 100 phone-ID in the tree
		
		searchPhoneID();
		
	}
	else if (answer == 4)
	{
		// 4. Efficiency comparison
		recoverListStack();
	}
	else if (answer == 5)
	{
		// 5. 555 printing
		print555();

	}
	else if (answer == 6)
	{
		// 6. Exit the program

		exit = true;
	}
	if (!exit)
	{
		
		printMenu();
	}
}




//OPCION 1
void UserInterface::StartSimulation() {

	logic.newSimulation();
	
	int idCounter = logic.getTotalIdCounter();
	
	cout << "Total IdUsers  " << idCounter<<endl;//Total de id counter
	
	cout << "Total Number 555: " << logic.getTotalNumber555().getlenght()<<endl;//Saca la cantidad de numeros 555

	
	
}

//OPTION 2
void UserInterface::searchPhone() {


	int answer;
	UserData* userdata = new UserData();
	bool condition = true;


	cout << "Introduce the number that you want to search(between 1 - 9 digits): ";
	cin >> answer;


	string s = to_string(answer);
	

	while (condition) {
		if (s.size() <= 9 && s.size() > 0) {
			condition = false;
		}
		else {
			cout << endl;
			cout << "Introduce the number that you want to search(between 1-9 digits): ";
			cin >> answer;
		}

	}

	userdata = logic.searchPhoneNumber(answer);
	printUserData(userdata);

}

//OPTION 3
void UserInterface::searchPhoneID() {
	int answer;
	bool condition=true;
	UserData* userdata = new UserData();
	List list100 = List();
	int idTotal=logic.getTotalIdCounter();
	cout << "Introduce the number that you want to search(between 1 -  the highest ID digits -> " << idTotal << " ): " ;
	cin >> answer;
	while (condition) {
		if (answer> idTotal || answer<1) {

			cout << "Introduce the number that you want to search(between 1 -  the highest ID digits -> " << idTotal << " ): " ;
			cin >> answer;
			

		}
		else {
			cout << "The id you have entered is: " << answer<<endl ;
			condition = false;
			
		}
	}
	
	userdata = logic.searchIdPhoneNumber(answer);
	list100=logic.List100(answer);
	printUserData(userdata);

	cout << "LIST" << endl;
	printList(list100);


}

//OPTION 4
void UserInterface::recoverListStack() {
	//Aqui vamos sacando los 100 useradatas de el binarytree,la lista y el stack
	
	//1 PART

	logic.storedListStack();//Metodo con la lista y el stack rellenos
	
	int randomnumber = 0;
	int id = 0;
	Queue queueBinaryTree = Queue();
	Queue queueList = Queue();
	Queue queueStack = Queue();
	UserData* userdata = new UserData();

	//2 PART RELLENAR LAS COLAS
	for (int i = 0; i <= 100; i++) {//Total for 100 veces, los numeros los vamos metiendo en queues

		randomnumber = logic.randomNumber(1, logic.getTotalIdCounter());//Nos crea ids aleatorios desde el uno al total ids puedan haber

		queueBinaryTree.enqueue(randomnumber);
		queueList.enqueue(randomnumber);
		queueStack.enqueue(randomnumber);
		
	}
	
	//BINARY TREE

	cout << "Search in Binary tree" << endl;
	double begin, end, binarytreetime;
	begin = double(clock());

	for (int i = 0; i <= 100; i++) {//Sacar en  Binary Tree
		 id = queueBinaryTree.dequeueInt();
		 
		userdata = logic.searchBinaryTree(id);
		printUserData(userdata);
			
	}
	end = double(clock());
	binarytreetime = (end - begin) / 1000;
	cout << "Time it took for the search of 100 randoms ID in Binary Tree: " << binarytreetime << " milliseconds." << endl;

	//--------------------------------------------------------------------------------------------------------------------------------------------------/

	//LIST
	cout << "Search in List" << endl;
	double listTime;
	begin = double(clock());
	
	
	for (int i = 0; i <= 100; i++) {//Sacar en  List


		 id = queueList.dequeueInt();
		
		userdata = logic.searchList(id);
		printUserData(userdata);

	}
	end = double(clock());
	listTime = (end - begin) / 1000;
	cout << "Time it took for the search of 100 randoms ID in List: " << listTime << " milliseconds." << endl;

	//--------------------------------------------------------------------------------------------------------------------------------------------------//

	//STACK
	cout << "Search in Stack" << endl;
	
	double stackTime;
	begin = double(clock());
	
	
	for (int i = 0; i <= 100; i++) {//Sacar en  Stack


		id = queueStack.dequeueInt();
		
		userdata=logic.searchStack(id);
		printUserData(userdata);
	}
	
	end = double(clock());
	stackTime = (end - begin) / 1000;
	cout << "Time it took for the search of 100 randoms ID in Stack: " << stackTime << " milliseconds." << endl;

	//--------------------------------------------------------------------------------------------------------------------------------------------------//

	//Tiempos resumen
	cout << endl << "TimeSummary" << endl;
	cout << "Time Binary Tree: " << binarytreetime << endl;
	cout << "Time List: " << listTime << endl;
	cout << "Time Stack: " << stackTime << endl;
}

//OPTION 5
void UserInterface::print555() {
	
	//1 PART  imprimiremos los numeros 555 junto con su id atraves de la cola. Además sacara el tiempo de ejecución

	Stack stack555 = Stack();
	Queue queue555 = Queue();
	Queue queuecopy = Queue();
	UserData* userdata = new UserData();
	int numberphone555;
	stack555 = logic.getTotalNumber555();//Metemos en un stack todos los numeros 555
	
	cout << "Numbers 555 Queue: " << endl;
	
	double begin, end, print555TimeQueue;
	begin = double(clock());
	while (!stack555.isEmpty()) {//Mientras no este vacio se ejecuta
		userdata=stack555.pop();//Saco los 555 de el stack

		queue555.enqueue(userdata->getPhoneNumber());//Y los voy metiendo en la queue
		numberphone555=queue555.dequeueInt();//Los sacamos para imprimir los numeros
		cout << "Id: " << userdata->getId()  << " Number Phone: " << numberphone555 << endl;//Imprimimos los numeros 555 
		
		
		queuecopy.enqueue(userdata->getPhoneNumber());//Y los voy metiendo en la queuecopia
		
	}
	end = double(clock());
	print555TimeQueue = (end - begin) / 1000;
	cout << "Time it took for print Number 555 in Queue: " << print555TimeQueue << " milliseconds." << endl;

	//-----------------------------------------------------------------------------------------------------------------------------------------------------//

	//2 PART imprimiremos los numeros 555 junto con su id atraves del binary tree. Además sacara el tiempo de ejecución

	double print555TimeBinaryTree;
	begin = double(clock());
	
	int phonenumber555;
	
	BinaryTree tree = BinaryTree();
	tree = logic.getBinaryTree();

	cout <<endl<< "Numbers 555 Binary Tree: " << endl;

	while (!queuecopy.isEmpty()) {
			
		phonenumber555 = queuecopy.dequeueInt();
		
		userdata=tree.search(phonenumber555,tree.getroot());
		cout << "Id: " << userdata->getId() << " Number Phone: " << userdata->getPhoneNumber() << endl;//Imprimimos los numeros 555 
	}
	end = double(clock());
	print555TimeBinaryTree = (end - begin) / 1000;
	cout << "Time it took for print Number 555 in BinaryTree : " << print555TimeBinaryTree << " milliseconds." << endl;
		
}

//PRINTERS
void UserInterface::printList(List list) {
	
	NodeList* node = new NodeList();
	node = list.getHead();

	for (int i = 0; i < list.lengthList(); i++) {

		printUserData(node->getValue());
		node = node->getNext();
	}
	

}

void UserInterface::printStack(Stack stack) {
		
		UserData* user = new UserData();
		int lenght=0;
		if (stack.isEmpty()) {

			
		}
		lenght =stack.getlenght();//Cojemos la longitud del stack
		
		for (int i = 0; i<lenght; i++ ) {//Leo el stack hasta que quede vacio
			
			user=stack.pop();
			printUserData(user);

		}
		
}

void UserInterface::printUserData(UserData* userData) {

	cout << "Id: " << userData->getId() << " MMRoom: " << userData->getUserRoom() << " Number Phone: " << userData->getPhoneNumber() << endl;
}

