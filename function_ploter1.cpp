 
#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <map>
#include <vector>
 
std::vector<std::vector<std::string>> matrix;
 
std::vector<std::string> from_1_to_25{" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "
," "," "," "," ","+"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "};
 
std::vector<std::string> x_axis{"+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+"
,"+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+"};
 
std::vector<std::string> from_minus1_to_minus25{" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "
," "," "," "," ","+"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "};
 
 
std::map<int ,int> values;
 
std::vector<std::vector<std::string>>::iterator row_vector_ptr;
std::vector<std::string>::iterator col_vector_ptr;
 
 
 
 
void fill_base_map_values(){
   for(int i = -25; i < 26; i++){
       values.insert({i,i});
   }
}
 
void log_print_map(){
   for(auto& i : values){
       std::cout<< i.first << " "<< i.second<<std::endl;
   }
}
 
void fill_base_matrix(){
 
   for(int i = 0; i < 25; i++){
       matrix.push_back(from_1_to_25);
   }
   matrix.push_back(x_axis);
 
   for(int i = 0; i<25; i++){
       matrix.push_back(from_minus1_to_minus25);
   }
}
 
void input(){
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
           for(auto& c: values){
               c.second = c.second + modification_number_int;
           }
       }
   
       else if(input == "2"){
           std::cout<< "how much do you want to substract?"<<std::endl;
           std::cin>> modification_number_string;
           int modification_number_int = stoi(modification_number_string);
           for(auto &c : values){
               c.second = c.second - modification_number_int;
           }
       }
       else if(input == "3"){
          std::cout<< "how much do you want to multiply?"<<std::endl;
          std::cin>> modification_number_string;
          int modification_number_int = stoi(modification_number_string);
          for(auto &c : values){
               c.second = c.second * modification_number_int;
           }
 
       }
       else if(input == "4"){
           std::cout<< "how much do you want to divide with?"<<std::endl;
           std::cin>> modification_number_string;
           int modification_number_int = stoi(modification_number_string);
           for(auto &c : values){
               c.second = c.second / modification_number_int;
           }
          
       }
   }
}
 
 
void print_matrix(){
   for(int i = 0; i < matrix.size(); i++){
       for(int j= 0; j<matrix[i].size(); j++){
           std::cout<< matrix[i][j]<<" ";
       }
       std::cout<<std::endl;
   }
}
 
void checkfor_over_or_uner_values(){
   for(auto&c : values){
       if(c.second > 25 || c.second < -25){
           c.second = 100;
       }
   }
}
 
//void check_for_duplicates(){
 
//}
 
void log_print_matrix(){
   matrix[25 - 3][25 - 2] = "#";
}
 
void change_matrix(){
  
   for(auto & c: values){
       if(c.second < 100){
           if(c.first == 0 && c.second > 0){
               matrix[25-c.second][25] = "#";
           }
           else if(c.first == 0 && c.second == 0){
               matrix[25][25] = "#";
           }
           else if(c.first == 0 && c.second < 0){
               matrix[25 - c.second][25] = "#";
           }
           else if( c.first < 0 && c.second > 0){
               matrix[25 - c.second][25 + c.first] = "#";
           }
           else if(c.first < 0 && c.second < 0){
               matrix[25 - c.second][25 + c.first] = "#";
           }
           else if(c.first > 0 && c.second > 0){
               matrix[25 - c.second][25 + c.first] = "#";
           }
           else if(c.first > 0 && c.second < 0){
               matrix[25 - c.second][25 + c.first] = "#";
           }
           else if(c.first < 0 && c.second == 0){
               matrix[25][25 + c.first] = "#";
           }
           else if(c.first > 0 && c.second == 0){
               matrix[25][25 + c.first] = "#";
           }
       }
   }
 
 
 
 
 
 
   //ha x nulla es ertek pozitiv  [25-c.second][c.first --> 25 lesz mert az a 0]
   //ha x nulla es erteke nulla [25][25]
   // ha x nulla es erteke negativ [25 + c.secon][25]
 
   // ha x negatic es erteke pozitiv [25 - c.second][25 - c.first]
   // ha x negativ es erteke negativ [25 + c.second][25 - c.first]
   // ha x negativ es erteke nulla [25][25-c.first]
 
   //ha x pozitiv es erteke pozitiv [25-c.second][25 + c.first]
   //ha x pozitiv es erteke negativ [25 + c.second][25 + c.first]
   //ha x pozitiv es erteke nulla [25][25 + c.first]
 
}
 
 
int main()
{  
   fill_base_map_values();
 //  log_print_map();
   fill_base_matrix();
   input();
   checkfor_over_or_uner_values();
   //change_matrix();
   change_matrix();
   print_matrix();
  
   //for(row_vector_ptr = matrix.begin(); row_vector_ptr != matrix.end(); row_vector_ptr++){
     //  for(col_vector_ptr = row_vector_ptr->begin(); col_vector_ptr != row_vector_ptr->end(); col_vector_ptr++){
       //    std::cout<< *(row_vector_ptr  + 1);
      // }
  // }
 
}
 
 
 

 
