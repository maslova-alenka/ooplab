#include <figure2/figure2.h>

using namespace figure2;
using namespace std;

FigureList::FigureList():
	_figure(nullptr),
	_size(0)
{}

FigureList::~FigureList() {
	clear();
}

void FigureList::swap(FigureList& other){
	std::swap(_size, other._size);
	std::swap(_figure, other._figure);
}

FigureList::FigureList(const FigureList& copy) :
	_figure(new FigurePtr[copy._size]),
	_size(copy._size)
{
	for (int i = 0; i < _size; i++)
		_figure[i] = new Figure(*copy._figure[i]);
}

FigureList& FigureList::operator=(FigureList copy) {
	swap(copy);
	return *this;
}

const Figure& FigureList::get_figure_by_index(int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[FigureList::get_figure_by_index] Invalid index");
	return *_figure[index];
}

int FigureList::get_size() const {
	return _size;
}

const Figure& FigureList::operator[](int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[FigureList::operator[]] Index is out of range");
	return *_figure[index];
}

Figure& FigureList::operator[](int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("Invalid index");
	return *_figure[index];
}

void FigureList::add(const Figure& f) {
	auto figure = new Figure*[_size + 1];
	for (int i = 0; i < _size; i++)
		figure[i] = _figure[i];
	figure[_size] = new Figure(f);
	delete[] _figure;
	_figure = figure;
	++_size;
}

void FigureList::insert(Figure f, int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[FigureList::insert] Invalid index");
	auto figure = new Figure * [_size + 1];
	for (int i = 0; i < _size; ++i)
		figure[i] = _figure[i];
	for (int i = _size; i > index; --i)
		figure[i] = figure[i - 1];
	figure[index] = new Figure(f);
	delete[] _figure;
	_figure = figure;
	++_size;
}

void FigureList::remove(int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[FigureList::remove] FigureList is empty");
	delete _figure[index];
	for (int i = index; i < _size - 1; i++)
		_figure[i] = _figure[i + 1];
	--_size;
}

void FigureList::clear() {
	if (_figure == nullptr)
		return;
	for (int i = 0; i < _size; i++)
		delete _figure[i];
	_size = 0; 
	delete[] _figure;
	_figure = nullptr;
}

std::ostream& figure2::operator<<(std::ostream& stream, const FigureList& f) {
	stream << f.get_size() << " figure: " << endl;
	for (int i = 0; i < f.get_size(); ++i)
		cout << "  " << i + 1 << ") " << f[i];
	return stream;
}

int FigureList::figure_max_area() const {
	if (_size <= 0)
		return -1;
	int index = 0;
	float max_area = _figure[0]->area();
	for (int i = 1; i < _size; i++) {
		float cur_area = _figure[i]->area();
		if (cur_area > max_area) {
			index = i;
			max_area = cur_area;
		}
	}
	return index;
}