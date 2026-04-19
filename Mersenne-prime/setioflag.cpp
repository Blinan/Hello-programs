#include <iomanip>
#include <iostream>
#include <numbers>
 
int main()
{
    const double PI = std::numbers::pi;
    const int WIDTH = 15;
 
    std::cout.setf(std::ios::left); // equivalent: cout << right;
    std::cout << std::setw(WIDTH / 2) << "radius"
              << std::setw(WIDTH) << "circumference" << '\n';
 
    std::cout.setf(std::ios::fixed); // equivalent: cout << fixed;
    for (double radius = 1; radius <= 6; radius += 0.5)
        std::cout << std::setprecision(1) << std::setw(WIDTH / 2)
                  << radius
                  << std::setprecision(2) << std::setw(WIDTH)
                  << (2 * PI * radius) << '\n';
}