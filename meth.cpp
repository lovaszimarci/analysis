#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>

int value_of_base_x_cordinates[50] = {-25,-24,-23,-22,-21,-20,-19,-18,-17,-16
,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
 
// strings start from 1 int start from 0 --> for loop different startin number
//the upper part of the grap (positive values)
std::string linefrom_one_to_twentyfive_mod[51] = {":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":"
,":",":",":",":","+",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":"};

std::string linefrom_one_to_twentyfive_og[51] = {":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":"
,":",":",":",":","+",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":"};
 
//the lower part of the graph  (negative values)
std::string linefrom_minusone_to_minustwentyfive[51] = {":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":"
,":",":",":",":","+",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":",":"};
 
//the midle line --> x axis (zero values)
std::string x_axis[51] = {"+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+"
,"+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+"};
 
std::map<int, int> cordinates;
 
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
          for(auto &cordinate : cordinates){
               cordinate.second = cordinate.second + modification_number_int;
            }
        for(auto&c:cordinates){
                std::cout<<c.first<<" "<<c.second<<std::endl;
            } 
            // itt helyesek
       }
     
       else if(input == "2"){
          std::cout<< "how much do you want to substract?"<<std::endl;
          std::cin>> modification_number_string;
          int modification_number_int = stoi(modification_number_string);
          for(auto &cordinate : cordinates){
            cordinate.second = cordinate.second - modification_number_int;
          }
      }
 
      else if(input == "3"){
           std::cout<< "how much do you want to multiply?"<<std::endl;
           std::cin>> modification_number_string;
           int modification_number_int = stoi(modification_number_string);
           for(auto &cordinate : cordinates){
            cordinate.second = cordinate.second * modification_number_int;
            }
            for(auto&c:cordinates){
                    std::cout<<c.first<<" "<<c.second<<std::endl;
                }

      }
 
      else if(input == "4"){
       std::cout<< "how much do you want to divide with?"<<std::endl;
          std::cin>> modification_number_string;
          int modification_number_int = stoi(modification_number_string);
          for(auto &cordinate : cordinates){
            cordinate.second = cordinate.second / modification_number_int;
          }
      }
  }
    
}
//for log
void print()
{
   for(auto &c : cordinates){
       std::cout<< c.first << " "<< c.second<<std::endl;
   }
}
 
void set_map_base_values()
{
   for(int i = -25; i < 26; i++){
       cordinates.insert({i,i});
   }
 
}

int xindex_to_changeto_hastag;

void plotting()
{
    for(int i = 25; i > 0; i--){
        for(auto &cordinate : cordinates){
            if(cordinate.second == i){
                for(int j = 0; j < 50; j++){
                    if(value_of_base_x_cordinates[j] == cordinate.first){
                        xindex_to_changeto_hastag = j + 1;
                        linefrom_one_to_twentyfive_mod[xindex_to_changeto_hastag] = "#";
                        for(auto &c: linefrom_one_to_twentyfive_mod){
                            std::cout<<c<<"  ";
                        }
                        std::cout<<std::endl;
                        linefrom_one_to_twentyfive_mod[xindex_to_changeto_hastag] = linefrom_one_to_twentyfive_og[xindex_to_changeto_hastag];
                        
                    }
                    
                }
                

            }

            else if(cordinate.second <= 25 && cordinate.second != i){
                for(auto &c: linefrom_one_to_twentyfive_mod){
                    std::cout<<c<<"  ";
                }
                std::cout<<std::endl;
                
            }
            
            
        } 
          
        
    }
    for(auto&c:cordinates){
            std::cout<<c.first<<" "<<c.second<<std::endl;
        } 

    

}
 
int main()
{
 
   set_map_base_values();
   modification();
   plotting();

 
 
 
   // plot of the graph
  
}
//std vector cant append array at runtime
 
 
