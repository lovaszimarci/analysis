#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>
 
int value_of_base_x_cordinates[51] = {-25,-24,-23,-22,-21,-20,-19,-18,-17,-16
,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
 
void modification()
{
   std::string input;
   std::string modification_number_string;
  
 
   while (input != "q"){
 
       std::cout<< "Chose an action(enter it's number) or press q to exit"<< std::endl;
       std::cout<<"1 = addition"<<std::endl;
       std::cout<<"2 = substraction"<<std::endl;
       std::cout<<"3 = multiplication"<<std::endl;
       std::cout<<"4 = divison"<<std::endl;
       std::cout<<"5 = root"<<std::endl;
       std::cout<<"6 = exponentiation"<<std::endl;
       std::cin>> input;
 
       if(input == "1"){
           std::cout<< "how much do you want to add?"<<std::endl;
           std::cin>> modification_number_string;
           int modification_number_int = stoi(modification_number_string);
           for(auto& i : value_of_base_x_cordinates){
               i = i + modification_number_int;
              
           }
       }
  
       else if(input == "2"){
           std::cout<< "how much do you want to substract?"<<std::endl;
           std::cin>> modification_number_string;
           int modification_number_int = stoi(modification_number_string);
           for(auto& i : value_of_base_x_cordinates){
               i = i - modification_number_int;
           }
       }
 
 
      
   }
 
}
 
 
int main()
{
   std::map<int, int> kordinatak;
   modification();
   for(auto & i : value_of_base_x_cordinates){
       std::cout<< i << " ";
   }
}
 
 
 
 
 
//std vector cant append array at runtime
 
 
