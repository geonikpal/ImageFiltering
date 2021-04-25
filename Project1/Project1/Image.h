//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2017 - 2018
//
//

#ifndef _IMAGE
#define _IMAGE
#include "Vec3.h"
#include"Array.h"
#include <string>


namespace imaging
{
	typedef math::Vec3<float> Color;

	class Image:public math::Array<Color>{
	
	public:
		Image();

		Image(unsigned int width, unsigned int height);

		
		Image(unsigned int width, unsigned int height, const vector<Color>& data);
		
		Image(const Image &src);

		~Image();

		bool load(const std::string & filename, const std::string & format);
		

		
		bool save(const std::string & filename, const std::string & format);

	};

}

#endif