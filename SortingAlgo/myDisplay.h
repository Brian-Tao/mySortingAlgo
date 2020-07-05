#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

inline void display(const std::vector<int>& v) {
	for (auto val : v)
		std::cout << std::setw(4) << val;
	std::cout << std::endl;
}

inline void display(const std::vector<std::vector<int>>& v) {
	for (auto vec : v)
		display(vec);
}

inline void display(const std::vector<std::string>& v) {
	for (auto val : v)
		std::cout << std::setw(6) << val;
	std::cout << std::endl;
}

