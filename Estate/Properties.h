#pragma once
#include "Array.h"
#include "String.h"
#include "Address.h"
#include "Users.h"
class Properties
{
public:
	
	struct PropertyData
	{
		Address address;
		unsigned int countRooms;
		unsigned int price;
		ASD::String type;
		unsigned int forRent;
		unsigned int houseNumber;
		unsigned int floorNumber;
		User user;
	};
	ASD::Array<PropertyData> properties;

};

