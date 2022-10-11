#include <iostream>
#include <iomanip>


int main()
{
    char hihi[10] = {'x','x','x','x','x','x','x','x','x','x',};

    for(int rows = 0; rows <10; rows++)
    {
        for(auto& c : hihi){
            std::cout<<c << ' ';
        }

        std::cout<< std::endl;
    }
}

