#include <iostream>
#include "ASDWindow.h"
#include "fun_console.h"

ASD::Window::Window() {
	x = y = 0;
	width = GetCols();
	height = GetRows();
	SetBgColor(Blue);
	SetColor(White);
	SetBorderColor(LightBlue);
	
	buf[0] = 201;
	buf[1] = 205;
	buf[2] = 187;
	buf[3] = 186;
	buf[4] = 200;
	buf[5] = 188;
	
}

ASD::Window & ASD::Window::HCenter() {
	x = (GetCols() - width) / 2;
	return *this;
}
ASD::Window & ASD::Window::VCenter() {
	y = (GetRows() - height) / 2;
	return *this;
}

ASD::Window & ASD::Window::SetColor(int c) {
	color = c;
	return *this;
}

ASD::Window & ASD::Window::SetBgColor(int c) {
	bgColor = c;
	return *this;
}

ASD::Window & ASD::Window::SetBorderColor(int c) {
	borderColor = c;
	return *this;
}

ASD::Window & ASD::Window::Move(int _x, int _y) {
	if (_x + width <= GetCols()) {
		x = _x;
	}
	else {
		width -= (_x - x);
		x = _x;
	}
	
	if (_y + height <= GetRows()) {
		y = _y;
	}
	else {
		height -= (_y - y);
		y = _y;
	}
	return *this;
}

ASD::Window & ASD::Window::SetWidth(int w) {
	if (w >= 3 && x + w <= GetCols()) {
		width = w;
	}
	return *this;
}

ASD::Window & ASD::Window::SetHeight(int h) {
	if (h >= 3 && y + h <= GetRows()) {
		height = h;
	}
	return *this;
}

ASD::Window & ASD::Window::Write(int _x, int _y, const char * str) {
	if (_x >= GetClientWidth() ||  _y >= GetClientHeight()) {
		return *this;
	}
	//::SetColor(color, bgColor);
	GotoXY(x + _x + 1, y + _y + 1);
	for (int i = 0; str[i]; i++) {
		if (_x + i >= GetClientWidth()) {
			break;
		}
		std::cout << str[i];
	}
	return *this;
}

ASD::Window &  ASD::Window::Show() {
	setlocale(0, ".850");
	::SetColor(borderColor, bgColor);
	GotoXY(x, y);
	std::cout << buf[0];
	for (int j = 0; j < width - 2; j++) {
		std::cout << buf[1];
	}
	std::cout << buf[2];
	for (int i = 1; i < height - 1; i++) {
		GotoXY(x, y + i);
		std::cout << buf[3];
		GotoXY(x + width - 1, y + i);
		std::cout << buf[3];
	}
	GotoXY(x, y + height - 1);
	std::cout << buf[4];
	for (int j = 0; j < width - 2; j++) {
		std::cout << buf[1];
	}
	std::cout << buf[5];
	::SetColor(color, bgColor);
	for (int i = 1; i < height - 1; i++) {
		GotoXY(x + 1, y + i);
		for (int j = 0; j < width-2; j++) {
			std::cout << " ";
		}
	}
	GotoXY(x + 1, y + 1);
	Draw();
	return *this;
}


/*
int ASD::Menu::Select() {
	if (items.GetCount() == 0) {
		active = -1;
		return active;
	}
	ShowCaret(false);
	active = 0;
	first = 0;
	while (1) {
		Show();

		if (active > first + GetClientHeight() - 1) {
			first = active - GetClientHeight() + 1;
		}
		else if (active < first) {
			first = active;
		}

		for (int i = 0, j = first; i < GetClientHeight() && j < items.GetCount(); i++, j++) {
			if (j == active) {
				::SetColor(selectColor, selectBgColor);
				::GotoXY(x + 1, y + 1 + i);
				for (int k = 0; k < GetClientWidth(); k++) {
					std::cout << " ";
				}
			}
			else {
				::SetColor(color, bgColor);
			}
			this->Write(0, i, items[j]);
		}
		int key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 80 && active + 1 < items.GetCount()) { //down
				active++;
			}
			if (key == 72 && active > 0) { //down
				active--;
			}
			continue;
		}
		if (key == 27) {
			active = -1;
			break;
		}
		if (key == 13) {
			break;
		}

	}
	ShowCaret(true);
	return active;
}

*/


int ASD::Menu::Select() {
	if (GetCount() == 0) {
		active = -1;
		return active;
	}
	ShowCaret(false);
	active = 0;
	first = 0;
	while (1) {
		Show();

		if (active > first + GetClientHeight() - 1) {
			first = active - GetClientHeight() + 1;
		}
		else if (active < first) {
			first = active;
		}

		for (int i = 0, j = first; i < GetClientHeight() && j < GetCount(); i++, j++) {
			if (j == active) {
				::SetColor(selectColor, selectBgColor);
				::GotoXY(x + 1, y + 1 + i);
				for (int k = 0; k < GetClientWidth(); k++) {
					std::cout << " ";
				}
			}
			else {
				::SetColor(color, bgColor);
			}
			DrawItem(i, j);
		}
		int key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 80 && active + 1 < GetCount()) { //down
				active++;
			}
			if (key == 72 && active > 0) { //down
				active--;
			}
			continue;
		}
		if (key == 27) {
			active = -1;
			break;
		}
		if (key == 13) {
			break;
		}

	}
	ShowCaret(true);
	return active;
}
int ASD::FunctionMenu::Select() {
	if (GetCount() == 0) {
		active = -1;
		return active;
	}
	ShowCaret(false);
	active = 2;
	first = 0;
	while (1) {
		height -= 2;
		Show();
		height += 2;
		if (active > first + GetClientHeight() - 1) {
			first = active - GetClientHeight() + 1;
		}
		else if (active < first+2) {
			first = active-2;
		}
		for (int i = 0, j = first; i < GetClientHeight() && j < GetCount()+2; i++, j++) {
			if (j == active) {
				::SetColor(selectColor, selectBgColor);
				::GotoXY(x + 1, y - 1 + i);
			}
			else {
				::GotoXY(x + 1, y - 1 + i);
				::SetColor(color, bgColor);
			}
			if (i != 1) {
				for (int k = 0; k < GetClientWidth(); k++) {
					std::cout << " ";
				}
			}
			if (!i) {
				int left = (GetClientWidth()-strlen(title))/2;
				Write(left, -2, (const char*)(title));
			}
			if (j > 1 && i>1) {
				DrawItem(i-2, j-2);
			}
		}
		
		int key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 80 && active + 1 < GetCount()+2) { //down
				active++;
			}
			if (key == 72 && active > 2) { //down
				active--;
			}
			continue;
		}
		if (key == 13) {
			break;
		}

	}
	active -= 2;
	getCountAction();
	ShowCaret(true);
	return active;
}
