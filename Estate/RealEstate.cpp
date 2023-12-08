#include "RealEstate.h"
#include "ASDWindow.h"
#include "InputV2.h"
#include "String.h"
#include "Users.h"
#include <string>
#include <iostream>

bool RealEstate::createUser() {
	ASD::String name,password,phone,type;
	ASD::Window win;
	win.SetWidth(40).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
	win.Show();
	int nameValid ,passwordValid;
	ASD::InputV2 in(20, win.GetX() + 14, win.GetY() + 1);
	do
	{
	nameValid = 1;
	win.Write(0, 0, "                                   ");
	win.Write(0, 0, "Input name :");
	in.process(0);
	name = in.get();
	name.toLower();
	
	if (!name.length()) {
		nameValid = 0;
	}
	else {
		int i = 0;
		while (i < users.getUsers().GetCount()) {
			if (users.getUsers()[i].getName() == name) {
				nameValid = 0;
				break;
			}
			i++;
		}
	}
	if (!nameValid) {
		win.Write(0, 0, "                                   ");
		win.Write(0, 0, "Error name or name already using");
		_getch();
	}
	} while (!nameValid);
	do
	{
	passwordValid = 1;
	win.SetHeight(3);
	::SetColor(White, Black);
	cls();
	win.Show();
	win.Write(0, 0, "Input password :");
	in.Move(win.GetX() + 18, win.GetY() + 1);
	in.process(0);
	password = in.get();
	if (password.length()<5) {
		passwordValid = 0;
		win.Write(0, 0, "                                   ");
		win.Write(0, 0, "Not a strong password");
		_getch();
	}
	
	else if (!((password.find("%") || password.find("$") || password.find("_") )
		&& password.hasCapitalLetter()
		) ){
		passwordValid = 0;
		win.Write(0, 0, "                                   ");
		win.SetHeight(5);
		win.Show();
		win.Write(0, 0, "The password must have the characters");
		win.Write(0, 1, "'%' or '$' or '_'");
		win.Write(0, 2, " and contain a capital letter");
		_getch();
	}
	} while (!passwordValid);
	
	win.Show();
	win.Write(0, 0, "Input phone : +380");
	in.setLength(9);
	in.Move(win.GetX() + 19, win.GetY() + 1);
	in.process(3);
	phone =in.get();
	phone = "+380" + phone;
	win.Show();
	win.SetWidth(47);
	do {
		win.Show();
		win.Write(0, 0, "Input type user Customer/Broker(C/B):");
		in.setLength(1);
		in.Move(win.GetX() + 38, win.GetY() + 1);
		in.process(2);
		_getch();
		type = in.get();
		type.toLower();
		if (type == "c") {
			break;
		}
		else if (type == "b") {
			win.Write(0,0,"                                      ");
			win.Write(0, 0, "Input Broker password:");
			in.setLength(15);
			in.Move(win.GetX() + 24, win.GetY() + 1);
			in.process(0);
			ASD::String brokerP = in.get();
			if (brokerPassword == brokerP) {
				break;
			}
			else {
				win.Show();
				win.Write(0, 0, "Wrong Broker password");
				_getch();
			}
		}
		else {
			win.Show();
			win.Write(0, 0, "Wrong choise");
			_getch();
		}
	} while (1);
	users.addUser(name,password,phone,type);
	return true;
}

bool RealEstate::logIn() {
	ASD::String name, password;
	ASD::Window win;
	win.SetWidth(40).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
	win.Show();
	ASD::InputV2 in(20, win.GetX() + 14, win.GetY() + 1);
	win.Write(0, 0, "Input name :");
	in.process(0);
	name = in.get();
	win.Write(0,0,"                                    ");
	win.Write(0, 0, "Input password :");
	in.Move(win.GetX() + 18, win.GetY() + 1);
	in.process(0);
	password = in.get();
	int i = 0;
	while (i < users.getUsers().GetCount()) {
		if (users.getUsers()[i].getName() == name) {
			if (users.getUsers()[i].getPassword() == password) {
				::SetColor(White, Black);
				cls();
				user = &users.getUsers()[i];
				showMainMenu();
				return true;
			}
		}
		i++;
	}

	return false;
}

bool RealEstate::setToStandartAddresses() {
	ASD::String* st = new ASD::String[3]{ "Khreshchatyk Street", "Volodymyrska Street", "Andriivskyi Descent" };
	ASD::Array<ASD::String> Kyiv(st, 3);
	st[0] = "Rynok Square";
	st[1] = "Prospekt Svobody";
	st[2] = "Lesi Ukrainky Street";
	ASD::Array<ASD::String> Lviv(st, 3);
	st[0] = "Deribasivska Street";
	st[1] = "Primorsky Boulevard";
	st[2] = "Pushkinska Street";
	ASD::Array<ASD::String> Odessa(st, 3);
	st[0] = "Sumska Street";
	st[1] = "Constitution Square";
	st[2] = "Pushkinska Street";
	ASD::Array<ASD::String> Kharkiv(st, 3);
	st[0] = "Soborna Street";
	st[1] = "Karla Marksa Avenue";
	st[2] = "Hlinky Street";
	ASD::Array<ASD::String> Dnipro(st, 3);
	st[0] = "Soborna Street";
	st[1] = "Gogolya Street";
	st[2] = "Miru Street";
	ASD::Array<ASD::String> Poltava(st, 3);
	st[0] = "Olha Kobylianska Street";
	st[1] = "Hrushevskoho Street";
	st[2] = "Kobylianska Square";
	ASD::Array<ASD::String> Chernivtsi(st, 3);
	st[0] = "Independence Square";
	st[1] = "Kostelna Street";
	st[2] = "Symona Petlyury Street";
	ASD::Array<ASD::String> Rivne(st, 3);
	st[0] = "Kryvonosa Street";
	st[1] = "Svobody Avenue";
	st[2] = "Zamkova Street";
	ASD::Array<ASD::String> Ternopil(st, 3);
	st[0] = "Halytska Street";
	st[1] = "Hetmanska Street";
	st[2] = "Sheptytskykh Street";
	ASD::Array<ASD::String> IvanoFrankivsk(st, 3);

	addresses.addAddress("Kyiv",Kyiv);
	addresses.addAddress("Lviv",Lviv);
	addresses.addAddress("Odessa", Odessa);
	addresses.addAddress("Kharkiv", Kharkiv);
	addresses.addAddress("Dnipro", Dnipro);
	addresses.addAddress("Poltava", Poltava);
	addresses.addAddress("Chernivtsi", Chernivtsi);
	addresses.addAddress("Rivne", Rivne);
	addresses.addAddress("Ternopil", Ternopil);
	addresses.addAddress("Ivano-Frankivsk", IvanoFrankivsk);

	
	return true;
}

bool RealEstate::postNewProperty() {
	if (!((*user).getLimit())) {
		return false;
	}
	
	ASD::String city, street;
	unsigned int type,countRooms,price,houseNumber;
	int floorNumber=-1000;
	bool forRent = 0;
	city=chooseCity();
	if (city == "") return true;
	street = chooseStreet(city);
	if (street == "") return true;
	type = chooseTypeEstate();
	if (!type) return true;
	else if (type == 1) {
		floorNumber = inputFloorNumber();
		if (floorNumber == -1000) {
			return true;
		}
	}
	countRooms = inputCountRooms();
	houseNumber = inputHouseNumber();
	forRent = inputForRent();
	price = inputPrice();
	Address address(city, street);
	properties.add(address,countRooms,price,type,forRent,houseNumber,floorNumber,user);
	(*user).setLimit(-1);
	return true;
}

ASD::String RealEstate::chooseCity() {
	ASD::String city;
	::SetColor(White, Black);
	cls();
	ASD::FunctionMenu pPMenu("City", 1);
	pPMenu.SetHeight(5).SetWidth(20).HCenter().VCenter();
	for (int i = 0; i < addresses.getCitiesName().GetCount(); i++) {
		pPMenu.addItem(addresses.getCitiesName()[i].get(), [this,i, &city]() {
			city = addresses.getCitiesName()[i];
			::SetColor(White, Black);
			cls();
			});
	}
	pPMenu.Select();
	return city;
}
ASD::String RealEstate::chooseStreet(ASD::String city) {
	ASD::String street;
	ASD::FunctionMenu streetMenu("Street", 1);
	streetMenu.SetHeight(5).SetWidth(30).HCenter().VCenter();
	for (int i = 0; i < addresses.getCityStreets(city).GetCount(); i++) {
		streetMenu.addItem(addresses.getCityStreets(city)[i].get(), [this,i, &street, &city]() {
			street = addresses.getCityStreets(city)[i];
			::SetColor(White, Black);
			cls();
			});
	}
	streetMenu.Select();

	return street;
}
unsigned int RealEstate::chooseTypeEstate() {
	int type=0;
	ASD::FunctionMenu typeMenu("Type", 1);
	typeMenu.SetHeight(5).SetWidth(20).HCenter().VCenter();

	typeMenu.addItem("appartment", [this,&type]() {
		type = 1;
		});
	typeMenu.addItem("penthouse", [this,&type]() {
		type = 2;
		});
	typeMenu.addItem("private house", [this,&type]() {
		type = 3;
		});
	typeMenu.Select();
	::SetColor(White, Black);
	cls();

	return type;
}
int RealEstate::inputFloorNumber() {
	int number=-1000;
	ASD::Window floorNumberWindow;
	floorNumberWindow.SetHeight(3).SetWidth(30).HCenter().VCenter();
	floorNumberWindow.Show();
	floorNumberWindow.Write(0, 0, "Input number floor :");
	ASD::InputV2 in(3, floorNumberWindow.GetX()+22, floorNumberWindow.GetY() + 1);
	in.process(3);
	ASD::String numberStr = in.get();
	if (numberStr.length() > 0) {
		setlocale(0, "en");
		number = atoi(numberStr.get());
	}
	::SetColor(White, Black);
	cls();
	return number;
}
unsigned int RealEstate::inputCountRooms() {
	unsigned int rooms = 0;
	ASD::Window ñountRoomsWindow;
	ñountRoomsWindow.SetHeight(3).SetWidth(30).HCenter().VCenter();
	ñountRoomsWindow.Show();
	ñountRoomsWindow.Write(0, 0, "Input count rooms :");
	ASD::InputV2 in(3, ñountRoomsWindow.GetX()+22, ñountRoomsWindow.GetY() + 1);
	in.process(3);
	ASD::String roomsStr = in.get();
	if (roomsStr.length() > 0) {
		setlocale(0, "en");
		rooms = atoi(roomsStr.get());
	}
	::SetColor(White, Black);
	cls();
	return rooms;
}
unsigned int RealEstate::inputHouseNumber() {
	unsigned int number=0;
	ASD::Window houseNumberWindow;
	houseNumberWindow.SetHeight(3).SetWidth(30).HCenter().VCenter();
	houseNumberWindow.Show();
	houseNumberWindow.Write(0, 0, "Input number house :");
	ASD::InputV2 in(3, houseNumberWindow.GetX()+22, houseNumberWindow.GetY() + 1);
	in.process(3);
	ASD::String numberStr = in.get();
	if (numberStr.length() > 0) {
		setlocale(0, "en");
		number = atoi(numberStr.get());
	}
	::SetColor(White, Black);
	cls();
	return number;
}
unsigned int RealEstate::inputPrice() {
	unsigned int price=0;
	ASD::Window priceWindow;
	priceWindow.SetHeight(3).SetWidth(45).HCenter().VCenter();
	priceWindow.Show();
	priceWindow.Write(0, 0, "Enter the sale price or per month :");
	ASD::InputV2 in(7, priceWindow.GetX()+37, priceWindow.GetY() + 1);
	in.process(3);
	ASD::String priceStr = in.get();
	if (priceStr.length() > 0) {
		setlocale(0, "en");
		price = atoi(priceStr.get());
	}
	::SetColor(White, Black);
	cls();
	return price;
}
bool RealEstate::inputForRent() {
	bool rent=0;
	ASD::Window rentWindow;
	rentWindow.SetHeight(3).SetWidth(35).HCenter().VCenter();
	rentWindow.Show();
	rentWindow.Write(0, 0, "This property is for rent(1/0):");
	ASD::InputV2 in(1, rentWindow.GetX()+33, rentWindow.GetY() + 1);
	in.process(3);
	ASD::String rentStr = in.get();
	if (rentStr.length() > 0) {
		setlocale(0, "en");
		rent = atoi(rentStr.get());
	}
	::SetColor(White, Black);
	cls();
	return rent;
}
void RealEstate::removeProperty() {
	int i = printAllProperties(1);
	if (i+1) {
		properties.remove(i);
		user->setLimit(1);
		::SetColor(White, Black);
		cls();
		ASD::Window w;
		w.SetWidth(34).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
		w.Show();
		w.Write(0, 0, "Property Successfully Removed");
		_getch();
	}
	else {
		::SetColor(White, Black);
		cls();
		ASD::Window w;
		w.SetWidth(34).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
		w.Show();
		w.Write(0, 0, "Properties not found");
		_getch();
	}
}
int RealEstate::printAllProperties(bool useUser=0) {
	
	ASD::ArrayMenu window;
	window.SetHeight(8).SetWidth(60).HCenter().VCenter().SetColor(LightGray);
	setlocale(0, "en");
	if (!properties.getProperties().GetCount()) return -1;
	int* arrInd = new int[properties.getProperties().GetCount()];
	window.setHeightRow(3);
	for (int i = properties.getProperties().GetCount()-1 , j=0; i+1; i--) {
		
		Properties::PropertyData property(properties.getProperty(i));
		if (useUser && user != property.user) {
			continue;
		}
		arrInd[j] = i;
		j++;
		ASD::String typeStr, floorNumber, forRent,userType;
		bool floor = 0;
		switch (property.type)
		{
		case 1:
			typeStr = "Appartment";
			floor = 1;
			break;
		case 2:
			typeStr = "Penthouse";
			break;
		case 3:
			typeStr = "Private house";
			break;
		default:
			typeStr = "Estate";
		}
		if (floor) {
			floorNumber = ",floor ";
			floorNumber += std::to_string(property.floorNumber).c_str();
		}
		if (property.forRent) {
			forRent = "for rent";
		}
		else {
			forRent = "for sale";
		}
		if (property.user->getType() == "c") {
			userType = "(individual)";
		}
		else {
			userType = "(broker)";
		}
		ASD::String str = typeStr + " " + forRent + " " + std::to_string(property.countRooms).c_str();
		str += " rooms " + floorNumber + ".\n" + "Price :"+std::to_string(property.price).c_str();
		str += " dollars.\nContacts:";
		str+=property.user->getName();
		str += " ";
		str+=property.user->getPhone();
		str += " " + userType+".";
		window.Add(str.get());
	}
	if (!window.GetCount()) return -1;
	int selected = arrInd[window.Select()];
	delete[] arrInd;
	return selected;
}
bool RealEstate::printPropertiesByParametrs(RealEstate::parametrs arr) {
	
	ASD::ArrayMenu window;
	window.SetHeight(8).SetWidth(60).HCenter().VCenter().SetColor(LightGray);
	setlocale(0, "en");
	if (!properties.getProperties().GetCount()) return false;
	window.setHeightRow(3);
	for (int i = properties.getProperties().GetCount()-1; i+1; i--) {
		
		Properties::PropertyData property(properties.getProperty(i));
		if ((arr.countRooms != 999 && arr.countRooms != property.countRooms )
			|| arr.forRent != property.forRent ||
			(arr.type != 999 && arr.type != property.type) ||
			arr.minPrice>property.price || arr.maxPrice < property.price
			) {
			continue;
		}
		ASD::String typeStr, floorNumber, forRent,userType;
		bool floor = 0;
		switch (property.type)
		{
		case 1:
			typeStr = "Appartment";
			floor = 1;
			break;
		case 2:
			typeStr = "Penthouse";
			break;
		case 3:
			typeStr = "Private house";
			break;
		default:
			typeStr = "Estate";
		}
		if (floor) {
			floorNumber = ",floor ";
			floorNumber += std::to_string(property.floorNumber).c_str();
		}
		if (property.forRent) {
			forRent = "for rent";
		}
		else {
			forRent = "for sale";
		}
		if (property.user->getType() == "c") {
			userType = "(individual)";
		}
		else {
			userType = "(broker)";
		}
		ASD::String str = typeStr + " " + forRent + " " + std::to_string(property.countRooms).c_str();
		str += " rooms " + floorNumber + ".\n" + "Price :"+std::to_string(property.price).c_str();
		str += " dollars.\nContacts:";
		str+=property.user->getName();
		str += " ";
		str+=property.user->getPhone();
		str += " " + userType+".";
		window.Add(str.get());
	}
	if (!window.GetCount()) return false;
	window.Select();
	return true;
}
void RealEstate::showMainMenu() {
	ASD::FunctionMenu mainMenu("Menu", 1);
	mainMenu.setSelectColor(Cyan).SetHeight(5).SetWidth(40).HCenter().VCenter().SetBgColor(Green).SetBorderColor(Magenta).SetColor(Yellow);
	mainMenu.addItem("Post New Property", [this, &mainMenu]() {
		if (!postNewProperty()) {
			::SetColor(White, Black);
			cls();
			ASD::Window w;
			w.SetWidth(34).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
			w.Show();
			w.Write(0, 0, "Your Ad Limit Has Been Reached");
			_getch();
		}
		::SetColor(White, Black);
		cls();
		mainMenu.Select();
		});
	mainMenu.addItem("Remove Property", [this, &mainMenu]() {
		removeProperty();
		::SetColor(White, Black);
		cls();
		mainMenu.Select();
		});
	mainMenu.addItem("Print All Properties", [this, &mainMenu]() {
		if (!(printAllProperties()+1)) {
			::SetColor(White, Black);
			cls();
			ASD::Window w;
			w.SetWidth(34).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
			w.Show();
			w.Write(0, 0, "Properties not found");
			_getch();
		}
		::SetColor(White, Black);
		cls();
		mainMenu.Select();
		});
	mainMenu.addItem("Print my Properties", [this, &mainMenu]() {
		if (!(printAllProperties(1)+1)) {
			::SetColor(White, Black);
			cls();
			ASD::Window w;
			w.SetWidth(34).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
			w.Show();
			w.Write(0, 0, "Properties not found");
			_getch();
		}
		::SetColor(White, Black);
		cls();
		mainMenu.Select();
		});
	mainMenu.addItem("Print properties by parametrs", [this, &mainMenu]() {
		parametrs arr = propertiesByParametrs();
		if (!printPropertiesByParametrs(arr)) {
			::SetColor(White, Black);
			cls();
			ASD::Window w;
			w.SetWidth(34).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
			w.Show();
			w.Write(0, 0, "Properties not found");
			_getch();
		}
		::SetColor(White, Black);
		cls();
		mainMenu.Select();
		});

	mainMenu.Select();
}
RealEstate::parametrs RealEstate::propertiesByParametrs() {
	RealEstate::parametrs arr;
	setlocale(0, "en");
	ASD::Window win;
	win.SetWidth(50).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
	win.Show();
	ASD::InputV2 in(1, win.GetX() + 47, win.GetY() + 1);
	win.Write(0, 0, "You are looking for a rented property (1/0) :");
	in.process(3);
	arr.forRent = atoi(in.get());
	win.SetHeight(5);
	win.Write(0, 0, "                                              ");
	win.Show();
	win.Write(0, 0, "You are looking for an apartment (1) ,");
	win.Write(0, 1, "penthouse(2), private house(3) ");
	win.Write(0, 2, "or all of this(999) :");
	in.setLength(3);
	in.Move(win.GetX() + 23, win.GetY() + 3);
	in.process(3);
	arr.type = atoi(in.get());
	::SetColor(15, 0);
	cls();
	win.SetHeight(3);
	win.SetWidth(32);
	win.Show();
	win.Write(0, 0, "                         ");
	win.Write(0, 0, "How many rooms (all:999):");
	in.Move(win.GetX() + 27, win.GetY() + 1);
	in.process(3);
	arr.countRooms = atoi(in.get());
	in.setLength(7);
	win.Show();
	win.Write(0, 0, "                ");
	win.Write(0, 0, "Input min price:");
	in.Move(win.GetX() + 18, win.GetY() + 1);
	in.process(3);
	arr.minPrice = atoi(in.get());
	win.Show();
	win.Write(0, 0, "                 ");
	win.Write(0, 0, "Input max price:");
	in.Move(win.GetX() + 18, win.GetY() + 1);
	in.process(3);
	arr.maxPrice = atoi(in.get());
	return arr;
}

void RealEstate::start() {
	ASD::FunctionMenu myInterface("Real Estate", 1);
	myInterface.SetHeight(5).SetWidth(20).HCenter().VCenter();
	myInterface.addItem("Sign up", [this, &myInterface]() {
		if ((*this).createUser()) {
			::SetColor(White, Black);
			cls();
			ASD::Window w;
			w.SetWidth(20).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
			w.Show();
			w.Write(0, 0, "User created");
		}
		_getch();
		::SetColor(White, Black);
		cls();
		myInterface.Select();
		});
	myInterface.addItem("Log in", [this, &myInterface]() {
		if (!(*this).logIn()) {
			::SetColor(White, Black);
			cls();
			ASD::Window w;
			w.SetWidth(30).SetHeight(3).SetColor(Green).SetBgColor(Yellow).VCenter().HCenter();
			w.Show();
			w.Write(0, 0, "Error user name or password");
			_getch();
		}
		::SetColor(White, Black);
		cls();
		myInterface.Select();
		});
	myInterface.Select();
}