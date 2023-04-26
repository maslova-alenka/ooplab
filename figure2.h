#pragma once

#include<cassert>
#include<cmath>
#include<stdexcept>
#include<iostream>

namespace figure2 
{
	const float pi = 3.141592f;

	enum TypesFigure {
		ellipse=1,
		trapezoid=3,
		rectangle=2
	};

	class Point
	{
		float _x, _y;
	public:
		Point();
		Point(float x, float y);
		float get_x() const;
		float get_y() const;
		void set_x(float x);
		void set_y(float y);
	};

	class Figure;
	using FigurePtr = Figure*;

	class Figure
	{
		TypesFigure _type;
		Point _left_bottom;
		Point _right_top;

		Point _left_top;
		Point _right_bottom;

	public:
		Figure();
		Figure(TypesFigure type, Point left_bottom, Point right_top);

		Figure(TypesFigure type, Point left_bottom, Point right_top, Point left_top, Point right_bottom);

		TypesFigure get_fig_type() const;
		std::string get_type() const;

		Point get_left_bottom_point() const;
		Point get_left_top_point() const;
		Point get_right_top_point() const;
		Point get_right_bottom_point() const;

		float area()const;
		float perimetr()const;
		Figure min_fraiming_rectangle() const;
	};

	std::ostream& operator<<(std::ostream& stream, const Figure& f);

	class FigureList
	{
	private:
		FigurePtr* _figure;
		int _size;
	public:
		FigureList();
		FigureList(const FigureList& copy);
		FigureList& operator=(FigureList copy);
		const Figure& get_figure_by_index(int i) const;
		int get_size() const;
		const Figure& operator[](int index) const;
		Figure& operator[](int index);

		void add(const Figure& f);
		void insert(Figure f, int index);
		void remove(int index);
		void clear();
		void swap(FigureList& other);

		~FigureList();

		int figure_max_area() const;
	};

	std::ostream& operator<<(std::ostream& stream, const FigureList& f);

}