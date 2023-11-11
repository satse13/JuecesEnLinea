#pragma once
#include <stdexcept>
#include <math.h>
using namespace std;

template<typename T>
class Complejo {
protected:
	T real;
	T imaginario;
public:
 	Complejo(T r = 0, T i = 0) :real(r), imaginario(i) {}
	~Complejo() {}
	Complejo& operator =(const Complejo & other) {
		if (this != &other) {
			real = other.real;
			imaginario = other.imaginario;
		}
		return *this;
	}
	Complejo operator +(const Complejo & other) const {
		Complejo sol;

		sol.real = real  + other.real;
		sol.imaginario = imaginario + other.imaginario;
		return sol;
	}
	Complejo operator *(const Complejo & other) const {
		Complejo sol; 

		sol.real = real * other.real - imaginario * other.imaginario;
		sol.imaginario = real * other.imaginario + other.real * imaginario;
		
		return sol;
	}
	double mod() const {
		return sqrt(real * real + imaginario * imaginario);
	}
};
template <typename T>
inline istream& operator>> (istream& entrada, Complejo<T>& c) {

	T r; 
	T i;
	entrada >> r;
	entrada >> i;
	c = Complejo<T>(r, i);
	return entrada;
}