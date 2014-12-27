#ifndef _fraction_h
#define _fraction_h

#include <iostream>

template<typename T>
T gcd(T xx, T yy) {
	return yy != 0 ? gcd(yy, xx % yy) : xx;
}

template<typename T>
class fraction {
private:
	T a, b;
public:
	fraction(T x = (T)0, T y = (T)1) {
		if(y == 0) throw "Cannot divide by 0!";
		a = x;
		b = y;
	}

	T getNumerator()   { return a; }
	T getDenominator() { return b; }
	void setNumerator(T) {
		a = x;
	}
	void setDenominator(T) {
		if(y == 0) throw "Cannot divide by 0!";
		b = y;
	}
	void simplify() {
		T x = a, y = b;
		T r = gcd(x, y);

		a /= r;
		b /= r;
	}

	fraction<T>& operator++() {
		a += b;
		return *this;
	}
	fraction<T>& operator--() {
		a -= b;
		return *this;
	}
	friend fraction<T> operator-(const fraction<T>& f1) {
		fraction<T> temp(-f1.a, f1.b);
		return temp;
	}
	friend fraction<T> operator+(const fraction<T>& f1, const fraction<T>& f2) {
		fraction<T> temp;
		temp.a = f1.a * f2.b + f2.a * f1.b;
		temp.b = f1.b * f2.b;
		temp.simplify();
		return temp;
	}
	friend fraction<T> operator-(const fraction<T>& f1, const fraction<T>& f2) {
		fraction<T> temp;
		temp.a = f1.a * f2.b - f2.a * f1.b;
		temp.b = f1.b * f2.b;
		return temp;
	}
	friend fraction<T> operator*(const fraction<T>& f1, const fraction<T>& f2) {
		fraction<T> temp;
		temp.a = f1.a * f2.a;
		temp.b = f1.b * f2.b;
		temp.simplify();
		return temp;
	}
	friend fraction<T> operator/(const fraction<T>& f1, const fraction<T>& f2) {
		fraction<T> temp;
		temp.a = f1.a * f2.b;
		temp.b = f1.b * f2.a;
		temp.simplify();
		return temp;
	}

	friend fraction<T>& operator+=(fraction<T>& f1, const fraction<T>& f2) {
		f1.a = f1.a * f2.b + f2.a * f1.b;
		f1.b = f1.b * f2.b;
		f1.simplify();
		return f1;
	}
	friend fraction<T>& operator-=(fraction<T>& f1, const fraction<T>& f2) {
		f1.a = f1.a * f2.b - f2.a * f1.b;
		f1.b = f1.b * f2.b;
		f1.simplify();
		return f1;
	}
	friend fraction<T>& operator*=(fraction<T>& f1, const fraction<T>& f2) {
		f1.a = f1.a * f2.a;
		f1.b = f1.b * f2.b;
		f1.simplify();
		return f1;
	}
	friend fraction<T>& operator/=(fraction<T>& f1, const fraction<T>& f2) {
		f1.a = f1.a * f2.b;
		f1.b = f1.b * f2.a;
		f1.simplify();
		return f1;
	}

	friend bool operator==(const fraction<T>& f1, const fraction<T>& f2) {
		return f1.a * f2.b - f1.b * f2.a == 0;
	}
	friend bool operator!=(const fraction<T>& f1, const fraction<T>& f2) {
		return f1.a * f2.b - f1.b * f2.a != 0;
	}
	friend bool operator<=(const fraction<T>& f1, const fraction<T>& f2) {
		return f1.a * f2.b <= f1.b * f2.a <= 0;
	}
	friend bool operator>=(const fraction<T>& f1, const fraction<T>& f2) {
		return f1.a * f2.b >= f1.b * f2.a;
	}
	friend bool operator< (const fraction<T>& f1, const fraction<T>& f2) {
		return f1.a * f2.b < f1.b * f2.a;
	}
	friend bool operator> (const fraction<T>& f1, const fraction<T>& f2) {
		return f1.a * f2.b > f1.b * f2.a;
	}

	friend std::istream& operator>>(std::istream& in, fraction<T>& f1) {
		in >> f1.a >> f1.b;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, fraction<T>& f1) {
		out << f1.a << '/' << f1.b;
		return out;
	}
};

#endif