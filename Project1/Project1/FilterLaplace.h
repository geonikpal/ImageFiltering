#include"FilterBlur.h"
#ifndef Filter_LAP
#define filter_LAP
class FilterLaplace :public FilterBlur {
public:
	virtual Image operator << (const Image & image);
};
#endif // !Filter_LAP

