#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <algorithm>
 
 
std::string input = "2/(x+16)*2";
 
int number_of_intIndex;
int int_number = 0;
std::string str_number = "";
int index_position = -1;
int index_position_before = -1;
 
std::string before_x;
 
std::string::iterator str_it;
char base_numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
 
 
bool isEelement(char character){
   char target = character;
 
   for(auto& c : base_numbers){
       if(c == target){
           std::cout<<"valid";
           return true;
          
       }
   }
   std::cout<<"false";
   return false;
}
 
   void reverseStr(std::string& str)
   {
       int n = str.length();
       for (int i = 0; i < n / 2; i++)
           std::swap(str[i], str[n - i - 1]);
   }
 
 
   // az x elotti stringeket kulon kell valasztani es kielemezni oket
   // ha megtalalja az aritmetikai operatorokat akkor ay elotte levoket kell megnezni hogy mennyi
   // ugyan az mukodiesi elv csak annyi hogy le kell csekkolni hogy nem iterator.end() e az indexelt string mert akkor
   // segmentation fault lesz
 
 
   // meg kell adni a findnak egy starting pointot --> mindig hozzaadni amikor megnezi a karaktereket
 
 
void functionStringParser(std::string inputString){
 
 
   //select the items from the string before the x symbol
   for(str_it = inputString.begin(); str_it != inputString.end(); str_it++){
       if(*str_it != 'x'){
           before_x +=  *str_it;
       }
       if(*str_it == 'x'){
           break;
       }
   }
 
   std::string::size_type i = inputString.find(before_x);
 
   if(i != std::string::npos){
       inputString.erase(i , before_x.length());
   }
   // true caption --> how to become a programer and get hired and i got hired
 
 
   std::cout<< before_x<< " ";
   std::cout<< inputString;
 
   for(str_it = inputString.begin(); str_it != inputString.end(); str_it++){
       std::cout<< "begin " <<*str_it << " ";
       index_position += 1;
       if( *str_it == '+'){
           number_of_intIndex = 1;
           while(isEelement(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number +=(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]);
               number_of_intIndex++;
               std::cout<<str_number;
           }
           std::cout<< " string number" << str_number;
           if(str_number != ""){
               int_number = int_number + std::stoi(str_number);
               std::cout<<"int number "<<int_number;
           }
           else{
               std::cout<<"hhhhh";
           }
          
           str_number = "";
           number_of_intIndex = 0;
       }
       else if( *str_it == '-'){
           number_of_intIndex = 1;
           while(isEelement(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number = str_number + inputString[inputString.find(*str_it) + number_of_intIndex];
               number_of_intIndex++;
           }
           if(str_number != ""){
               int_number = int_number - std::stoi(str_number);
           }
           else{
               std::cout<<"hhhhh";
          
           str_number = "";
           number_of_intIndex = 0;
           }
       }
       else if( *str_it == '/'){
           number_of_intIndex = 1;
           while(isEelement(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number = str_number + inputString[inputString.find(*str_it) + number_of_intIndex];
               number_of_intIndex++;
           }
           if(str_number != ""){
               int_number = int_number / std::stoi(str_number);
           }
           else{
               std::cout<<"hhhhh";
          
           str_number = "";
           number_of_intIndex = 0;
           }
       }
      
       else if( *str_it == '*'){
               number_of_intIndex = 1;
               while(isEelement(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
                   str_number = str_number + inputString[inputString.find(*str_it, index_position) + number_of_intIndex];
                   number_of_intIndex++;
                   }
               if(str_number != ""){
                   int_number = int_number * std::stoi(str_number);
               }
               else{
                   std::cout<<"hhhhh";
               }
               str_number = "";
               number_of_intIndex = 0;
          
       }
       else if( *str_it == '^'){
           number_of_intIndex = 1;
           while(isEelement(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number = str_number + inputString[inputString.find(*str_it, index_position) + number_of_intIndex];
               number_of_intIndex++;
               }
           if(str_number != ""){
               int_number = pow(int_number, std::stoi(str_number));
           }
           else{
               std::cout<<"hhhhh";
           }
           str_number = "";
           number_of_intIndex = 0;
       }
       else if( *str_it == 'R'){
           number_of_intIndex = 1;
           while(isEelement(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number = str_number + inputString[inputString.find(*str_it, index_position) + number_of_intIndex];
               number_of_intIndex++;
               }
           if(str_number != ""){
               int_number = pow(int_number, 1.0/std::stoi(str_number));
           }
           else{
               std::cout<<"hhhhh";
           }
           str_number = "";
           number_of_intIndex = 0;
       }
   }
 
   std::string str_number_before = "";
   int int_number_before;
 
   str_it = before_x.begin();
   if(str_it != before_x.end()){
       for(str_it = before_x.begin(); str_it != before_x.end(); str_it++){
           index_position_before = -1;
           if(*str_it == '/'){
               while(isEelement(before_x[before_x.find(*str_it) + index_position_before]) == true){
                   str_number_before = str_number_before + before_x[before_x.find(*str_it) + index_position_before];
                   index_position_before --;
               }
               reverseStr(str_number_before);
               int_number_before = std::stoi(str_number_before);
               std::cout<< int_number_before;
 
           }
       }
   }
 
}
 
 
 
 
int main(){
 
   functionStringParser(input);
  
 
 
}
 
