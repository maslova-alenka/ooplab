#include <figure2/menu_figure2.h>
#include "figure2/figure2.h"
#include <Windows.h>

using namespace figure2;
using namespace menu;
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	FigureList f;
	Figure figure;

	menu::text_menu();

	while (true)
	{
		int choice = menu::get_key();
		int index = 0;


		system("cls");
		menu::text_menu();


		if (choice == 57) {
			f.clear();
			break;
		}

		switch (choice)
		{

		case 49:
			f.add(create_figure());
			break;

		case 50:
			cout << "¬ведите индекс, по которому нужно вставить новую фигуру: ";
			cin >> index;
			f.insert(create_figure(), index);
			break;


		case 51:
			cout << "¬ведите индекс, по которому нужно удалить фигуру: ";
			cin >> index;
			f.remove(index);
			break;

		case 52:
			cout << "¬ведите индекс фигуры, у которой нужно вычислить периметр: ";
			cin >> index;
			cout << "периметр = " << f[index].perimetr() << endl;
			break;

		case 53:
			cout << "¬ведите индекс фигуры, у которой нужно вычислить площадь: ";
			cin >> index;
			cout << "площадь = " << f[index].area() << endl;
			break;

		case 54:
			cout << "¬ведите индекс фигуры, у которой нужно найти обрамл€ющий пр€моугольник: ";
			cin >> index;
			cout<< f[index].min_fraiming_rectangle() << endl;
			break;

		case 55:
			cout << "»ндекс фигуры с максимальной площадью"<< f.figure_max_area();
			break;

		case 56:
			cout << f;
			break;
		}

	}
	return 0;
}