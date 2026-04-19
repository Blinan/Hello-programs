#include <iostream>
#include <random>

int main()
{
    std::random_device r;
    std::cout << "now output random_device:" <<std::endl;
    
    for(int i = 5; i > 0; --i)
    std::cout << r() << std::endl;

    std::cout << "now output default_random_engine:" <<std::endl;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> uni_dis(-10, 10);
    for(int i = 50; i > 0; --i)
        {
            std::cout << e() << std::endl;
            std::cout <<"uni_dis =   "<< uni_dis(e) <<std::endl ;
        }
    return 0;
}