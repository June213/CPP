/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: june <june@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:07:34 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/03 11:47:30 by june             ###   ########.fr       */
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
		Fixed &operator=(const Fixed &src);
		~Fixed();
		int getRawBits(void)const;
		void setRawBits(int const raw);
		int toInt(void)const;
		float toFloat(void)const;	
};
	std::ostream& operator<<(std::ostream &out, const Fixed &value);

#endif