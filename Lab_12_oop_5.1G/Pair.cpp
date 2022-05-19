#include "Pair.h"
#include <sstream>
#include <iostream>


Pair::Pair(int a, int b)
{
	setA(a);
	setB(b);
}

Pair::Pair(const Pair& p)
{
	*this = p;
}

Pair& Pair::operator=(const Pair& p)
{
	a = p.a;
	b = p.b;
	return *this;
}

Pair::operator string() const
{
	stringstream ss;
	ss << '(' << a << ", " << b << ')';
	return ss.str();
}

Pair operator-(const Pair& p1, const Pair p2)
{
	return Pair(p1.a - p2.a, p1.b - p2.b);
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << string(p);
	return out;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "����� �����: "; cin >> p.a;
	cout << "����� �����: "; cin >> p.b;
	return in;
}

