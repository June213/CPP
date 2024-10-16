/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:48:35 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/16 11:54:07 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void test1()
{
    std::cout << "test1\n";
    std::string s1 = "a"; std::string s2 = "55"; std::string s3 = "9.9f"; std::string s4 = "97.1f";
	std::cout << "s1: " << s1 << "\n";
    ScalarConverter::convert(s1);
    std::cout << "\n";
	std::cout << "s2: " << s2 << "\n";
    ScalarConverter::convert(s2);
    std::cout << "\n";
	std::cout << "s3: " << s3 << "\n";
    ScalarConverter::convert(s3);
    std::cout << "\n";
	std::cout << "s4: " << s4 << "\n";
    ScalarConverter::convert(s4);
    std::cout << "\n\n\n";
}

void test2()
{
    std::cout << "test2\n";
    std::string s1 = "300"; std::string s2 = "2147483648.0"; std::string s3 = "3402823466385288598117041834845169254424.0"; std::string s4 = "1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231644448738177180919299881250404026184124858361.0";
	std::cout << "s1: " << s1 << "\n";
    ScalarConverter::convert(s1);
    std::cout << "\n";
	std::cout << "s2: " << s2 << "\n";
    ScalarConverter::convert(s2);
    std::cout << "\n";
	std::cout << "s3: " << s3 << "\n";
    ScalarConverter::convert(s3);
    std::cout << "\n";
	std::cout << "s4: " << s4 << "\n";
    ScalarConverter::convert(s4);
    std::cout << "\n\n\n";
}

void test3()
{
    std::cout << "test3\n";
    std::string s1 = "inf"; std::string s2 = "-inf"; std::string s3 = "nan"; std::string s4 = "-nan";
	std::cout << "s1: " << s1 << "\n";
    ScalarConverter::convert(s1);
    std::cout << "\n";
	std::cout << "s2: " << s2 << "\n";
    ScalarConverter::convert(s2);
    std::cout << "\n";
	std::cout << "s3: " << s3 << "\n";
    ScalarConverter::convert(s3);
    std::cout << "\n";
	std::cout << "s4: " << s4 << "\n";
    ScalarConverter::convert(s4);
    std::cout << "\n\n\n";
}

void test4()
{
    std::cout << "test4\n";
    std::string s1 = "inff"; std::string s2 = "-inff"; std::string s3 = "nanf"; std::string s4 = "-nanf";
	std::cout << "s1: " << s1 << "\n";
    ScalarConverter::convert(s1);
    std::cout << "\n";
	std::cout << "s2: " << s2 << "\n";
    ScalarConverter::convert(s2);
    std::cout << "\n";
	std::cout << "s3: " << s3 << "\n";
    ScalarConverter::convert(s3);
    std::cout << "\n";
	std::cout << "s4: " << s4 << "\n";
    ScalarConverter::convert(s4);
    std::cout << "\n";
}

int main()
{
    test1();
    test2();
    test3();
    test4();
}

