// HelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

int main()
{
	std::cout << "Hello world! Now enter a number: ";
	int number;
	std::cin >> number;


	std::cout << "\n\nHere are all of the powers 1 to 12 on " << number << ": \n";
	for (int i = 1; i <= 12; i++) {
		std::cout << i << ": " << pow(number, i) << "\n";
	}
}

