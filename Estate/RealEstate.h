#pragma once
#include "Array.h"
#include "Users.h"
#include "Properties.h"
#include "Address.h"
#include <iostream>
class RealEstate
{
	ASD::String brokerPassword = "broker";
	Users users;
	User* user;
	Properties properties;
	Addresses addresses;
public:
	
	RealEstate() {
		this->setToStandartAddresses();
	}
	bool createUser();
	bool logIn();
	bool setToStandartAddresses();
	bool postNewProperty();
	ASD::String chooseCity();
	ASD::String chooseStreet(ASD::String city);
	unsigned int chooseTypeEstate();
	int inputFloorNumber();
	unsigned int inputCountRooms();
	unsigned int inputPrice();
	unsigned int inputHouseNumber();
	bool inputForRent();
	void removeProperty();
	bool printAllProperties();
	void showMainMenu();
};

