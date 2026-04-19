#include <iostream>
#include <fstream>
#include <string>


int main()
{
    
    std::ifstream input("content");
    std::ofstream output("output"); 
    char c[500];
    std::string str;
    for(int i = 1; getline(input, str); ++i)
    if(i % 3 == 2)
    output << str << std::endl;
    else continue;
    std::cout << str << std::endl;
    input.close();
    output.close();
    return 0;
}
