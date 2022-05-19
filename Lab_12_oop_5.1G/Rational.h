// Rational.h
#pragma once
#include <string>
#include "MyException.h"
#include "RationalException.h"
#include "Pair.h"
using namespace std;

class Rational : public Pair
{
public:
	Rational(int a = 1, int b = 1) throw(MyException);
	Rational(const Pair& p);
	Rational(const Rational& r);
	Rational& operator=(const Rational& r);

	Pair getPair() const { return *this; }
	void setPair(Pair p) throw(RationalException);

	operator string() const;
	friend ostream& operator<<(ostream& out, const Rational& r);
	friend istream& operator>>(istream& in, Rational& r) throw(exception);

	friend Rational operator+(const Rational& r1, const Rational& r2);
	friend Rational operator/(const Rational& r1, const Rational& r2);
	friend Rational operator-(const Rational& r1, const Rational& r2);
};
