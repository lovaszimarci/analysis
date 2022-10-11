#include <iostream>
#include <string>
#include <map>




int main()
{

    std::map<int, int> kordinatak;

    kordinatak.insert({1,2});

    for(auto& i : kordinatak){

        
        std::cout<< i.first;
        std::cout<< i.second;
        
    }
}




