#pragma once
#include <stdlib.h>	
class UserData
{
	int phoneNumber;    //Declaramos variable tipo int 
	char userRoom;		//Declaramos variable tipo char 
	int id;				//Declaramos variable tipo int

public:
	
	UserData(int phoneNumber, char userRoom, int id);   //Constructor 
	UserData();

	void setPhoneNumber(int phoneNumber);
	void setUserRoom(char userRoom);
	void setId(int id);

	int getPhoneNumber();
	char getUserRoom();
	int getId();
	



};