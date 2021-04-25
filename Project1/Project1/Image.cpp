
#include "Image.h"
#include"../ppm/ppm.h"
#include<iostream>
#include"Vec3.h"


using namespace std;


namespace imaging {

	Image::Image() :Array() {}


	Image::Image(unsigned int width, unsigned int height) : Array(width, height) {}


	Image::Image(unsigned int width, unsigned int height, const vector<Color>& data) : Array(width, height, data) {}

	Image::Image(const Image &src) : Array(src) {}

	Image::~Image() {
		vector<Color>().swap(buffer);
	}

	bool Image::load(const std::string & filename, const std::string & format) {
		string format_ = format;
		for (int i = 0; i < format_.length(); i++)
			format_[i] = toupper(format_[i]);

		const char* formatc = format_.c_str();//ready for comparison

		int dot = filename.find_last_of(".");
		std::string suffix = filename.substr(dot + 1, filename.length() - 1);
		string suffix_ = suffix;
		for (int i = 0; i < suffix_.length(); i++)
			suffix_[i] = toupper(suffix_[i]);
		const char* suffixc = suffix_.c_str(); //ready for comparison
		const char* filenamec = filename.c_str();

		if (strcmp(suffixc, formatc) == 0) {
			int widthu=0, heightu = 0;

			float* data_ = ReadPPM(filenamec, &widthu, &heightu);
			buffer.clear();
			for (int i = 0; i < widthu*heightu*3; i++) {
				if (i % 3 == 0) {
					Color data3;
					data3.r = data_[i];
					data3.g = data_[i + 1];
					data3.b = data_[i + 2];
					this->buffer.push_back(data3);	
				}
			}
			this->width = widthu;
			this->height = heightu;
			delete[] data_;
			return 1;
		}
		return 0;
	}


	bool Image::save(const std::string & filename, const std::string & format) {
		string format_ = format;
		for (int i = 0; i < format_.length(); i++)
			format_[i] = toupper(format_[i]);

		const char* formatc = format_.c_str();//ready for comparison

		int dot = filename.find_last_of(".");
		std::string suffix = filename.substr(dot + 1, filename.length() - 1);
		string suffix_ = suffix;
		for (int i = 0; i < suffix_.length(); i++)
			suffix_[i] = toupper(suffix_[i]);
		const char* suffixc = suffix_.c_str(); //ready for comparison
		const char* filenamec = filename.c_str();
		if (strcmp(suffixc, formatc) == 0) {
			float* dataw = new float[width*height * 3];
			int x = 0;
			for (int i = 0; i < width*height*3; i++) {
				if (i % 3 == 0) {
					dataw[i] = buffer[x].g;
					dataw[i + 1] = buffer[x].b;
					dataw[i + 2] = buffer[x].r;
					x++;
				}
				
			}
			WritePPM(dataw, this->width, this->height, filenamec);
			delete[] dataw;
			return 1;
		}
		return 0;
	}
		

	
}
	


