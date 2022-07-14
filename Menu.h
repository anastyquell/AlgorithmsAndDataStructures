#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void SetColor(int text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

class Menu
{
	int col;
	int amount;
	int padding;
	string* menu = nullptr;
	string* text = nullptr;
	int MaxLenth(string* text, int size)
	{
		int max = text[0].length();
		for (int i = 1; i < size; i++)
		{
			if (max <= text[i].length())
			{
				max = text[i].length();
			}
		}
		return max;
	}
	int createMenu()
	{
		if (text == nullptr)
		{
			cout << "Введите кол-во пунктов меню: ";
			cin >> amount;
			cout << "Заполните списов меню по формату - <<Номер - Задание>>." << endl;
			text = new string[amount];
			cin.ignore();
			for (int i = 0; i < amount; i++)
			{
				cout << "Пункт №" << i + 1 << ": ";
				getline(cin, text[i]);

			}
			cout << "Введите значение для отступов-->";
			cin >> padding;
		}


		col = amount + 2;
		int row = MaxLenth(text, amount) + (padding + padding) + 6;
		menu = new string[col];
		int k = 0, counter = 0;
		for (int i = 0; i < col; i++)
		{
			
			string line = "";
			if (i == 0)
			{

				line += "#";
				int num = (row - 8) / 2;
				for (int j = 0; j < num; j++)
				{
					line += "-";
				}

				line += "<MENU>";
				if (row % 2 == 0)
				{
					for (int j = 0; j < num + 1; j++)
					{
						line += "-";
					}
				}
				else if (row % 2 != 0)
				{
					for (int j = 1; j < num + 1 + padding * 2; j++)
					{
						line += "-";
					}
				}

				line += "#";

			}
			else if (i == col - 1)
			{
				line += "#";
				for (int j = 0; j < row - 1; j++)
				{
					line += "-";
				}
				line += "#";
			}
			else
			{
				line += "|";
				int p = 1;
				do
				{
					line += " ";
					p++;
				} while (p <= padding);
				counter++;
				line += to_string(counter);
				line += " - ";
				line += text[k]; k++;
				int lenth = (row - line.length());
				p = 1;
				do
				{
					line += " ";
					p++;
				} while (p <= lenth);
				line += "|";
			}
			menu[i] = line;
		}
		return amount;
	}
protected:
	Menu()
	{
		createMenu();
	}
	Menu(string* text, int amount, int padding)
	{
		this->text = text;
		this->amount = amount;
		this->padding = padding;
		createMenu();
	}
	static Menu* menu_;

public:
	Menu(Menu& other) = delete;
	void operator=(const Menu&) = delete;
	static Menu* GetInstance();
	static Menu* GetInstance(string* text, int amount, int padding);
	void PrintMenu()
	{
		for (int i = 0; i < col; i++)
		{
			SetColor(i, LightGray);
			cout << menu[i] << endl;
		}
		SetColor(White, Black);
	}

};

Menu* Menu::menu_ = nullptr;

Menu* Menu::GetInstance()
{
	if (menu_ == nullptr) {
		menu_ = new Menu();
	}
	return menu_;
}
Menu* Menu::GetInstance(string* text, int amount, int padding)
{
	if (menu_ == nullptr) {
		menu_ = new Menu(text, amount, padding);
	}
	return menu_;
}

