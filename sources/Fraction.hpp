#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
        void reduce()
        {
            int gcd = std::gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
        }

    public:
        Fraction();
        Fraction(int numeratorVal, int denominatorVal = 1);
        Fraction(float floatNumber);
        Fraction(double doubleNumber);
        Fraction(const Fraction &fraction);
        ~Fraction();
        Fraction& operator=(const Fraction& other);

        Fraction(Fraction &&other) noexcept;

        Fraction &operator=(Fraction &&other) noexcept;

        int getNumerator();
        int getDenominator();

        Fraction operator+(const Fraction &fractionRight) const;
        Fraction operator-(const Fraction &fractionRight) const;
        Fraction operator*(const Fraction &fractionRight) const;
        Fraction operator/(const Fraction &fractionRight) const;
        Fraction operator+=(const Fraction &fractionRight);
        Fraction operator-=(const Fraction &fractionRight);
        Fraction operator*=(const Fraction &fractionRight);
        Fraction operator/=(const Fraction &fractionRight);

        bool operator==(const Fraction &fractionRight) const;
        bool operator!=(const Fraction &fractionRight) const;
        bool operator<(const Fraction &fractionRight) const;
        bool operator<=(const Fraction &fractionRight) const;
        bool operator>(const Fraction &fractionRight) const;
        bool operator>=(const Fraction &fractionRight) const;

        friend bool operator==(const Fraction &fractionLeft, float floatNumberRight);
        friend bool operator!=(const Fraction &fractionLeft, float floatNumberRight);
        friend bool operator<(const Fraction &fractionLeft, float floatNumberRight);
        friend bool operator<=(const Fraction &fractionLeft, float floatNumberRight);
        friend bool operator>(const Fraction &fractionLeft, float floatNumberRight);
        friend bool operator>=(const Fraction &fractionLeft, float floatNumberRight);

        friend bool operator==(float floatNumberLeft, const Fraction &fractionRight);
        friend bool operator!=(float floatNumberLeft, const Fraction &fractionRight);
        friend bool operator<(float floatNumberLeft, const Fraction &fractionRight);
        friend bool operator<=(float floatNumberLeft, const Fraction &fractionRight);
        friend bool operator>(float floatNumberLeft, const Fraction &fractionRight);
        friend bool operator>=(float floatNumberLeft, const Fraction &fractionRight);

        friend Fraction operator+(float floatNumberLeft, const Fraction &rightSide);
        friend Fraction operator-(float floatNumberLeft, const Fraction &rightSide);
        friend Fraction operator*(float floatNumberLeft, const Fraction &rightSide);
        friend Fraction operator/(float floatNumberLeft, const Fraction &rightSide);

        Fraction operator+(float floatNumberRight) const;
        Fraction operator-(float floatNumberRight) const;
        Fraction operator*(float floatNumberRight) const;
        Fraction operator/(float floatNumberRight) const;
        Fraction operator+=(float floatNumberRight);
        Fraction operator-=(float floatNumberRight);
        Fraction operator*=(float floatNumberRight);
        Fraction operator/=(float floatNumberRight);

        Fraction operator++(int);
        Fraction &operator--();
        Fraction operator--(int);
        Fraction &operator++();

        friend std::ostream &operator<<(std::ostream &outputStream, const Fraction &fractionNumber);
        friend std::istream &operator>>(std::istream &istream, Fraction &fractionNumber);
    };

}