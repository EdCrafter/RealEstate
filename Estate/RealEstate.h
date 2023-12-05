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
	Properties properties;
	Address addresses;
public:
	
	RealEstate() {
		this->setToStandartAddresses();
	}
	bool createUser();
	bool logIn();
	bool setToStandartAddresses();
	bool postNewProperty(unsigned int);
	ASD::String chooseCity();
	ASD::String chooseStreet(ASD::String city);
};

