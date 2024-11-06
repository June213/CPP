/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:33:17 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/06 10:13:49 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

int main()
{
    std::cout << "=== Constructor por defecto ===" << std::endl;
    Array<int> arr1;
    std::cout << "Tamaño del array arr1: " << arr1.size() << std::endl;
	std::cout << std::endl;
	
	std::cout << "=== Constructor con tamaño ===" << std::endl;
    Array<int> arr2(5);
    std::cout << "Tamaño de arr2: " << arr2.size() << std::endl;
    for (int i = 0; i < 5; i++) {
        arr2[i] = i * 10;
    }
    for (int i = 0; i < 5; i++) {
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }
	std::cout << std::endl;

	std::cout << "\n=== Constructor de copia ===" << std::endl;
    Array<int> arr4(arr2);
    std::cout << "Tamaño del array arr4: " << arr4.size() << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "arr4[" << i << "] = " << arr4[i] << std::endl;
	}
	arr4[3] = 100;
	std::cout << "Después de modificar arr4[3]: " << arr4[3] << std::endl;
	std::cout << "arr2[3] (copia) = " << arr2[3] << std::endl;
	std::cout << std::endl;

	std::cout << "=== Asignación ===" << std::endl;
    Array<int> arr3 = arr2;
    std::cout << "Tamaño de arr3 (copia): " << arr3.size() << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;
	}
    arr2[0] = 100;
    std::cout << "Después de modificar arr2[0]: " << std::endl;
    std::cout << "arr2[0] = " << arr2[0] << std::endl;
    std::cout << "arr3[0] (copia) = " << arr3[0] << std::endl;
	std::cout << std::endl;

	std::cout << "=== Fuera de rango ===" << std::endl;
    try {
        std::cout << arr2[10] << std::endl; 
    } catch (const std::exception &e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }
	std::cout << std::endl;

    return 0;
}


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);

// 		tmp[0] = 1234;
// 		if (numbers[0] == tmp[0])
// 		{
// 			std::cerr << "didn't save the value!!" << std::endl;
// 			return 1;
// 		}
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
// 	std::cout << "Independent copy test: OK" << std::endl;
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
// 	std::cout << "Exception handling test: OK" << std::endl;

// 	if (numbers.size() != MAX_VAL) {
//         std::cerr << "size() test failed: the size is incorrect!" << std::endl;
//         return 1;
//     }
//     std::cout << "Size test: OK" << std::endl;

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
