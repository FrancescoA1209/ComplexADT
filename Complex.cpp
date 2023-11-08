//========================================================
// Francesco Assalone
// Complex.cpp
// November 2023
// This file contains the class methods for the
// Complex number class.
//========================================================

#include "Complex.h"
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

float real;
float Imag;

Complex::Complex ( const Complex &c ) 
{ 
    a = c.a; 
    b = c.b; 
}

Complex::Complex ( float x, float y ) 
{ 
    a = x; b = y; 
}

//========================================================
// setReal access method
//========================================================
void Complex::setReal ( float r )
{
    float real = r;
}

//========================================================
// getReal access method
// Francesco Assalone
// Parameters : void ( n/a )
// Returns : float realNum
// 
// Gets the real part of the complex number
//========================================================
float Complex::getReal ( void ) const
{  
    return real;
}

//========================================================
// setImag
//========================================================
void Complex::setImag( float i )
{
    Imag = i;
}
//========================================================
// getImag
//========================================================
float Complex::getImag () const 
{
    return Imag;

}
//========================================================
// assignment operator
//========================================================

//========================================================
// addition operators
//========================================================
Complex Complex::operator+ ( float f ) const 
{
    return Complex(real + f, Imag);
}
//========================================================
// subtraction operators
//========================================================
Complex Complex::operator- (const Complex &c ) const 
{
    return Complex(real - c.getReal(), Imag + c.getImag());
}
//========================================================
// multiplication operators
//========================================================
Complex Complex::operator*(const Complex &c) const 
{ 
    return Complex(real * c.getReal() - Imag * c.getImag(), real * c.getImag() + Imag * c.getReal()); 
}
//========================================================
// Division Operator
// Francesco Assalone
// Parameters : Complex object "C"
// Returns : Complex object with the correctly calculated real and imaginary parts
// 
// This function supports division between two complex numbers
//========================================================
Complex Complex::operator/ ( float f ) const{
    if (f == 0.0){
        cout << "Cannot divide by 0" << endl;
    }
    return Complex(real / f, Imag / f)
}
//========================================================
// exponentiation
//========================================================

//========================================================
// operator~
//========================================================

//========================================================
// abs
//========================================================

//========================================================
// Equality operator
// Francesco Assalone
// Parameters : Complex class variable "c"
// Returns : Whether or not the two complex are equal.
//
// This function will aims to determine whether or not
// both real and imaginary parts are equal
//========================================================
bool Complex::operator== ( const Complex &c ) const
{
    return real == c.getReal() && Imag == c.getImag();
}
//========================================================
// Inequality operator
// Francesco Assalone
// Parameters : Inequality Complex variable "c"
// Returns : Will return False if the two complex
// numbers are equal and True if the two complex
// numbers are not equal.
//========================================================
bool Complex::operator!= ( const Complex &c) const
{
    return !(real == c.getReal() && Imag == c.getImag());
}
//========================================================
// Overload >> for cin
// Francesco Assalone
// 
// Parameters :
// istream &in - Reading from the input stream where we 
// get the real and imaginary numbers.
//
// Complex &c - Complex object that will be assigned
// real and imaginary parts.
//========================================================
istream& operator>>(istream &in, Complex &c) {
    double r, i;
    in >> r >> i;
    c.setReal(r);
    c.setImag(i);
    return in;
}
//========================================================
// overload << for cout
//========================================================