 
#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <math.h>


std::string inputFunction;
 
//2d vector for the base of the cordinate space
std::vector<std::vector<std::string>> matrix;
//the upper part of the y axis
std::vector<std::string> from_1_to_25{" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "
," "," "," "," ","+"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "};
//x axis
std::vector<std::string> x_axis{"+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+"
,"+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+","+"};
// the lower part of the y axis
std::vector<std::string> from_minus1_to_minus25{" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "
," "," "," "," ","+"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "};
 
//map to store the data pairs for the plotting
std::map<int ,double> values;


//might need them for an iterator solution 
//std::vector<std::vector<std::string>>::iterator row_vector_ptr;
//std::vector<std::string>::iterator col_vector_ptr;

std::map<int, double>::iterator map_iter;
 

 
int number_of_intIndex;
int int_number = 0;
std::string str_number = "";
int index_position = -1;
int index_position_before = -1;
 
std::string before_x;
 
std::string::iterator str_it;
char base_numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
char arithmetic_operators[6] = {'-', '+', '/', 'R', '^', '*'};


bool isEelement_of_arithmetic_operators(char character){
   char target = character;
 
   for(auto& c : arithmetic_operators){
       if(c == target){
           std::cout<<"valid ar ";
           return true;
          
       }
   }
   std::cout<<"false ar ";
   std::cout<< target;
   return false;
}
bool isEelement_of_basenumbers(char character){
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
 

    // it substract the parts before x from the string
   std::string::size_type i = inputString.find(before_x);
 
   if(i != std::string::npos){
       inputString.erase(i , before_x.length());
   }
   // true caption --> how to become a programer and get hired and i got hired
 
 
   std::cout<< before_x<< " ";
   std::cout<< inputString;
 // starts the evalueation ofthe string after x
   for(str_it = inputString.begin(); str_it != inputString.end(); str_it++){
       std::cout<< "begin " <<*str_it << " ";
       index_position += 1;
       if( *str_it == '+'){
           number_of_intIndex = 1;
           while(isEelement_of_basenumbers(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number +=(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]);
               number_of_intIndex++;
               std::cout<<str_number;
           }
           int_number = int_number + std::stoi(str_number);

           for(auto& c : values){
            c.second = c.second + std::stoi(str_number);
           }
          
           str_number = "";
           number_of_intIndex = 0;
       }
       else if( *str_it == '-'){
           number_of_intIndex = 1;
           while(isEelement_of_basenumbers(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number = str_number + inputString[inputString.find(*str_it) + number_of_intIndex];
               number_of_intIndex++;
           }
           if(str_number != ""){
               
            for(auto& c : values){
                c.second = c.second - std::stoi(str_number);
            }
           }
          
           str_number = "";
           number_of_intIndex = 0;
       }
       else if( *str_it == '/'){
           number_of_intIndex = 1;
           while(isEelement_of_basenumbers(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number = str_number + inputString[inputString.find(*str_it) + number_of_intIndex];
               number_of_intIndex++;
           }
           if(str_number != ""){

                for(auto& c : values){
                    c.second = c.second / std::stoi(str_number);
                }
           }
           
          
           str_number = "";
           number_of_intIndex = 0;
       }
       else if( *str_it == '*'){
               number_of_intIndex = 1;
               while(isEelement_of_basenumbers(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
                   str_number = str_number + inputString[inputString.find(*str_it, index_position) + number_of_intIndex];
                   number_of_intIndex++;
                   }
               if(str_number != ""){
                   for(auto& c : values){
                        c.second = c.second * std::stoi(str_number);
                    }
            
               }
               str_number = "";
               number_of_intIndex = 0;
          
       }
       else if( *str_it == '^'){
           number_of_intIndex = 1;
           while(isEelement_of_basenumbers(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number = str_number + inputString[inputString.find(*str_it, index_position) + number_of_intIndex];
               number_of_intIndex++;
               }
           if(str_number != ""){
                
            for(auto& c : values){
                    c.second = pow(c.second, std::stoi(str_number));
                }
           }
           
           str_number = "";
           number_of_intIndex = 0;
       }
       else if( *str_it == 'R'){
           number_of_intIndex = 1;
           while(isEelement_of_basenumbers(inputString[inputString.find(*str_it, index_position) + number_of_intIndex]) == true){
               str_number = str_number + inputString[inputString.find(*str_it, index_position) + number_of_intIndex];
               number_of_intIndex++;
               }
           if(str_number != ""){
               for(auto& c : values){
                        c.second = pow(c.second, 1.0/std::stoi(str_number));
                    }
               
           }
           str_number = "";
           number_of_intIndex = 0;
       }
   }
 
   std::string str_number_before = "";
   int int_number_before;
 
   str_it = before_x.end();
   if(isEelement_of_arithmetic_operators(before_x[before_x.size() - 2]) == true){
       for(str_it = before_x.begin(); str_it != before_x.end(); str_it++){
           index_position_before = -1;
           if(*str_it == '/'){
               while(isEelement_of_basenumbers(before_x[before_x.find(*str_it) + index_position_before]) == true){
                   str_number_before = str_number_before + before_x[before_x.find(*str_it) + index_position_before];
                   index_position_before --;
               }
               reverseStr(str_number_before);
               int_number_before = std::stoi(str_number_before);
                for(auto& c : values){
                    c.second = int_number_before / c.second;
                }
 
           }
       }
    }
} 
 
// fills the the data pairs with the basic values ex: 1-->1 
void fill_base_map_values(){
   for(int i = -25; i < 26; i++){
       values.insert({i,i});
   }
}
 
// fillst the matrix with the preinitialized vectors
void fill_base_matrix(){
 
   for(int i = 0; i < 25; i++){
       matrix.push_back(from_1_to_25);
   }
   matrix.push_back(x_axis);
 
   for(int i = 0; i<25; i++){
       matrix.push_back(from_minus1_to_minus25);
   }
}

//tool for test
void log_print_map(){
   for(auto& i : values){
       std::cout<< i.first << " "<< i.second<<std::endl;
   }
}
//tool for test
void log_print_matrix(){
   matrix[25 - 3][25 - 2] = "#";
}
 
 
//this is the input function --> modifies the values of the bas map
void input(){
  std::cout<< "please write a function"<<std::endl;
  std::cout<<"^ = exponentiation"<<std::endl;
  std::cout<<"R = nth root"<<std::endl;
  std::cout<<"- = substraction"<<std::endl;
  std::cout<<"+ = addition"<<std::endl;
  std::cout<<"* = mulitplication"<<std::endl;
  std::cout<<"example function --> (x+3)*2"<<std::endl;
  std::cin>> inputFunction;

}
 
// the final print of the matrix
void print_matrix(){
   for(int i = 0; i < matrix.size(); i++){
       for(int j= 0; j<matrix[i].size(); j++){
           std::cout<< matrix[i][j]<<" ";
       }
       std::cout<<std::endl;
   }
}

// check if theres any values that cant be visualized due to the lack of space
void checkfor_over_or_under_values(){
   for(auto&c : values){
       if(c.second > 25 || c.second < -25){
           c.second = 100;
       }
   }
}
 
void check_for_duplicates(){

    for(map_iter = values.begin(); map_iter != values.end(); ++map_iter){
        

        // ha c.s < 0 then delete current
        if(map_iter ->first < 0 && map_iter -> second == std::next(map_iter) ->second){
            values.erase(map_iter++);
        }
        /*
        // ha c.s = 0 then delete current and delet next
        if(current == 0 && current == next && current == previous){
            values.erase(previous);
            values.erase(next);
        }
        */
        if(map_iter -> first > 0 && map_iter->second == std::prev(map_iter) ->second){
            values.erase(map_iter--);
        }
    }
}
 
// it changes the matrix with the modified values from the map
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
   fill_base_matrix();
   input();
   functionStringParser(inputFunction);
   //checkfor_over_or_under_values();
   //check_for_duplicates();
   log_print_map();
   //change_matrix();
   //print_matrix();

  
   //for(row_vector_ptr = matrix.begin(); row_vector_ptr != matrix.end(); row_vector_ptr++){
     //  for(col_vector_ptr = row_vector_ptr->begin(); col_vector_ptr != row_vector_ptr->end(); col_vector_ptr++){
       //    std::cout<< *(row_vector_ptr  + 1);
      // }
  // }
 
}