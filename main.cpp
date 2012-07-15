/******************************************************************************************************************
*** Name:       Jonathan Canfield																				***
*** Clase:      CPSC 323																						***
*** Professor:  Choi																							***
*** Assignment: #1																								***
*** Due:        9/30/2011																						***
*******************************************************************************************************************/


#include "header.h"
 int main(){
	 /*********************************************************************************************************
	  send out the token and lexem heading. Main runs untill the end of the file is reached. When a char is read 
	  from the file it is first checked thought two if statments. If the char is not one of the requirments of the 
	  two if statements the char is sent to the FSM. When the FSM has done its work; finding whether the element
	  is a identifer, keyword , int or real. process begins again.
	  **********************************************************************************************************/
	    system("Color f");
		cout<<"Token   "<<"       Lexeme\n\n";
		outfile<<"Token   "<<"       Lexeme\n\n";
	/*reading in file one char at a time.*/	 
	 while (!myfile.eof()){		
		
		c = myfile.get();		
		FSM_State= true;
		/******************************************************************************************************
		   checking to see if the char input from file is a separator if it is the function for the separator is 
		   called which will print the token and lex from the fsm. Sets FSM_State to terminated
		 ******************************************************************************************************/
		if (c=='(' || c== ')' || c== '{' || c== '}' ||c =='['|| c== ']'||c==',' ){
			separator_check (c);}

	    /******************************************************************************************************
		 checking to see if the char input from file is a operater if it is the function for the seperator is 
		   called which will print the token and lex from the fsm. sets FSM_State to terminated
		*******************************************************************************************************/
		if ( c== '=' || c== '==' || c== ':' || c== ';' || c== '@' ||c== '%' ||c=='|'|| c== '&'|| c=='#' ||
			c=='*'|| c=='+'||c=='<' || c=='>'|| c=='^' || c== '+' || c=='-'|| c=='/'||c=='*'){
		   	operator_check(c);}

		/*****************************************************************************************************
			if the char from the file is not a separator or operator the FSM_function is called to look for
			a real, int, keyword or identifer
		******************************************************************************************************/		
		if (FSM_State){			
			FSM_functions (c);}
}
        system ("pause");

	 return 0;}

 /****************************************************************************************************
 this is the function for a saperator. the token is set to separater the lexeme is given the input 
 char and the FSM_State is set to false, whcih begins a new fsm state for the input char. 
 ****************************************************************************************************/
 void separator_check (char c){
	  token ="Separator";
	  lexeme= c;
	  FSM(token, lexeme);			
	  FSM_State= false; 
 
 }


 /*********************************************************************************************************************************
 the is the oparater function. since there are some special cases such as "=" ":=" the FSM takes in the char from the file but
 checks the next incoming char to see if it is one of the special cases. if not special case FSM_State is terminated. if special 
 case is found the next char (or lexeme) is taken in and the FSM_State is terminted. finally the FSM is called to print the 
 token and lexeme.
 **********************************************************************************************************************************/
 void operator_check (char c){
	  found_token=false;
	  FSM_State= false;
	  token ="Operator ";
	  lexeme= c;	 
	 
		  if (c ==':'){	
		     char b = myfile.peek();
			    if (b == '='){
					 cc=":=";
					 oparator_check_extra_char (cc);}}
		   if (c =='='){	
		     char b = myfile.peek();
			    if (b == '='){
					 cc="==";
					 oparator_check_extra_char (cc);}}
			
		  if (c =='&'){	
		     char b = myfile.peek();
			    if (b == '&'){
					 string cc="&&";
					oparator_check_extra_char (cc);}}
				
		  if (c =='|'){	
			  char b = myfile.peek();
			    if (b == '|'){
					 string cc="||";
					oparator_check_extra_char (cc);}}

		   if (c =='='){	
			  char b = myfile.peek();
			    if (b == '<'){
					 string cc="=<";
					oparator_check_extra_char (cc);}}

		    if (c =='='){	
			  char b = myfile.peek();
			    if (b == '>'){
					 string cc="=>";
					oparator_check_extra_char (cc);}}

			 if (c =='<'){	
			  char b = myfile.peek();
			    if (b == '='){
					 string cc="<=";
					oparator_check_extra_char (cc);}}
		  
			  if (c =='>'){	
			  char b = myfile.peek();
			    if (b == '='){
					 string cc=">=";
					 lexeme= cc;
					oparator_check_extra_char (cc);}}			  

	//if the was not speical case the orginal input char is sent to the FSM output
		   if (!found_token){
		       FSM(token,lexeme);	
		        count=0;}	
		       found=false;
			  
 }

 /**************************************************************************************************************************************
  This function is called when a "special case" if found for the oparator, this being :=, =< etc.. then the token and lexeme are sent
  to the FSM for output.
  ***************************************************************************************************************************************/
 void oparator_check_extra_char (string cc){
				     lexeme= cc;
					 c = myfile.get();
					 found =true;
					 count=0;
				     FSM(token,lexeme);
					 found_token=true;
 
 }

/**************************************************************************************************************************************
This is the FSM main function for the program. The first set of case statements is for type int or real. While the remaining set of 
case statements are for the identifers and keywords.
***************************************************************************************************************************************/
 void FSM_functions (char c){
  /****************************************************************************************************************************
	this case is for type interger or real. the input is read from the file. If the next int (or lexeme) is a int or "." the 
	FSM_tate is still on untill no int is read i.e. a non real of int character. Once non real or int the state is terminated. 
  *****************************************************************************************************************************/
	 switch  (c){
	 case '0': case '1':
	 case '2': case '3':
	 case '4': case '5':
	 case '6': case '7':
	 case '8': case '9':
	 case '.':	
		 	integer_real(c);
			break;
	case 'a' : case 'A':      
 	case 'b' : case 'B':      
 	case 'c' : case 'C':      
 	case 'd' : case 'D':      	
 	case 'e' : case 'E':      
 	case 'f' : case 'F':      	
 	case 'g' : case 'G':      
 	case 'h' : case 'H':      	
 	case 'i' : case 'I':      	
 	case 'j' : case 'J':      
 	case 'k' : case 'K':      	
 	case 'l' : case 'L':      	
 	case 'm' : case 'M':      	
 	case 'n' : case 'N':      
 	case 'o' : case 'O':      	
 	case 'p' : case 'P':      
 	case 'q' : case 'Q':      	
 	case 'r' : case 'R':      
 	case 's' : case 'S':      	
 	case 't' : case 'T':      
 	case 'u' : case 'U':      
 	case 'v' : case 'V':     
 	case 'w' : case 'W':      	
 	case 'y' : case 'Y':      	
 	case 'z' : case 'Z':
	case '_':
            identifer(c);
     break;
		   
	   }
		 



 }
 /************************************************************************************************
 This is part of the FSM which prints the token and lexeme from the terminated FSM_State.
 ************************************************************************************************/
  void FSM(string tok, string lex){
  cout<< tok<< "      " <<lex<<"\n";
  outfile<<tok<< "      " <<lex<<"\n";
  count=0;

  }
  /***************************************************************************************************************************************
  The function for type int and real. The function takes in a int or '.' then checks for the next incoming element from the file.
  if the next incoming element is a int of '.' the FSM_State if still active, if the next element from the file is not a int or '.' 
  the FSM_State is terminated. Once the FSM_state is terminted the input from the file is checked for the special case '.' for real.
  If there are mutiple "." the token is unknown.  Then the FSM is sent the correct token and lexeme and the FSM_State is terminated.
  ****************************************************************************************************************************************/
  void integer_real(char c){
  
  int counter=0;	
  FSM_State=true;
  toker="Integer  ";
  int dec_check=0;
  bool dec_checker=false;
		z[count]=c;		
		count++;
		char b =myfile.peek();
			//checking to see if the next incoming element form the text file is a int if so the FSM_state is still active.
		   if (b == '0' || b =='1'|| b == '2' || b== '3' || b=='4' || b=='5' || b=='6' || b=='7' || b=='8' || b=='9' || b== '.'){
			  FSM_State=true;
			       }
		   else {FSM_State=false;}
			  //once the FSM_State is terminated a check is made to see if the int is actually a real number. If so the real token is sent to the FSM 
		     
			   if (!FSM_State){			 
				   counter=0;
				   lexeme=z;
				   //checking to see if its a real, operator or unknown.
				   while (counter != count){
				        if (z[counter] == '.'){
							dec_check++;}
						 counter++;}
						if (dec_check == 1 && count > 1){
					    	  toker="Real     ";}
						if (dec_check == 1 && count == 1){
					    	  toker="operator ";}
						if (dec_check > 1){
							toker="unknown  ";}
					  
		
			
			 //if the elements read from the file are not real numbers the integer token a elements are sent to the FSM.
		       FSM(toker,lexeme);
			   count=0;		
			   clear_array ();
	     }
  }
  
  /*********************************************************************************************************************************************************
    The function for identifer and keyword. The function runs untill a non-identifer value is found from the next incoming element from the text file.******
    when a non identifer value is found from the next incoming elemnt the FSM_State is terminated. Once terminted the string or char for the identifer is ** 
    checked for special cases such is if the identifer is acutally a KEYWORD or if a '_a' is sent in which is invalid. This results in "_a" being unknown 
	token
	*******************************************************************************************************************************************************/
  void identifer( char c){
	  bool found_key=true;
	  bool end_run= true;
	  FSM_State=true;
	  int counter=0;	
	  toker = "Identifer";	 	 
	  for_identifer[count]=c;		
	  count++;	 
	 //runs untill the next incoming element is not a char that would be considered a identifer or keyword. 
	 //if not the FMS state is terminated
	 while (end_run){ 

	 char b =myfile.peek();
	  //checking for incoming element from file. If the element is a char or _ then the FSM_State is still active.
	  if (b=='_'||b == 'a' || b =='A'|| b == 'b' || b== 'B' || b=='c' || b=='C' || b=='d' || b=='D' || b=='e' || b=='E' || b== 'f'
		|| b== 'F'|| b== 'g'|| b== 'G'|| b== 'h'|| b== 'H'|| b== 'i'|| b== 'I'|| b== 'j'|| b== 'J'|| b== 'K'|| b== 'k'|| b== 'l'|| b== 'L'
		|| b== 'm'|| b== 'M'|| b== 'N'|| b== 'n'|| b== 'o'|| b== 'O'|| b== 'P'|| b== 'p'|| b== 'q'|| b== 'Q'|| b== 'r'|| b== 'R'
		|| b== 's'|| b== 'S'|| b== 't'|| b== 'T'|| b== 'u'|| b== 'U'|| b== 'v'|| b== 'V'|| b== 'w'|| b== 'W'|| b== 'x'|| b== 'X'
		|| b== 'y'|| b== 'Y'|| b== 'z'|| b== 'Z'||b == '0'|| b =='1'|| b== '2'|| b== '3'|| b=='4' || b=='5' || b=='6' || b=='7'
		|| b=='8' || b=='9' ){FSM_State=true;}
	  else {FSM_State=false;
			end_run=false;}
			if (FSM_State){
				for_identifer[count] = myfile.get();			     
				count++;}	
	 }
	
     //once the FSM_State is terminted a check is made to see if the identifer is actually a KEYWORD. If it is the case then FSM is called to ouput the 
	 // keyword.
	
	 check_unknown_identifer (); //checking to see if the final input is actually a unknown.
	 
	 if (!FSM_State){ 
	      counter=0;
		  lexeme = for_identifer;
	     //checking for input being a keyword.
		  while (counter !=66 && found_key){
		    	 if (lexeme ==keywords[counter]){
					found_key = false;
			    	toker= "Keyword  ";					
					FSM(toker,lexeme);}
				 counter++;
		            }					
	  //if its not a keyword the FSM is called to output the identifer
	    if (found_key){					
	    	 FSM(toker,lexeme);}	   
			//clearing the array holding the chars taken in from the file for the identifer. 
	  clear_array ();
	  count=0;				  
	  }
		 
  }
  /*************************************************************************************
  cleaing the arrays which stored input from the active state of the FSM. This function
  is called when the fsm state is terminated. 
  *************************************************************************************/
  void clear_array ()
  {
	
	  for (int counter = 0; counter != 30; counter++){	
			 for_identifer[counter]='\0';
			 z[counter]='\0';			
	  }		
  }

/******************************************************************************************
This function checks to see is the identifer is not a proper identifer. the checks include
"_A", "abc123"  and "an__aa". If the standards of identifer are not met the token is set to 
unknown.
*******************************************************************************************/

  void check_unknown_identifer (){
	 int counter=0;
	 int counters=1;
	 bool tot=false;
	 //checking for '_' in the array if there is then int might be okay in the identifer.
		for (counter=0; counter != count; counter++){	
		 if (for_identifer[counter] == '_'){
			 tot=true;}	
		}
		
	 counter=0;
	 //if the first element is '_' the token is set to unknown
	if (for_identifer[0] == '_'){
	  toker="Unknown  ";
	  FSM_State=false;}

	//this is the big check. looking for input such as '__' and input of 'abc123'
	while (counters != count && !FSM_State){
		 if (for_identifer[counter] == '_' && for_identifer[counters]== '_'){		
		     lexeme = for_identifer;
		     toker = "unknown  ";
			 FSM(toker,lexeme);
		     FSM_State=true;
			 clear_array ();}		 
	     if (!tot){
		    if (for_identifer[counter] =='0'||for_identifer[counter] =='1'||for_identifer[counter] =='2'||for_identifer[counter] =='3'||
		    	for_identifer[counter] =='4'||for_identifer[counter] =='5'||for_identifer[counter] =='6'||for_identifer[counter] =='7'||
		    	for_identifer[counter] =='8'||for_identifer[counter] =='9'){
		   
			    lexeme = for_identifer;
		        toker = "unknown  ";
			    FSM(toker,lexeme);
		        FSM_State=true;
			    clear_array ();}
			}
		 counters++;
		 counter++;}
  }