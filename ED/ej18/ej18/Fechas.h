#pragma once
# ifndef FECHA
# define FECHA
# include <iostream>
# include <array>
# include <stdexcept>
class Fecha {
public:
	// Constructores
	Fecha() {}
	Fecha(int d, int m, int a) : dia(d), mes(m), anyo(a) {
		if (m <= 0 || m > MESES_ANYO) throw std::invalid_argument("Fecha invalida");
		else if (d <= 0 || d > DIAS_MES)
			throw std::invalid_argument("Fecha invalida");
	}
	// operador de asignacion
	Fecha& operator =(Fecha const& other) {
		if (this != &other) {
			dia = other.dia; mes = other.mes; anyo = other.anyo;
		}
		return *this;
	}
	// consultoras
	int get_dia() const { return dia; }
	int get_mes() const { return mes; }
	int get_anyo() const { return anyo; }
	// Numero de dias transcurridos desde la fecha del parametro ( anterior )
	// hasta la fecha del objeto ( posterior ).
	// -1 si la fecha del objeto es anterior a la del parametro .
	int operator - (Fecha const& fAnt) const {
		if (*this <= fAnt) return -1;
		else
			return (this->anyo - fAnt.anyo) * DIAS_ANYO + this->desdePAnyo() - fAnt.desdePAnyo() - 1;
	}
	// operadores de comparacion
	bool operator < (Fecha const& f) const {
		if (anyo < f.anyo) return true;
		else if (anyo > f.anyo) return false;
		else if (mes < f.mes) return true;
		else if (mes > f.mes) return false;
		else if (dia < f.dia) return true;
		else return false;
	}
	bool operator == (Fecha const& f) const {
		return anyo == f.anyo && mes == f.mes && dia == f.dia;
	}
	bool operator <= (Fecha const& f) const {
		return *this < f || *this == f;
	}
	bool operator > (Fecha const& f) const {
		return !(*this <= f);
	}
	bool operator >= (Fecha const& f) const {
		return !(*this < f);
	}
private:
	const int DIAS_MES = 30;
	const int MESES_ANYO = 12;
	const int DIAS_ANYO = DIAS_MES * MESES_ANYO;
	int dia, mes, anyo;
	// Calcula el numero de dias transcurridos desde principio de anyo .
	int desdePAnyo() const {
		return (this->mes - 1) * 30 + this->dia;
	}
};
inline std::ostream& operator << (std::ostream& out, Fecha const& f) {
	out << f.get_anyo() << ' ' << f.get_mes() << ' ' << f.get_dia() << '\n';
	return out;
}
inline std::istream& operator >> (std::istream& in, Fecha& f) {
	int a, m, d;
	in >> a >> m >> d;
	f = Fecha(a, m, d);
	return in;
}
# endif
