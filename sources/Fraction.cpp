#include "Fraction.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <limits>

namespace ariel
{
    Fraction::Fraction()
    {
        numerator = 0;
        denominator = 1;
    }

    Fraction::Fraction(int numeratorVal, int denominatorVal)
    {
        int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

        if (denominatorVal == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        if (denominatorVal < 0)
        {
            numeratorVal *= -1;
            denominatorVal *= -1;
        }
        if (numeratorVal > max_int || numeratorVal < min_int || denominatorVal > max_int || denominatorVal < min_int)
        {
            throw std::overflow_error("Overflow error");
        }
        numerator = numeratorVal;
        denominator = denominatorVal;
        reduce();
    }

    Fraction::Fraction(float floatNumber)
    {
        int sign = (floatNumber < 0) ? -1 : 1;
        floatNumber = std::abs(floatNumber);
        int whole = (int)floatNumber;
        int decimal = (int)std::round((floatNumber - whole) * 1000);
        numerator = (whole * 1000 + decimal) * sign;
        denominator = 1000;
        reduce();
    }

    Fraction::Fraction(double doubleNumber)
    {
        int sign = (doubleNumber < 0) ? -1 : 1;
        doubleNumber = std::abs(doubleNumber);
        int whole = (int)doubleNumber;
        int decimal = (int)std::round((doubleNumber - whole) * 1000);
        numerator = (whole * 1000 + decimal) * sign;
        denominator = 1000;
        reduce();
    }

    Fraction::Fraction(const Fraction &fraction)
    {
        numerator = fraction.numerator;
        denominator = fraction.denominator;
    }

    Fraction::~Fraction()
    {
        numerator = 0;
        denominator = 1;
    }

    Fraction &Fraction::operator=(const Fraction &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;    }

    Fraction::Fraction(Fraction &&other) noexcept
    {
        numerator = other.numerator;
        denominator = other.denominator;
        other.numerator = 0;
        other.denominator = 1;
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept
    {
        numerator = other.numerator;
        denominator = other.denominator;
        other.numerator = 0;
        other.denominator = 1;
        return *this;
    }

    int Fraction::getNumerator()
    {
        return numerator;
    }
    int Fraction::getDenominator()
    {
        return denominator;
    }

    Fraction Fraction::operator+(const Fraction &fractionRight) const
    {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        long long newNumerator = (long long)numerator * fractionRight.denominator + (long long)fractionRight.numerator * denominator;
        long long newDenominator = denominator * fractionRight.denominator;
        if (newNumerator > max_int || newNumerator < min_int || newDenominator > max_int || newDenominator < min_int)
        {
            throw std::overflow_error("Overflow error");
        }
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator-(const Fraction &fractionRight) const
    {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        long long newNumerator = (long long)numerator * fractionRight.denominator - (long long)fractionRight.numerator * denominator;
        long long newDenominator = denominator * fractionRight.denominator;
        if (newNumerator > max_int || newNumerator < min_int || newDenominator > max_int || newDenominator < min_int)
        {
            throw std::overflow_error("Overflow error");
        }
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator*(const Fraction &fractionRight) const
    {
        int newNumerator = numerator * fractionRight.numerator;
        int newDenominator = denominator * fractionRight.denominator;
          if (((numerator != 0) && (newNumerator / numerator != fractionRight.numerator)) ||
            ((denominator != 0) && (newDenominator / denominator != fractionRight.denominator)))
        {
            throw std::overflow_error("Overflow error");
        }
        
        
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator/(const Fraction &fractionRight) const
    {
        if (fractionRight.numerator == 0)
        {
            throw std::runtime_error("Cannot divide by zero");
        }
        int newNumerator = numerator * fractionRight.denominator;
        int newDenominator = denominator * fractionRight.numerator;
        if (((numerator != 0) && (newNumerator / numerator != fractionRight.denominator)) ||
            ((denominator != 0) && (newDenominator / denominator != fractionRight.numerator)))
        {
            throw std::overflow_error("Overflow error");
        }
        return Fraction(newNumerator, newDenominator);
    }
    Fraction Fraction::operator+=(const Fraction &fractionRight)
    {
        *this = *this + fractionRight;
        return *this;
    }
    Fraction Fraction::operator-=(const Fraction &fractionRight)
    {
        *this = *this - fractionRight;
        return *this;
    }
    Fraction Fraction::operator*=(const Fraction &fractionRight)
    {
        *this = *this * fractionRight;
        return *this;
    }
    Fraction Fraction::operator/=(const Fraction &fractionRight)
    {
        if (fractionRight.numerator == 0)
        {
            throw std::runtime_error("Cannot divide by zero");
        }
        *this = *this / fractionRight;
        return *this;
    }

    bool Fraction::operator==(const Fraction &fractionRight) const
    {
        float leftSide = (float)numerator / (float)denominator;
        float rightSide = (float)fractionRight.numerator / (float)fractionRight.denominator;
        Fraction left(leftSide);
        Fraction right(rightSide);
        return left.numerator == right.numerator && left.denominator == right.denominator;
    }
    bool Fraction::operator!=(const Fraction &fractionRight) const
    {
        return !(*this == fractionRight);
    }
    bool Fraction::operator<(const Fraction &fractionRight) const
    {
        float leftSide = (float)numerator / (float)denominator;
        float rightSide = (float)fractionRight.numerator / (float)fractionRight.denominator;
        Fraction left(leftSide);
        Fraction right(rightSide);
        return left.numerator * right.denominator < right.numerator * left.denominator;
    }
    bool Fraction::operator<=(const Fraction &fractionRight) const
    {
        return *this < fractionRight || *this == fractionRight;
    }
    bool Fraction::operator>(const Fraction &fractionRight) const
    {
        return !(*this <= fractionRight);
    }
    bool Fraction::operator>=(const Fraction &fractionRight) const
    {
        return !(*this < fractionRight);
    }

    bool operator==(const Fraction &fractionLeft, float floatNumberRight)
    {
        Fraction right(floatNumberRight);
        return fractionLeft == right;
    }
    bool operator!=(const Fraction &fractionLeft, float floatNumberRight)
    {
        return !(fractionLeft == floatNumberRight);
    }
    bool operator<(const Fraction &fractionLeft, float floatNumberRight)
    {
        Fraction right(floatNumberRight);
        return fractionLeft < right;
    }
    bool operator<=(const Fraction &fractionLeft, float floatNumberRight)
    {
        return fractionLeft < floatNumberRight || fractionLeft == floatNumberRight;
    }
    bool operator>(const Fraction &fractionLeft, float floatNumberRight)
    {
        return !(fractionLeft <= floatNumberRight);
    }
    bool operator>=(const Fraction &fractionLeft, float floatNumberRight)
    {
        return !(fractionLeft < floatNumberRight);
    }

    bool operator==(float floatNumberLeft, const Fraction &fractionRight)
    {
        Fraction left(floatNumberLeft);
        return left == fractionRight;
    }
    bool operator!=(float floatNumberLeft, const Fraction &fractionRight)
    {
        return !(floatNumberLeft == fractionRight);
    }
    bool operator<(float floatNumberLeft, const Fraction &fractionRight)
    {
        Fraction left(floatNumberLeft);
        return left < fractionRight;
    }
    bool operator<=(float floatNumberLeft, const Fraction &fractionRight)
    {
        return floatNumberLeft < fractionRight || floatNumberLeft == fractionRight;
    }
    bool operator>(float floatNumberLeft, const Fraction &fractionRight)
    {
        return !(floatNumberLeft <= fractionRight);
    }
    bool operator>=(float floatNumberLeft, const Fraction &fractionRight)
    {
        return !(floatNumberLeft < fractionRight);
    }

    Fraction operator+(float floatNumberLeft, const Fraction &rightSide)
    {
        Fraction left(floatNumberLeft);
        return left + rightSide;
    }
    Fraction operator-(float floatNumberLeft, const Fraction &rightSide)
    {
        Fraction left(floatNumberLeft);
        return left - rightSide;
    }
    Fraction operator*(float floatNumberLeft, const Fraction &rightSide)
    {
        Fraction left(floatNumberLeft);
        return left * rightSide;
    }
    Fraction operator/(float floatNumberLeft, const Fraction &rightSide)
    {
        if (rightSide.numerator == 0)
        {
            throw std::runtime_error("Cannot divide by zero");
        }

        Fraction left(floatNumberLeft);
        return left / rightSide;
    }

    std::ostream &operator<<(std::ostream &outputStream, const Fraction &fractionNumber)
    {
        outputStream << fractionNumber.numerator << "/" << fractionNumber.denominator;
        return outputStream;
    }

    std::istream &operator>>(std::istream &istream, Fraction &fractionNumber)
    {
        int new_numerator, new_denominator;

        if (istream >> new_numerator >> new_denominator)
        {
            if (new_denominator < 0)
            {
                new_numerator *= -1;
                new_denominator *= -1;
            }
            else if (new_denominator == 0)
            {
                throw std::runtime_error("zero denominator is not allowed");
            }
            if (new_numerator == 0)
            {
                new_denominator = 1;
            }
            fractionNumber.numerator = new_numerator;
            fractionNumber.denominator = new_denominator;
            fractionNumber.reduce();
            return istream;
        }
        else
        {
            throw std::runtime_error("invalid input");
        }
    }

    Fraction Fraction::operator+(float floatNumberRight) const
    {
        Fraction right(floatNumberRight);
        return *this + right;
    }
    Fraction Fraction::operator-(float floatNumberRight) const
    {
        Fraction right(floatNumberRight);
        return *this - right;
    }
    Fraction Fraction::operator*(float floatNumberRight) const
    {
        Fraction right(floatNumberRight);
        return *this * right;
    }
    Fraction Fraction::operator/(float floatNumberRight) const
    {
        if (floatNumberRight == 0)
        {
            throw std::runtime_error("Cannot divide by zero");
        }
        Fraction right(floatNumberRight);
        return *this / right;
    }

    Fraction Fraction::operator+=(float floatNumberRight)
    {
        *this = *this + floatNumberRight;
        return *this;
    }
    Fraction Fraction::operator-=(float floatNumberRight)
    {
        *this = *this - floatNumberRight;
        return *this;
    }
    Fraction Fraction::operator*=(float floatNumberRight)
    {
        *this = *this * floatNumberRight;
        return *this;
    }
    Fraction Fraction::operator/=(float floatNumberRight)
    {
        if (floatNumberRight == 0)
        {
            throw std::runtime_error("Cannot divide by zero");
        }
        *this = *this / floatNumberRight;
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        Fraction temp = *this;
        numerator += denominator;
        return temp;
    }
    Fraction &Fraction::operator--()
    {
        numerator -= denominator;
        return *this;
    }
    Fraction Fraction::operator--(int)
    {
        Fraction temp = *this;
        numerator -= denominator;
        return temp;
    }

    Fraction &Fraction::operator++()
    {
        numerator += denominator;
        return *this;
    }
}
