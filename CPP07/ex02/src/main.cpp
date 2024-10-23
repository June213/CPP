/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:33:17 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/23 10:28:23 by jsalaber         ###   ########.fr       */
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
	std::cout << std::endl;

	std::cout << "=== Asignación ===" << std::endl;
    Array<int> arr3 = arr2;
    std::cout << "Tamaño de arr3 (copia): " << arr3.size() << std::endl;
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
