#include <iostream>
#include "Time.h"

void main() {
	while (true) {
		Time t1, t2;

		std::cout << "Enter timer 1: ";
		std::cin >> t1;
		std::cout << "Timer 1: " << t1 << std::endl;

		std::cout << "Enter timer 2: ";
		std::cin >> t2;
		std::cout << "Timer 2: " << t2 << std::endl;
		std::cout << std::endl;

		t1.getTimesSum(t2);
		t1.formatTimesSum();
		std::cout << "Timers' summary value: ";
		t1.printTime();

		t1.getTimesDifference(t2);
		t1.formatTimesDifference(t2);
		std::cout << "Timers' difference value: ";
		t1.printTime();
	}
}