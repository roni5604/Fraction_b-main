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
        /// @brief
        /// Default constructor for Fraction class default values are 0/1
        Fraction();

        /// @brief
        /// Constructor for Fraction class
        /// @param numeratorVal
        /// @param denominatorVal default value is 1 if not given if given 0 throws exception
        Fraction(int numeratorVal, int denominatorVal = 1);

        /// @brief constructor for Fraction class from float number
        /// @param floatNumber float number to convert to fraction until 3 digits after the point
        Fraction(float floatNumber);

        /// @brief constructor for Fraction class from double number
        /// @param doubleNumber  double number to convert to fraction until 3 digits after the point
        Fraction(double doubleNumber);

        /// @brief  copy constructor for Fraction class
        /// @param fraction Fraction object to copy
        Fraction(const Fraction &fraction);

        /// @brief destructor for Fraction class
        ~Fraction();

        /// @brief assignment operator for Fraction class
        /// @param fraction  Fraction object to copy
        /// @return Fraction& the copied Fraction object
        Fraction &operator=(const Fraction &fraction);

        /// @brief move constructor for Fraction class
        /// @param fraction Fraction object to move for the new Fraction object
        Fraction(Fraction &&fraction) noexcept;

        /// @brief move assignment operator for Fraction class
        /// @param fraction Fraction object to move for the new Fraction object
        /// @return Fraction& the moved Fraction object
        Fraction &operator=(Fraction &&fraction) noexcept;

        /// @brief  convert Fraction to ostream object that can be printed
        /// @param outputStream  ostream object to print the Fraction object
        /// @param fractionNumber  Fraction object
        /// @return  ostream& the ostream object that can be printed
        friend std::ostream &operator<<(std::ostream &outputStream, const Fraction &fractionNumber);

        /// @brief convert istream object to Fraction object
        /// @param istream  istream object
        /// @param fractionNumber Fraction object that will be changed
        /// @return  istream& the istream object that can be converted to Fraction object
        friend std::istream &operator>>(std::istream &istream, Fraction &fractionNumber);

        /// @brief prefix increment operator for Fraction class
        /// @return Fraction object before increment
        Fraction operator++(int);

        /// @brief prefix decrement operator for Fraction class
        /// @return Fraction& reference to the Fraction object before decrement
        Fraction &operator--();

        /// @brief postfix decrement operator for Fraction class
        /// @return Fraction object before decrement
        Fraction operator--(int);

        /// @brief postfix increment operator for Fraction class
        /// @return Fraction& reference to the Fraction object before increment
        Fraction &operator++();

        /// @brief add Fraction object to the current Fraction object
        /// @param fractionRight Fraction object to add
        /// @return the result of the addition
        Fraction operator+(const Fraction &fractionRight) const;

        /// @brief subtract Fraction object from the current Fraction object
        /// @param fractionRight Fraction object to subtract
        /// @return the result of the subtraction
        Fraction operator-(const Fraction &fractionRight) const;

        /// @brief multiply Fraction object with the current Fraction object
        /// @param fractionRight Fraction object to multiply
        /// @return the result of the multiplication
        Fraction operator*(const Fraction &fractionRight) const;

        /// @brief divide Fraction object from the current Fraction object
        /// @param fractionRight Fraction object to divide if the Fraction object is 0 throws exception
        /// @return the result of the division
        Fraction operator/(const Fraction &fractionRight) const;

        /// @brief add Fraction object to the current Fraction object
        /// @param fractionRight Fraction object to add
        /// @return the result of the addition
        Fraction operator+=(const Fraction &fractionRight);

        /// @brief subtract the current Fraction object from Fraction object
        /// @param fractionRight Fraction object to subtract
        /// @return the result of the subtraction
        Fraction operator-=(const Fraction &fractionRight);

        /// @brief multiply Fraction object with the current Fraction object
        /// @param fractionRight Fraction object to multiply
        /// @return the result of the multiplication
        Fraction operator*=(const Fraction &fractionRight);

        /// @brief divide the current Fraction object from Fraction object
        /// @param fractionRight Fraction object to divide if the Fraction object is 0 throws exception
        /// @return the result of the division
        Fraction operator/=(const Fraction &fractionRight);

        /// @brief check if the current Fraction object is equal to the Fraction object
        /// @return true if the Fraction objects are equal else false
        bool operator==(const Fraction &fractionRight) const;

        /// @brief check if the current Fraction object is not equal to the Fraction object
        /// @return  true if the Fraction objects are not equal else false
        bool operator!=(const Fraction &fractionRight) const;

        /// @brief check if the current Fraction object is less than the Fraction object
        /// @return true if the current Fraction object is less than the Fraction object else false
        bool operator<(const Fraction &fractionRight) const;

        /// @brief check if the current Fraction object is less than or equal to the Fraction object
        /// @return true if the current Fraction object is less than or equal to the Fraction object else false
        bool operator<=(const Fraction &fractionRight) const;

        /// @brief check if the current Fraction object is greater than the Fraction object
        /// @return true if the current Fraction object is greater than the Fraction object else false
        bool operator>(const Fraction &fractionRight) const;

        /// @brief check if the current Fraction object is greater than or equal to the Fraction object
        /// @return true if the current Fraction object is greater than or equal to the Fraction object else false
        bool operator>=(const Fraction &fractionRight) const;

        /// @brief check if the current Fraction object is equal to the float number
        /// @return true if the current Fraction object is equal to the float number else false
        friend bool operator==(const Fraction &fractionLeft, float floatNumberRight);

        /// @brief check if the current Fraction object is not equal to the float number
        /// @return true if the current Fraction object is not equal to the float number else false
        friend bool operator!=(const Fraction &fractionLeft, float floatNumberRight);

        /// @brief check if the current Fraction object is less than the float number
        /// @return true if the current Fraction object is less than the float number else false
        friend bool operator<(const Fraction &fractionLeft, float floatNumberRight);

        /// @brief check if the current Fraction object is less than or equal to the float number
        /// @return true if the current Fraction object is less than or equal to the float number else false
        friend bool operator<=(const Fraction &fractionLeft, float floatNumberRight);

        /// @brief check if the current Fraction object is greater than the float number
        /// @return true if the current Fraction object is greater than the float number else false
        friend bool operator>(const Fraction &fractionLeft, float floatNumberRight);

        /// @brief check if the current Fraction object is greater than or equal to the float number
        /// @return true if the current Fraction object is greater than or equal to the float number else false
        friend bool operator>=(const Fraction &fractionLeft, float floatNumberRight);

        /// @brief check if the float number is equal to the current Fraction object
        /// @return true if the float number is equal to the current Fraction object else false
        friend bool operator==(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief check if the float number is not equal to the current Fraction object
        /// @return true if the float number is not equal to the current Fraction object else false
        friend bool operator!=(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief check if the float number is less than the current Fraction object
        /// @return true if the float number is less than the current Fraction object else false
        friend bool operator<(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief check if the float number is less than or equal to the current Fraction object
        /// @return true if the float number is less than or equal to the current Fraction object else false
        friend bool operator<=(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief check if the float number is greater than the current Fraction object
        /// @return true if the float number is greater than the current Fraction object else false
        friend bool operator>(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief check if the float number is greater than or equal to the current Fraction object
        /// @return true if the float number is greater than or equal to the current Fraction object else false
        friend bool operator>=(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief add float number to the current Fraction object
        /// @return the result of the addition 
        friend Fraction operator+(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief subtract float number from the current Fraction object
        /// @return the result of the subtraction
        friend Fraction operator-(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief multiply float number with the current Fraction object
        /// @return the result of the multiplication
        friend Fraction operator*(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief divide float number from the current Fraction object
        /// @return the result of the division throws exception if the Fraction object is 0
        friend Fraction operator/(float floatNumberLeft, const Fraction &fractionRight);

        /// @brief add float number to the current Fraction object
        /// @return the result of the addition
        Fraction operator+(float floatNumberRight) const;

        /// @brief subtract float number from the current Fraction object
        /// @return the result of the subtraction
        Fraction operator-(float floatNumberRight) const;

        /// @brief multiply float number with the current Fraction object
        /// @return the result of the multiplication
        Fraction operator*(float floatNumberRight) const;

        /// @brief divide float number from the current Fraction object
        /// @return the result of the division throws exception if the Fraction object is 0
        Fraction operator/(float floatNumberRight) const;

        /// @brief add float number to the current Fraction object
        /// @return the result of the addition
        Fraction operator+=(float floatNumberRight);

        /// @brief subtract float number from the current Fraction object
        /// @return the result of the subtraction
        Fraction operator-=(float floatNumberRight);

        /// @brief multiply float number with the current Fraction object
        /// @return the result of the multiplication
        Fraction operator*=(float floatNumberRight);

        /// @brief divide the current Fraction object from float number
        /// @return the result of the division throws exception if the float number is 0
        Fraction operator/=(float floatNumberRight);


        /// @brief gives the numerator of the Fraction object
        /// @return int the numerator of the Fraction object
        int getNumerator();

        /// @brief gives the denominator of the Fraction object
        /// @return int the denominator of the Fraction object
        int getDenominator();
    };

}