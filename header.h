/******************************************************************************************************************
*** Name:       Jonathan Canfield																				***
*** Clase:      CPSC 323																						***
*** Professor:  Choi																							***
*** Assignment: #1																								***
*** Due:        9/30/2011																						***
*******************************************************************************************************************/

#include <iomanip>
#include <iostream> 
#include <string>
#include <iostream>
#include<fstream>
using namespace std;

 void clear_array ();            //clears the array which held the identifers, in or real. 
 void check_unknown_identifer();
 void FSM_functions (char);      //function which checks the FSM for int, real, identifer or keyword
 void FSM(string, string);       //the FSM which recieves the token and lexeme 
 void operator_check (char);     //takes in oparator from file check for additional element. either case sends token ,lexeme to FSM
 void separator_check (char);    //takes in separator from files, sends to FSM for token and lexeme
 void integer_real(char);		 //takes in int or '.' checks if final readin from file is real or int. sends tokens,lexeme to FSM
 void oparator_check_extra_char (string); //if additonal oparator is found i.e. ":=" sends token and lexeme to FSM
 void identifer (char);          //takes in char's for identifer, checks for keyword and errors i.e "__" sends token, lesxeme to FSM
 char z[100];					 //used of storage of intergers and real
 string token;                   //used in FSM for token
 string toker;					 //used to send token to FSM
 string lexeme;					 //used in FSM for lexeme
 int count=0;					 //important counter for storing elements in array from file. must be reseet when FSM terminated. 
 int count_identifer=0;		     //used to check if input from text is '__' i.e. abc__dfg if so FSM terminated at first '_'
 char c;					     //input from file stored in char c
 char for_identifer[30];		 //input stored for the purpose of identifer. later transfer to string for FSM keyword check and output
 string cc;						 //used to send oparator to FSM ie :=, ==....
 bool found = false;             
 bool found_token=false;		 //bool value for if s token was found or not
 bool FSM_State= true;	         //the state of the FSM state turns off when specifc events occur.
 

 string keywords []= {"absolute" , "and", "array", "begin", "case", "const", "div", "downto", "end", "external", "file", "for",
	                  "forward", "function", "goto", "in", "inline", "label", "mod", "nil", "not","or", "overly", "packed", "procedure",
					   "program", "record", "repeat", "set", "shl","then","to", "type", "until", "var","with", "xor","write","print","scan",
					   "while", "do", "if", "else","endif","int","char","string","double","const","false","true","long","delete","catch",
					   "break","case","short","try","void","static","enum","return","unsigned","switch"};
  
  ifstream myfile ("rat11f.txt");  //The text file which is read. This contains the users source code.
  ofstream outfile ("output.txt"); //outputs the results from the source code.