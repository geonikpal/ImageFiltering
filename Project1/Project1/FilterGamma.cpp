#include "FilterGamma.h"
#include <cmath>
Image FilterGamma::operator << (const Image & image) {
	Color p_;
	vector<Color> data;
	for (int h = 0; h < image.getHeight(); h++) {
		for (int w = 0; w < image.getWidth(); w++) {
			float valuer = image.getItem(w, h).r;
			valuer=pow(valuer, gamma);
			if (valuer >= 0 && valuer <= 1) {

			}
			else if (valuer < 0) {
				valuer = 0;
			}
			else if (valuer > 1) {
				valuer = 1;
			}

			float valueg = image.getItem(w, h).g;
			valueg = pow(valueg, gamma);
			if (valueg >= 0 && valueg <= 1) {

			}
			else if (valueg < 0) {
				valueg = 0;
			}
			else if (valueg > 1) {
				valueg = 1;
			}

			float valueb = image.getItem(w, h).b;
			valueb = pow(valueb, gamma);
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
	Image imageFiltered(image.getWidth(), image.getHeight(), data);
	return imageFiltered;
}
FilterGamma::FilterGamma():gamma(1) {}
FilterGamma::FilterGamma(float gamma_):gamma(gamma_){}
FilterGamma::FilterGamma(const FilterGamma & src) {
	gamma = src.gamma;
}