#ifndef _ARRAY_H
#define _ARRAY_H
#include<vector>


using namespace std;
namespace math {
	template <typename T>
	class Array {
	public:

	protected:
		vector<T> buffer;                            

		unsigned int width, 						 
			height;		                 

	public:
		
		const unsigned int getWidth() const { return width; }

		
		const unsigned int getHeight() const { return height; }

		
		vector<T> getVector();

		
		T getItem(unsigned int x, unsigned int y) const;

		
		void setItem(unsigned int x, unsigned int y, T & value);

		
		void setData(const vector<T> & data);
		
		Array();

		
		Array(unsigned int width, unsigned int height);

		Array(unsigned int width, unsigned int height, const vector<T>& data);

		
		Array(const Array &src);

		
		~Array();
		
		Array<T> & operator= (const Array<T> & right);

		T& operator() (unsigned int i,unsigned int j);

		
	};
	
	template <typename T>
	vector<T> Array<T>::getVector() {
		return buffer;
	}

	template <typename T>
	T Array<T>::getItem(unsigned int x, unsigned int y) const {
		if (x > width || y > height || x < 0 || y < 0) {
			std::cerr << "ERROR\n";
			return 0;
		}
		return buffer[x + y*width];
	}

	template <typename T>
	void Array<T>::setItem(unsigned int x, unsigned int y, T & value) {
		if (x > width || y > height || x < 0 || y < 0) {
			std::cerr << "ERROR\n";
			return;
		}
		buffer[x + y*width] = value;
	}

	template <typename T>
	void Array<T>::setData(const vector<T> & data) {
		if (width == 0 || height == 0 ) return;
		buffer.clear();
		for (int i = 0; i < data.size(); i++) {
			buffer.push_back(data[i]);
		}

	}

	template <typename T>
	Array<T>::Array() {
		width = 0;
		height = 0;
		buffer.clear();
	}

	template <typename T>
	Array<T>::Array(unsigned int width, unsigned int height) {
		this->width = width;
		this->height = height;
	}

	template <typename T>
	Array<T>::Array(unsigned int width, unsigned int height, const vector<T>& data) {
		this->width = width;
		this->height = height;
		setData(data);
	}

	template <typename T>
	Array<T>::Array(const Array &src) {
		width = src.width;
		height = src.height;
		buffer.clear();
		for (int i = 0; i<src.buffer.size(); i++)
			buffer.push_back(src.buffer[i]);
	}

	template <typename T>
	Array<T>::~Array() {
		vector<T>().swap(buffer);
	}

	template <typename T>
	Array<T> & Array<T>::operator=(const Array<T> & right) {
		if (&right == this)
			return *this;
		width = right.width;
		height = right.height;
		buffer.clear();
		for (int i = 0; i < right.buffer.size(); i++) {
			buffer.push_back(right.buffer[i]);
		}
		return *this;
	}

	template <typename T>
	T& Array<T>::operator ()(unsigned int i, unsigned int j) {

		T& ref = buffer[j*width + i];
		return ref;
	}

}//namespace math

#endif
