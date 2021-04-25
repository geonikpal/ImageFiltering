#include "Filter.h"
#include"FilterLinear.h"
Image FilterLinear::operator << (const Image & image) {
	
	vector<Color> data;
	Color p_;
	
		for (int h = 0; h < image.getHeight(); h++) {
			for (int w = 0; w < image.getWidth(); w++) {
			float valuer = a.r*image.getItem(w,h).r + c.r;

			if (valuer >= 0&&valuer<=1) {

			}
			else if (valuer < 0) {
				valuer = 0;
			}
			else if (valuer > 1) {
				valuer = 1;
			}
			
			float valueg = a.g*image.getItem(w, h).g + c.g;
			if (valueg >= 0 && valueg <= 1) {

			}
			else if (valueg < 0) {
				valueg = 0;
			}
			else if (valueg > 1) {
				valueg = 1;
			}

			float valueb = a.b*image.getItem(w, h).b + c.b;
			if (valueb >= 0 && valueb <= 1) {

			}
			else if (valueb < 0) {
				valueb = 0;
			}
			else if (valueb > 1) {
				valueb = 1;
			}

			 p_ = Color(valuer, valueg, valueb);
			data.push_back(p_);
			
		}
	}
	Image imageFiltered(image.getWidth(), image.getHeight(),data);
	return imageFiltered;
}

FilterLinear::FilterLinear(Color a_, Color c_) : a(a_), c(c_) {}
FilterLinear::FilterLinear():a(Color(0,0,0)),c(Color(0,0,0)) {}
FilterLinear::FilterLinear(const FilterLinear &src): a(src.a),c(src.c) {}




