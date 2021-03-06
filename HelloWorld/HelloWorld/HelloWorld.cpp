// HelloWorld.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <conio.h>
#include <cmath>
#include <random> //std::random_device and uniform_int_distribution I believe
#include <map>
#include <string>
#include <chrono> //"Clock" to measure runtime

using namespace std::chrono;

bool daleKillsMatsurf(std::string);
bool daleTakesADaleOnPoorLarry(std::string);

int main()
{
	std::cout << "Hello world! Now enter a number: ";
	int	number;
	std::cin >>	number;


	std::cout << "\n\nHere are all of the powers 1 to 12 on " << number << ": \n";
	for (int i = 1; i <= 12; i++) {
		std::cout << i << ": " << pow(number, i) << "\n";
	}

	//Begin measuring the runtime to see how long the generator takes. Probably not very.
	auto start = steady_clock::now();

	std::random_device rd;
	std::map<int, int> hist;
	std::uniform_int_distribution<int> dist(0, 9);
	for (int n = 0; n < 20000; ++n) {
		++hist[dist(rd)]; // note: demo only: the performance of many 
						  // implementations of random_device degrades sharply
						  // once the entropy pool is exhausted. For practical use
						  // random_device is generally only used to seed 
						  // a PRNG such as mt19937
	}
	for (auto p : hist) {
		std::cout << p.first << " : " << (std::string(p.second / 100, '*')) << '\n';
	}

	//Gets the time after generating the uniformly distributed integers and calculates the runtime
	//			Casts the duration to microseconds, then takes in the current time - the start variable
	auto end = std::chrono::duration_cast<microseconds>(std::chrono::steady_clock::now() - start);

	//Averages about 52000 microseconds on my machine, or 0.053 (2 sig figs) seconds approximately
	std::cout << "Time: " << end.count() << " microseconds.\n";

	std::cout << "Test print\n";

	short larry = 0;//larry is a 0
	long shit = larry;//larry is shit

	std::string matsurf = (daleKillsMatsurf("yes")) ? "Matsurf dies" : "fuck you";

	std::cout << matsurf << "\n";

	_getch(); //From conio.h

	return 0;

}

bool daleKillsMatsurf(std::string c) {
	return !daleTakesADaleOnPoorLarry(c);
}

bool daleTakesADaleOnPoorLarry(std::string ) {
	return true;
}
