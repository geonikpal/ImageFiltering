#include "Filter.h"
#ifndef FIG_H
#define FIG_H
class FilterGamma :public Filter {
protected:
	 float gamma;
public:
	Image operator << (const Image & image);
	FilterGamma();
	FilterGamma(float gamma_);
	FilterGamma(const FilterGamma & src);
	float getGamma() { return gamma; }


};
#endif