#include <iostream>
#include <Windows.h>
#include <conio.h>
//#include <string>
#include "String_.h"
#include "Array.h"
#include "List.cpp"
#include "Menu.h"

using namespace ASD;


void main() {
	/*
	
  string* menuItem = new string[2]
  { 
    "string",
    "array",
	"list",
	"0: exit"
  };
  
  Menu* menu = Menu::GetInstance(menuItem, 4, 10);*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "rus");
	ASD::string s;

	Array <int> arr(11);
	arr.setrand();

	List <int> list;
	for (int i = 0; i < 12; i++) {
		list.AddHead(rand() % 10);
	}
	List<int>::Node* t = list.GetHead();

	char key;
	bool flag = true;
	Menu* menu = Menu::GetInstance();
	system("cls");
	menu->PrintMenu();
	while (flag) {
		switch (key = _getch()) {
		case '1':
			system("cls");
			s.input();
			s.cut(' ', ' ');
			std::cout << s.str << "\n";
			menu->PrintMenu();
			break;
		
		case '2':
			system("cls");
			std::cout << "Array \n";
			for (int i = 0; i < 11; i++)std::cout << arr[i] << " ";
			std::cout << "\nЧисла кратные 2 и не кратные 3: \n";
			for (int i = 0; i < 11; i++) {
				if (arr[i] % 2 == 0 && arr[i] % 3 != 0) {
					std::cout << arr[i] << " ";
				}
			}
			std::cout << "\n";
			menu->PrintMenu();
			break;
		case '3':
			system("cls");
			std::cout << "List:\n";
			
			while (t) {
				std::cout << t->value << " ";
				t = t->next;
			}
			t = list.GetTail();
			std::cout << "\nЧисла кратные 2 и не кратные 3:\n";
			while (t) {
				
				if (t->value % 2 == 0 && t->value % 3 != 0)std::cout << t->value << " ";
				t = t->prev;
			}
			std::cout << "\n";
			menu->PrintMenu();
			break;
		case '4':
			flag = false;
			cout << "\nВы вышли из программы\n";
			break;
		default:
			cout << "Вы ввели не верный пункт меню\n";
			break;
		}
		system("pause");

	}
}
