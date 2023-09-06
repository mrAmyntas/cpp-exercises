#include <iostream>

int main()
{
std::cout << "Welcome to this stupid calculator\n";

float liter{};

std::cout << "Enter liter: ";
std::cin >> liter;

std::cout << "Result: " << liter << " liter = " << liter * 1000 << " milliliter.\n";

}
