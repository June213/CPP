/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: june <june@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:07:34 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/03 12:50:27 by june             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixedPointValue;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		bool operator>(const Fixed &src) const;
		bool operator<(const Fixed &src) const;
		bool operator>=(const Fixed &src) const;
		bool operator<=(const Fixed &src) const;
		bool operator==(const Fixed &src) const;
		bool operator!=(const Fixed &src) const;
		
		Fixed operator+(const Fixed &src) const;
		Fixed operator-(const Fixed &src) const;
		Fixed operator*(const Fixed &src) const;
		Fixed operator/(const Fixed &src) const;
		
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		
		int getRawBits(void)const;
		void setRawBits(int const raw);
		int toInt(void)const;
		float toFloat(void)const;
		
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};
	std::ostream& operator<<(std::ostream &out, const Fixed &value);

#endif