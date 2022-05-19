// Rational.cpp
#include "Rational.h"
#include <iostream>
#include <sstream>
using namespace std;


Rational::Rational(int a, int b) : Pair(a, b) 
{
	if (b == 0)
		throw new MyException("b == 0");
}

Rational::Rational(const Pair& p)
{
	setA(p.getA());
	setB(p.getB());
}

Rational::Rational(const Rational& p)
{
	*this = p;
}

Rational& Rational::operator=(const Rational& p)
{
	setA(p.getA());
	setB(p.getB());
	return *this;
}


void Rational::setPair(Pair p) throw(RationalException)
{
	if (p.getB() == 0)
		throw RationalException("b == 0");
	*this = p;
}

Rational::operator string() const
{
	stringstream ss;
	ss << getA() << '/' << getB();
	return ss.str();
}

ostream& operator<<(ostream& out, const Rational& r)
{
	out << string(r);
	return out;
}

istream& operator>>(istream& in, Rational& r)
{
	int a, b;
	cout << "Чисельник: "; cin >> a;
	cout << "Знаменник: "; cin >> b;
	if (b == 0)
		throw exception("b == 0");
	r.setA(a);
	r.setB(b);
	return in;
}

Rational operator+(const Rational& r1, const Rational& r2)
{
	return Rational({ r1.getA() * r2.getB() + r1.getB() * r2.getA(), r1.getB() * r2.getB() });
}

Rational operator/(const Rational& r1, const Rational& r2)
{
	return Rational({ r1.getA() * r1.getB(), r2.getA() * r2.getB() });
}

Rational operator-(const Rational& r1, const Rational& r2)
{
	return Rational({ r1.getA() * r2.getB() - r1.getB() * r2.getA(), r1.getB() * r2.getB() });
}
