#include <iostream>	//standard functions
#include <fstream>	//reading file
#include <cstdlib>	//exit()
#include <string>
#include "GenStack.h"	//stack class
using namespace std;
int main(int argc, char** argv)
{
	if (argc < 2 || argc >= 3){	//message pops out if no filename passed in command line or incorrect argument taken
		cout << "This program is designed to read a file and check for missing delimiters.\n";
		cout << "The program must be run with an accompanying path to your file.\n";
		cout << "EX: './a.out /home/cpsc/Documents/foo.cpp'\n";
	}
	else{
		fstream inFile;
		string theFile = argv[1];	//take file from command line argument
		char delimL, delimR, x;
		string currentLine;
		int line = 1;
		GenStack<char> g(20);	//initialize stack
		inFile.open(theFile.c_str());
		while(getline(inFile, currentLine))
		{	//left delimiter found, push into stack
			for(int i = 0; i <= currentLine.size(); i++)
			{
				x = currentLine[i];
				if(x == '{' || x == '[' || x == '(') g.push(x);
				else if(x == '}' || x == ']' || x == ')')
				{	//right delimiter found
					delimL = g.pop();	//pop last left delimiter found
					delimR = x;			//new variable for clarity
					if( (delimL == '{' && delimR == '}') ||
						(delimL == '[' && delimR == ']') ||
						(delimL == '(' && delimR == ')') )
					{	//delimiters match, null out then continue to prevent confusion
						delimL = '\0';	delimR = '\0';
						continue;	//continue program
					}
					else{	//delimiters do not match
						cout << "Error detected at line " << line << ".\n"
						<< delimR << " was found, ";
						if(delimL == '(') cout << ") expected.\n";
						else if(delimL == '{') cout << "} expected.\n";
						else if(delimL == '[') cout << "] expected.\n";
						else
						{	//delimiters do not match or
							if(delimR == ')') cout << "Prior ( is missing.\n";
							else if(delimR == '}') cout << "Prior { is missing.\n";
							else if(delimR == ']') cout << "Prior [ is missing.\n";
						}	//left delimiter is missing
						exit(1);
					}
				}
			}
			line++;
		}
		if(g.isEmpty() != 1){	//if stack is not empty, right delimiter missing
			cout << "Delimiters are imbalanced.\n";
			delimL = g.peek();
			cout << delimL << " is missing an accompanying ";
			if(delimL == '(') cout << ")\n";
			else if(delimL == '{') cout << "}\n";
			else if(delimL == '[') cout << "]\n";
		}
		else cout << "Program has no missing delimiters.\n";
	}
}
