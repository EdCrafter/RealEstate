#include "RealEstate.h"
#include "ASDWindow.h"
#include "InputV2.h"
#include "String.h"
#include "Users.h"
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
				ASD::FunctionMenu mainMenu("Menu", 1);
				mainMenu.SetHeight(5).SetWidth(20).HCenter().VCenter();
				mainMenu.addItem("Post New Property", [this,&mainMenu,&i]() {
					if (!postNewProperty(i)) {
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
				
				mainMenu.Select();
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

bool RealEstate::postNewProperty(unsigned int i) {
	User& user = users.getUsers()[i];
	if (!(user.getLimit())) {
		return false;
	}
	else {
		user.setLimit(-1);

		std::cout << "                        " << user.getLimit() << "\n";
		_getch();
	}
	return true;
}