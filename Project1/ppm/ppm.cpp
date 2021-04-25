
#pragma once
#include<iostream>
#include<ostream>
#include<string>
#include<vector>
#include <sstream>
#include<fstream>
#include "ppm.h"
#include"../Project1/Image.h"

using namespace std;
namespace imaging {

	float * ReadPPM(const char * filename, int * w, int * h) {

		ifstream file(filename, ios_base::in | ios_base::binary);

		//Checking if the file opened
		if (!file.is_open()) {
			printf("Unable to open %s!\n", filename);
			return nullptr;
		}

		string format;
		int value = 0;
		//save the data to 4 variables
		file >> format >> *w >> *h >> value;
		//Checking format
		if (format == "P6") {
			
			if (value <= 0 || value > 255) {
				cerr << "Error ";
				return nullptr;
			}
			
			else {

				char ch;
				//size of the array
				int size = *w*(*h) * 3;

				float *pointer = new float[size];
				for (int i = 0; i < size; i++) {
					file.get(ch);
					pointer[i] = (unsigned char)ch / (float)value;
				}
				cout << "Load completed successfully" << endl;
				printf("Image dimensions are:%i X %i \n", *w, *h);
		
				
				return pointer;
			}
	 }
	  else {
			cout << "Load failed" << endl;
			return nullptr;
		}

	}
	bool WritePPM(const float * data, int w, int h, const char * filename) {
		ofstream file(filename, ios_base::out | ios_base::binary);

		if (!file.is_open()) {
			printf("Unable to open %s!\n", filename);
			return 0;
		}

		string width=to_string(w);
		string height = to_string(h);
		//entering the basic data
		file <<"P6 " << width+" " << height+" " << "255 ";
		file.flush(); //make sure the data passed
		int size = w*h*3;//size of data
		//passing the binary data into the file
		for (int i = 0; i < size; i++) {
			unsigned char c = data[i]* 255;
			file << c;
		}
		file.flush(); //make sure the data passed
		cout << "Saving completed successfully\n";
		
	}


}
	 
	


	
	
	 
	


