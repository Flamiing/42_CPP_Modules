/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:00:07 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/21 17:28:12 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{

}

Fixed::Fixed(const int value) : _value(value << 8)
{

}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << this->_fractBits)))
{

}

Fixed::Fixed(const Fixed& other)
{
	_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed	result;
	result._value = _value + other.getRawBits();
	return result;
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed	result;
	result._value = _value - other.getRawBits();
	return result;
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed	result;
	result._value = _value * other.getRawBits() >> Fixed::_fractBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed	result;
	result._value = _value * (1 << Fixed::_fractBits) / other.getRawBits();
	return result;
}

Fixed& Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed& Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value--;
	return temp;
}

bool Fixed::operator>(const Fixed &other)
{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other)
{
	return (_value < other._value);
}

bool Fixed::operator>=(const Fixed &other)
{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other)
{
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed &other)
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other)
{
	return (_value != other._value);
}

Fixed::~Fixed(void)
{

}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_fractBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_fractBits);
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}