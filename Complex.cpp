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
    real = r;
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
// Francesco Assalone
// Parameters : float i
// Returns : N/A
// 
// Sets the imaginary number for the Complex object
//========================================================
void Complex::setImag( float i )
{
    Imag = i;
}
//========================================================
// getImag
// Francesco Assalone
// Parameters : N/A
// Returns : Imaginary number "Imag"
// 
// Returns the imaginary number of the Complex object
//========================================================
float Complex::getImag() const 
{
    return Imag;

}
//========================================================
// assignment operator
//========================================================

//========================================================
// addition operators
// Francesco Assalone
// Parameters : float f
// Returns : A Complex object
// 
// Overloading the addition function to become usable 
// with floats.
//========================================================
Complex Complex::operator+ ( float f ) const 
{
    return Complex(real + f, Imag);
}
//========================================================
// Subtraction operators
// Francesco Assalone
// Parameters : Complex object
// Returns : Complex object with adjusted values
// 
// This function overloads the subtraction operator for the
// Complex class. It subtracts both the real and imaginary 
// parts of the input Complex object from the corresponding 
// parts of the current object.
//========================================================
Complex Complex::operator- (const Complex &c ) const 
{
    return Complex(real - c.getReal(), Imag + c.getImag());
}
//========================================================
// Multiplication operator
// Author: Francesco Assalone
// Parameters: const Complex &c - A Complex object
// Returns: Complex object with adjusted values
// 
// This function overloads the multiplication operator for the
// Complex class. It multiplies the current object with the 
// input Complex object 'c' following the rules of complex 
// number multiplication.
//========================================================
Complex Complex::operator* (const Complex &c) const 
{
    return Complex(real * c.getReal() - Imag * c.getImag(), real * c.getImag() + Imag * c.getReal()); 
}
//========================================================
// Division operator
// Author: Francesco Assalone
// Parameters: float f - A float value
// Returns: Complex object with adjusted values
// 
// This function overloads the division operator for the
// Complex class. It divides the real and imaginary parts 
// of the current object by the input float 'f', if 'f' is 
// not zero. If 'f' is zero, it outputs an error message.
//========================================================
Complex Complex::operator/ (float f) const 
{
    if (f == 0.0){
        cout << "Cannot divide by 0" << endl;
    }
    return Complex(real / f, Imag / f);
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