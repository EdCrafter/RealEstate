#pragma once
#include "Array.h"
#include "String.h"

class User
{
protected:
	ASD::String name;
	ASD::String password;
	ASD::String phone;
	ASD::String type;
	int limit;
public:
	User() : name(), password(), phone(), type(), limit() {}
	User(ASD::String& newName, ASD::String& newPassword,ASD::String& newPhone,ASD::String& newType,int newLimit)
		: name(newName), password(newPassword), phone(newPhone), type(newType),limit(newLimit) {}

	User(User& other)
		: name(other.name), password(other.password), phone(other.phone), type(other.type),limit(other.limit){
	}
	ASD::String getName() {
		return name;
	}
	ASD::String getPassword() {
		return password;
	}
	ASD::String getPhone() {
		return phone;
	}
	ASD::String getType() {
		return type;
	}
	int getLimit() {
		return limit;
	}
	int setLimit(int dec) {
		limit += dec;
		return limit;
	}

	User& operator = (User& other) {
		name = other.name;
		password = other.password;
		phone = other.phone;
		type = other.type;
		limit = other.limit;
		return *this;
	}
	bool operator != (User& other) {
		return (!(*this == other));
	}
	bool operator == (User& other) {
		if (
			name == other.name
			) {
			return true;
		}
		return false;
	}
	void toString() {
		std::cout << "name =     " << name << "\n";
		std::cout << "password = " << password << "\n";
		std::cout << "name =     " << phone << "\n";
		std::cout << "name =     " << type << "\n";
	}
};



class Users
{
	ASD::Array<User> users;
public:	
	
	ASD::Array<User>& getUsers() {
		return users;
	}
	bool addUser(ASD::String name,ASD::String password,ASD::String phone,ASD::String type) {
		int limit = 0;
		if (type == "c") {
			limit = 3;
		}
		else if (type == "b") {
			limit = 10;
		}
		User user(name,password,phone,type,limit);
		users.Add(user);
		return true;
	}
	void toString() {
		for (int i = 0; i < users.GetCount(); i++) {
			std::cout << "User id = " << i << "\n";
			users[i].toString();
			std::cout << "\n";
		}
	}

};

