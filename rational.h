#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

using namespace std;

class Rational
{
public:
   Rational(int numerator, int denominator = 1);
   ~Rational() {}
   Rational(const Rational& copy);

   Rational& operator=(const Rational& other);
   Rational& operator=(int i);

   int numerator() const { return numer; }
   int denominator() const { return denom; }

   static int NWD(int a, int b)
   {
       if(b!=0)
           return NWD(b,a%b);
       return a;
   }

   static Rational normalize(const Rational& other)
   {
       Rational rational = Rational((int)other.numerator()/other.gcdND, (int)other.denominator()/other.gcdND);
       return rational;
   }

   static Rational normalized(int numerator, int denominator)
   {
       return Rational::normalize(Rational(numerator, denominator));
   }

   Rational operator+(const Rational& other) const;
   Rational operator-(const Rational& other) const;
   Rational operator*(const Rational& other) const;
   Rational operator/(const Rational& other) const;

   Rational operator+() const;
   Rational operator-() const;

   bool operator==(const Rational& other) const;
   bool operator>=(const Rational& other) const;
   bool operator<=(const Rational& other) const;
   bool operator>(const Rational& other) const;
   bool operator<(const Rational& other) const;

private:
   int numer;
   int denom;
   int gcdND;

   void initialize(int numerator, int denominator);

   friend std::ostream& operator<<(std::ostream &, const Rational &);
   friend std::istream& operator>>(std::istream &, Rational &);
};

Rational operator+(const Rational& r, int i);
Rational operator+(int i, const Rational& r);

Rational operator-(const Rational& r, int i);
Rational operator-(int i, const Rational& r);

Rational operator*(const Rational& r, int i);
Rational operator*(int i, const Rational& r);

Rational operator/(const Rational& r, int i);
Rational operator/(int i, const Rational& r);

#endif // RATIONAL_H
