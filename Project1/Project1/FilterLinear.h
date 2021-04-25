#include "Filter.h"
#ifndef LINFILT_H
#define LINFILT_H

class FilterLinear :public Filter {
protected:
	const Color a, c;
	public:
	Image operator << (const Image & image);
	FilterLinear();
	FilterLinear(const FilterLinear &src);
	FilterLinear(Color a_, Color c_);
	Color geta() { return a; }
	Color getc() { return c; }
};
#endif // !LINFILT_H
