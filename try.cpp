#include <iostream>

int main()
{

int index;

int value_of_base_x_cordinates[50] = {-25,-24,-23,-22,-21,-20,-19,-18,-17,-16
,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

for(int i = 0; i < 50; i++){
    if(value_of_base_x_cordinates[i] == 0){
        index = i;
    }
}

std::string linefrom_minusone_to_minustwentyfive[51] = {"·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·"
,"·","·","·","·","+","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·","·"};

std::cout<<linefrom_minusone_to_minustwentyfive[index+1];

}


