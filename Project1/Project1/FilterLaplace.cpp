#include "FilterLaplace.h"
Image FilterLaplace::operator << (const Image & image) {
	float f[3][3] = { { 0,1,0 },{1,-4,1},{0,1,0} };
	Image imagefiltered = Image(image.getWidth(), image.getHeight());
	vector<Color> datalaplace;
	for (int j = 0; j < image.getHeight(); j++) {
		for (int i = 0; i < image.getWidth(); i++) {
			float sr = 0.f;
			float sg = 0.f;
			float sb = 0.f;
			for (int m =-1; m <= 1; m++) {
					for (int n = -1; n <=1; n++) {
						if (i + m >= 0 && i + m < image.getWidth() && j + n >= 0 && j + n < image.getHeight() && m + 1>= 0 && m + 1 < image.getWidth() && n + 1 >= 0 && n + 1 < image.getWidth()) {
							sr = sr + image.getItem(i + m, j + n).r*f[m + 1][n + 1];
							sg = sg + image.getItem(i + m, j + n).g*f[m + 1][n + 1];
							sb = sb + image.getItem(i + m, j + n).b*f[m + 1][n + 1];
						}
					}
			}
			Color newpix = Color(sr, sg, sb);
			newpix.clampToLowerBound(0);
			newpix.clampToUpperBound(1);
			datalaplace.push_back(newpix);
	
		}
	}
	imagefiltered.setData(datalaplace);
	return imagefiltered;
 }