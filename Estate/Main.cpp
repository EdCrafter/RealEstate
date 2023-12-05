#include <iostream>
#include "ASDWindow.h"
#include "RealEstate.h"
using namespace std;

int main() {
	RealEstate realEstate;
	ASD::FunctionMenu myInterface("Real Estate",1);
	myInterface.SetHeight(5).SetWidth(20).HCenter().VCenter();
	myInterface.addItem("Sign up", [&realEstate, &myInterface]() {
		if (realEstate.createUser()) {
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
	myInterface.addItem("Log in", [&realEstate, &myInterface]() {
		if (!realEstate.logIn()) {
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
	return 0;
}