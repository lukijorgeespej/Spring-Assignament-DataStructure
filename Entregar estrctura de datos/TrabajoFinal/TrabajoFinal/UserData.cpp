
#include "UserData.h"

UserData::UserData(int phoneNumber, char userRoom, int  id)
{
	this->phoneNumber = phoneNumber;   //Estamos inicializando el nodo
	this->userRoom = userRoom;
	this->id = id;

}
UserData::UserData()
{
	this->phoneNumber = NULL;   //Estamos inicializando el nodo
	this->userRoom = NULL;
	this->id = NULL;

}


void UserData::setPhoneNumber(int phone) {

	phoneNumber = phone;
}
void UserData::setUserRoom(char user) {
	userRoom = user;
}
void UserData::setId(int i) {
	id = i;
}

int UserData::getPhoneNumber() {
	return phoneNumber;
}
char UserData::getUserRoom() {
	return userRoom;
}
int UserData::getId() {
	return id;
}
