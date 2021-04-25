#ifndef FBLUR
#define FBLUR
#include "Filter.h"

class FilterBlur :public Filter,public math::Array<float> {
protected:
	int N;
public:
	Image operator << (const Image & image);
	FilterBlur();
	FilterBlur(const FilterBlur& src);
	FilterBlur(int N_);
	int getN() {
		return N;
	}
};
#endif // !FBLUR