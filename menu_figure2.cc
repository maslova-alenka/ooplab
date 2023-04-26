#include <figure2/menu_figure2.h>
#include <string.h>

using namespace figure2;
using namespace menu;
using namespace std;

void menu::text_menu()
{
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                Меню                               |" << endl;
	cout << " —-------------------------------------------------------------------" << endl;
	cout << " | 1 - добавить фигуру в конец                                       |" << endl;
	cout << " | 2 - добавить фигуру по индексу                                    |" << endl;
	cout << " | 3 - удалить фигуру по индексу                                     |" << endl;
	cout << " | 4 - рассчитать периметр                                           |" << endl;
	cout << " | 5 - рассчитать площадь                                            |" << endl;
	cout << " | 6 - вычислить минимальный обрамляющий прямоугольник               |" << endl;
	cout << " | 7 - поиск в наборе первой фигуры с максимальной площадью          |" << endl;
	cout << " | 8 - вывести список фигур                                          |" << endl;
	cout << " | 9 - выйти из системы                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}




int menu::get_key()
{
	int key = _getch();
	if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 57))
		return key;
}

Figure menu::create_figure()
{
	Figure f;
	int type;
	Point left_bottom;
	Point left_top;
	Point right_top;
	Point right_bottom;
	float x1, x2, y1, y2, x3, x4, y3, y4;


	cout << "Введите тип фигуры (1-Эллипс 2-Прямоугольник 3-Трапеция): ";
	cin >> type;
	if (type != 1 && type != 2 && type != 3)
		throw runtime_error("Invalid type");
	if (type == 1) {
		cout << " Введите левую нижнюю точку \n " << "x=";
		cin >> x1;
		cout << "y=";
		cin >> y1;

		cout << " Введите правую верхнюю точку \n " << "x=";
		cin >> x2;
		cout << "y=";
		cin >> y2;
		return Figure(ellipse, Point(x1, y1), Point(x2, y2));
	}
	if (type == 2) {
		cout << "Введите левую нижнюю точку \n " << "x=";
		cin >> x1;
		cout << "y=";
		cin >> y1;

		cout << "Введите правую верхнюю точку \n " << "x=";
		cin >> x2;
		cout << "y=";
		cin >> y2;
		return Figure(rectangle, Point(x1, y1), Point(x2, y2));
	}
	if (type == 3) {
		cout << "Трапеция ";
		cout << "Введите левую нижнюю точку \n " << "x=";
		cin >> x1;
		cout << "y=";
		cin >> y1;

		cout << " Введите правую верхнюю точку \n " << "x=";
		cin >> x2;
		cout << "y=";
		cin >> y2;

		cout << "Введите левую верхнюю точку \n " << "x=";
		cin >> x3;
		cout << "y=";
		cin >> y3;

		cout << "Введите правую нижнюю точку \n " << "x=";
		cin >> x4;
		cout << "y=";
		cin >> y4;
		return Figure(trapezoid, Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4));

	}
}