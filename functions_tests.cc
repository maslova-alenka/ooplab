#include <figure2/figure2.h>
#include <gtest/gtest.h>

using namespace figure2;
using namespace std;

TEST(FiguresTests, PointDefaultConstructorTest2) {
    Point p = Point();
    EXPECT_EQ(p.get_x(), 0);
}

TEST(PointTests, PointTest3) {
    Point p = Point(4, 9);
    EXPECT_EQ(p.get_x(), 4);
    EXPECT_EQ(p.get_y(), 9);
}

TEST(FiguresTests, FigureConstructorTypeTest4) {
    Point left_top = Point(-3, 3);
    Point right_top = Point(1, 3);
    Point right_bottom = Point(5, -2);
    Point left_bottom = Point(-5, -2);
    Figure f = Figure(trapezoid, left_bottom, left_top, right_top, right_bottom);
    EXPECT_EQ(f.get_fig_type(), trapezoid);
    EXPECT_EQ(f.get_left_top_point().get_x(), -3);
    EXPECT_EQ(f.get_left_top_point().get_y(), 3);
}


TEST(FigureTest, EllipseAreaTest5) {
    Point left_bottom;
    Point right_top;

    left_bottom = Point(-2, 0);
    right_top = Point(2, 3);
    Figure f = Figure(ellipse, left_bottom, right_top);
    EXPECT_NEAR(f.area(), 9.4, 0.1);
}

TEST(FiguresTest, TrapezoidTest6) {
    Point left_bottom;
    Point left_top;
    Point right_top;
    Point right_bottom;

    right_top = Point(1, 3);
    left_top = Point(-3, 3);
    left_bottom = Point(-5, -2);
    right_bottom = Point(5, -2);
    Figure f = Figure(trapezoid, left_bottom, left_top, right_top, right_bottom);
    EXPECT_EQ(f.area(), 35);
}

TEST(FiguresTest, RectangleTest7) {
    Point left_bottom;
    Point right_top;

    right_top = Point(3, 2);
    left_bottom = Point(-2, -2);
    Figure f = Figure(rectangle, left_bottom, right_top);
    EXPECT_EQ(f.area(), 20);
}

TEST(FiguresTest, EllipsePerimetr8) {
    Point left_bottom;
    Point right_top;

    left_bottom = Point(-3, 0);
    right_top = Point(3, 2);
    Figure f = Figure(ellipse, left_bottom, right_top);
    EXPECT_NEAR(f.perimetr(), 13.4, 0.1);
}


TEST(FiguresTest, TrapezoidTest9) {
    Point left_bottom;
    Point left_top;
    Point right_top;
    Point right_bottom;

    right_top = Point(1, 2);
    left_top = Point(-3, 2);
    left_bottom = Point(-7, -1);
    right_bottom = Point(5, -1);
    Figure f = Figure(trapezoid, left_bottom, left_top, right_top, right_bottom);
    EXPECT_EQ(f.perimetr(), 26);
}

TEST(FiguresTest, RectangleTest10) {
    Point left_bottom;
    Point right_top;

    right_top = Point(3, 2);
    left_bottom = Point(-2, -2);
    Figure f = Figure(rectangle, left_bottom, right_top);
    EXPECT_EQ(f.perimetr(), 18);
}

TEST(FiguresTest, MinRecRecTest11) {
    Point left_bottom;
    Point right_top;

    right_top = Point(3, 2);
    left_bottom = Point(-2, -2);
    Figure f = Figure(rectangle, left_bottom, right_top);
    EXPECT_EQ(f.min_fraiming_rectangle().get_left_bottom_point().get_x(), -2);
    EXPECT_EQ(f.min_fraiming_rectangle().get_right_top_point().get_y(), 2);

}

TEST(FiguresTest, MinRecEllTest12) {
    Point left_bottom;
    Point right_top;

    left_bottom = Point(-3, 0);
    right_top = Point(3, 2);
    Figure f = Figure(ellipse, left_bottom, right_top);
    EXPECT_EQ(f.min_fraiming_rectangle().get_left_bottom_point().get_x(), -3);
    EXPECT_EQ(f.min_fraiming_rectangle().get_right_top_point().get_y(), 2);

}

TEST(FiguresTest, MinRecTrapTest13) {
    Point left_bottom;
    Point left_top;
    Point right_top;
    Point right_bottom;

    right_top = Point(1, 3);
    left_top = Point(-3, 3);
    left_bottom = Point(-5, -2);
    right_bottom = Point(5, -2);

    Figure f = Figure(trapezoid, left_bottom, left_top, right_top, right_bottom);
    EXPECT_EQ(f.min_fraiming_rectangle().get_left_bottom_point().get_x(), -5);
    EXPECT_EQ(f.min_fraiming_rectangle().get_right_top_point().get_y(), 3);
}

TEST(FigureListTests, FigureListTest14) {
    FigureList figurelist;

    Point left_bottom;
    Point left_top;
    Point right_top;
    Point right_bottom;

    right_top = Point(1, 3);
    left_top = Point(-3, 3);
    left_bottom = Point(-5, -2);
    right_bottom = Point(5, -2);
    figurelist.add(Figure(trapezoid, left_bottom, left_top, right_top, right_bottom));

    left_bottom = Point(-3, 0);
    right_top = Point(3, 2);
    figurelist.add(Figure(ellipse, left_bottom, right_top));

    right_top = Point(3, 2);
    left_bottom = Point(-2, -2);
    figurelist.add(Figure(rectangle, left_bottom, right_top));

    left_bottom = Point(-4.5, -2);
    left_top = Point(0, 2);
    right_top = Point(2, 2);
    right_bottom = Point(3.5, -2);
    figurelist.add(Figure(trapezoid, left_bottom, left_top, right_top, right_bottom));

    EXPECT_EQ(figurelist[3].get_fig_type(), trapezoid);
    EXPECT_EQ(figurelist[0].get_left_bottom_point().get_x(), -5);
    EXPECT_EQ(figurelist[1].get_right_top_point().get_y(), 2);
}

TEST(FigureListTests, MaxAreaTest15) {
    FigureList figurelist;

    Point left_bottom;
    Point left_top;
    Point right_top;
    Point right_bottom;

    right_top = Point(1, 3);
    left_top = Point(-3, 3);
    left_bottom = Point(-5, -2);
    right_bottom = Point(5, -2);
    figurelist.add(Figure(trapezoid, left_bottom, left_top, right_top, right_bottom));

    left_bottom = Point(-3, 0);
    right_top = Point(3, 2);
    figurelist.add(Figure(ellipse, left_bottom, right_top));

    right_top = Point(3, 2);
    left_bottom = Point(-2, -2);
    figurelist.add(Figure(rectangle, left_bottom, right_top));

    left_bottom = Point(-4.5, -2);
    left_top = Point(0, 2);
    right_top = Point(2, 2);
    right_bottom = Point(3.5, -2);
    figurelist.add(Figure(trapezoid, left_bottom, left_top, right_top, right_bottom));


    EXPECT_EQ(figurelist.figure_max_area(), 0);
}


TEST(ExceptionTests, IndexOutTest16) {
    FigureList figure = FigureList();
    EXPECT_THROW(figure[-1].area(), std::runtime_error);
    EXPECT_THROW(figure[10].area(), std::runtime_error);
}

TEST(ExceptionTests, EmptyTest17) {
    FigureList figure = FigureList();
    EXPECT_THROW(figure.remove(1), std::runtime_error);
}