#include <iostream>
#include <random>
#include <unistd.h>

int main() {
    // 使用随机设备创建一个随机种子
    std::random_device rd;
    
    // 使用随机种子初始化 Mersenne Twister 随机数生成器
    std::mt19937 generator(rd());

    // 生成一个随机数
    while(1){
    std::cout << "Random number: " << generator() << std::endl;
    //usleep(1000*1000*0.5);
    }
            // 使用随机设备创建一个随机种子
            std::random_device seed;
            // '创建'并'使用随机种子初始化 Mersenne Twister '随机数生成器
            std::mt19937 generator(seed()); 
            std::uniform_int_distribution<int> dist(-128, 0); 
            static int temp = 0;
            temp = dist(generator); 
    return 0;
}

            