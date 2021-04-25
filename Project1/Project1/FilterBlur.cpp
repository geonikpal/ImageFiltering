#include"FilterBlur.h"
#include<cmath>
Image FilterBlur::operator << (const Image & image) {
	Image imagefiltered=Image(image.getWidth(),image.getHeight());
	vector<float> data;
	vector<Color> datablur;
	for (int size = 0; size < image.getWidth()*image.getHeight(); size++) {
		data.push_back(1 / pow(N, 2));
	}
	Array<float> f=Array(image.getWidth(),image.getHeight(),data);

	for (int j = 0; j< image.getHeight(); j++) {
		for (int i= 0; i < image.getWidth(); i++){
			float sr = 0.f;
			float sg = 0.f;
			float sb = 0.f;
			
			if (N == 1) {
				for (int m1 = -0.5; m1 <= N; m1++) {
					for (int n1 = -0.5; n1 <= N; n1++) {
						if (i + m1 >= 0 && i + m1 < image.getWidth() && j + n1 >= 0 && j + n1 < image.getHeight() && m1 + N / 2 >= 0 && m1 + N / 2 < image.getWidth() && n1 + N / 2 >= 0 && n1 + N / 2 < image.getWidth() && i + m1 != i&&j + n1 != j) {
							sr = sr + image.getItem(i + m1, j + n1).r*f.getItem(m1 + N / 2, n1 + N / 2);
							sg = sg + image.getItem(i + m1, j + n1).g*f.getItem(m1 + N / 2, n1 + N / 2);
							sb = sb + image.getItem(i + m1, j + n1).b*f.getItem(m1 + N / 2, n1 + N / 2);
						}
					}
				}
			}
			else {
				for (float m = -N / 2; m <= N / 2; m++) {
					for (float n = -N / 2; n <= N / 2; n++) {
						if (i + m >= 0 && i + m < image.getWidth() && j + n >= 0 && j + n < image.getHeight() && m + N / 2 >= 0 && m + N / 2 < image.getWidth() && n + N / 2 >= 0 && n + N / 2 < image.getWidth() && i + m != i&&j + n != j) {
							sr = sr + image.getItem(i + m, j + n).r*f.getItem(m + N / 2, n + N / 2);
							sg = sg + image.getItem(i + m, j + n).g*f.getItem(m + N / 2, n + N / 2);
							sb = sb + image.getItem(i + m, j + n).b*f.getItem(m + N / 2, n + N / 2);
						}

					}
				}
			}
				Color newpix = Color(sr, sg, sb);
				newpix.clampToLowerBound(0);
				newpix.clampToUpperBound(1);
				datablur.push_back(newpix);
		}
	}
	imagefiltered.setData(datablur);
	return imagefiltered;
}
	FilterBlur::FilterBlur():N(2) {}
	FilterBlur::FilterBlur(const FilterBlur& src) {
		N = src.N;
	}
	FilterBlur::FilterBlur(int N_):N(N_){}
