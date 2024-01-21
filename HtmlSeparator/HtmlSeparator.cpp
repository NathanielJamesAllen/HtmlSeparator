//******************************************************************
// HTML-CNVT.CPP
// Program to place HTML commands and text in separate files
// James Allen
// March 11, 2021
//******************************************************************
#include <iostream>
#include <fstream>    // For file I/O

using namespace std;

ifstream inHTML;          // Standard HTML file for input
ofstream outTEXT;         // Holds text from HTML file
ofstream outCMDS;         // Holds commands from the HTML file

void write_files(char ch, bool& getting_text);//Function declaration
void close_files(void);//Function declaration


int main()
{
	char ch;//variable declarations
	bool getting_text;

	// Open the files
	cout << "Opening files.....";//displays message
	inHTML.open("Lab5html.htm");//opens file "lect-events.htm"
	outTEXT.open("htmltext.txt");//opens file "htmltext.txt"
	outCMDS.open("htmlcmds.txt");//opens file "htmlcmds.txt"
	cout << "complete" << endl << endl;//displays message

	// Get data
	cout << "Writing files.....";//displays message
	getting_text = true;
	while (inHTML) {//while inHTML is not in a fail state
		ch = inHTML.get();//assign input from inHTMl to ch
		write_files(ch, getting_text);//call to the function
		cout << ".";//print a period at the end
	}
	cout << "complete" << endl << endl;//displays message

	close_files();//call to the function
	return 0;
}

void write_files(char ch, bool& getting_text) {//function heading
//if ch equal to <, getting text is falsee, displays newline for outTEXT, displays value of ch to outCMDS
	if (ch == '<') {
		getting_text = false;
		outTEXT << endl;
		outCMDS << ch;
	}
	//if ch equal to >, displays value of ch to outCMDs, getting text is true
	else {
		if (ch == '>') {
			outCMDS << ch << endl;
			getting_text = true;
		}
		//if getting text is true, display value of ch to outTEXT
		else {
			if (getting_text == true) {
				outTEXT << ch;
			}
			//otherwise, display value of ch to outCMDS
			else {
				outCMDS << ch;
			}
		}
	}

}

void close_files(void) {//function heading
	outTEXT << endl;//displays newline for outTEXT
	outCMDS << endl;//displays newline for outCMDS
	inHTML.close();//closes lect-events.htm
	outTEXT.close();//closes htmltext.txt 
	outCMDS.close();//closes htmlcmds.txt

}