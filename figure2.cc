#include <figure2/figure2.h>

#include<cassert>
#include<cmath>
#include<stdexcept>


using namespace figure2;
using namespace std;


Point::Point() : _x(0), _y(0) {}
Point::Point (const float x_1, const float y_1): _x(x_1),_y(y_1){}

float Point::get_x() const {
	return _x;
}
float Point::get_y() const {
	return _y;
}
void Point::set_x(float x) {
	_x = x;
}
void Point::set_y(float y) {
	_y = y;
}

Figure::Figure() {
	_type = rectangle;
	_right_bottom = Point(1, 1);
	_left_bottom = Point(-1, -1);
}

Figure::Figure(TypesFigure type, Point left_bottom, Point right_top) {
	_type = type;
	_left_bottom = left_bottom;
	_right_top = right_top;
}

Figure::Figure(TypesFigure type, Point left_bottom, Point left_top, Point right_top, Point right_bottom) {
	_type = type;
	_left_bottom = left_bottom;
	_left_top = left_top;
	_right_bottom = right_bottom;
	_right_top = right_top;
}


TypesFigure Figure::get_fig_type() const {
	return _type;
}

std::string Figure::get_type() const {
	switch (_type)
	{
	case TypesFigure::ellipse:
		return "Ellipse";
	case TypesFigure::trapezoid:
		return "Trapezoid";
	case TypesFigure::rectangle:
		return "Rectangle";
	default:
		throw runtime_error("Unknown type");
	}
}

Point Figure::get_left_bottom_point() const
{
	return _left_bottom;
};

Point Figure::get_left_top_point() const
{
	return _left_top;
};

Point Figure::get_right_bottom_point() const
{
	return _right_bottom;
};

Point Figure::get_right_top_point() const
{
	return _right_top;
};

float Figure:: area() const{
	float h, hor, bot_hor, vert;
	switch (_type) {
	case ellipse:
		vert = (_right_top.get_y() - _left_bottom.get_y()) / 2;
		hor = (_right_top.get_x() - _left_bottom.get_x()) / 2;
		return pi * vert * hor;

	case trapezoid:
		hor = _right_top.get_x() - _left_top.get_x();
		bot_hor = _right_bottom.get_x() - _left_bottom.get_x();
		h = _right_top.get_y() - _right_bottom.get_y();
		return ((hor + bot_hor) / 2) * h;

	case rectangle:
		vert = _right_top.get_y() - _left_bottom.get_y();
		hor = _right_top.get_x() - _left_bottom.get_x();
		return hor * vert;
	}
	return 0;
}

float Figure::perimetr() const {
	float h, hor, bot_hor, vert, side_tr_1, side_tr_2, d_x1, d_x2;
	switch (_type) {
	case ellipse:
		vert = (_right_top.get_y() - _left_bottom.get_y()) / 2;
		hor = (_right_top.get_x() - _left_bottom.get_x()) / 2;
		return 4 * (pi * hor * vert + (hor - vert) * (hor - vert)) / (vert + hor);

	case trapezoid:
		hor = _right_top.get_x() - _left_top.get_x();
		bot_hor = _right_bottom.get_x() - _left_bottom.get_x();
		h = _right_top.get_y() - _right_bottom.get_y();

		d_x1 = _left_top.get_x() - _left_bottom.get_x();
		d_x2 = _right_bottom.get_x() - _right_top.get_x();

		side_tr_1 = sqrt((d_x1 * d_x1) + (h * h));
		side_tr_2 = sqrt((d_x2 * d_x2) + (h * h));
		return side_tr_1 + side_tr_2 + hor + bot_hor;

	case rectangle:
		vert = _right_top.get_y() - _left_bottom.get_y();
		hor = _right_top.get_x() - _left_bottom.get_x();
		return 2 * (hor + vert);
	}
	return 0;
}

Figure Figure::min_fraiming_rectangle() const{
	if (_type == trapezoid) {
		return Figure(rectangle, _left_bottom, Point(_right_bottom.get_x(), _right_top.get_y()));
	}
	return Figure(rectangle, _left_bottom, _right_top);
}

std::ostream& figure2::operator<<(std::ostream& stream, const Figure& f) {
	if (f.get_type() == "Trapezoid")
		stream << "“ип фигуры: "<< f.get_type() << " \n "
		<< " Ћева€ нижн€€: x = " << f.get_left_bottom_point().get_x() << " y = " << f.get_left_bottom_point().get_y() << "\n"
		<< " Ћева€ верхн€€: x = " << f.get_left_top_point().get_x() << " y = " << f.get_left_top_point().get_y() << "\n"
		<< " ѕрава€ нижн€€: x = " << f.get_right_bottom_point().get_x() << " y = " << f.get_right_bottom_point().get_y() << "\n"
		<< " ѕрава€ верхн€€: x = " << f.get_right_top_point().get_x() << " y = " << f.get_right_top_point().get_y() << "\n" << endl;

	else
		stream << "“ип фигуры: " << f.get_type() << " \n "
		<< " Ћева€ нижн€€: x = " << f.get_left_bottom_point().get_x() << " y = " << f.get_left_bottom_point().get_y() << "\n"
		<< " ѕрава€ верхн€€: x = " << f.get_right_top_point().get_x() << " y = " << f.get_right_top_point().get_y()  << "\n" << endl;
		return stream;
}
