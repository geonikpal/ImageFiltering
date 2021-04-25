#include <iostream>
#include "Array.h"
#include "Image.h"
#ifndef FILTER_H
#define FILTER_H
using namespace imaging;
class Filter {
protected:
	virtual Image operator << (const Image & image) = 0;

};
#endif // !FILTER_H
