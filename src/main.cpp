/* ===================================================
 * This is the main function to act as the interface
 * to the roman numeral converter
 *
 *  Created on: Nov 6, 2016
 *      Author: Aisha Steege
 *===================================================*/

#include <iostream>
#include <sstream>
#include <string>

#include "NumeralConverter.h"

using namespace std;

main()
{
    NumeralConverter converter;
    std::string input ("0");
    
    cout << "\nWelcome to the Roman Numeral Converter\n\n";    
    cout << "Would you like to convert \n   (1) roman to arabic\n   (2) arabic to roman \n ";    
    
    int selection = 0;
    std::getline ( std::cin, input );    
    std::stringstream( input ) >> selection;
    
    if ( selection == 1)
    {
	    cout << "Please enter a number (I-MMMCMXCIX) to be converted\n";
	    cout << "Roman : ";
	    std::string roman;
	    std::getline ( std::cin, roman );    
	    cout << "Arabic: " << converter.RomanToArabic( roman ) << endl;
    }
    else if ( selection == 2 )
    {
	    cout << "Please enter a number (1-3999) to be converted\n";
	    cout << "Arabic: ";
    	int arabic = 0;
    	std::getline ( std::cin, input );    
	    std::stringstream( input ) >> arabic;
	    cout << "Roman : " << converter.ArabicToRoman( arabic ) << endl;
    }
    else
    {
    	cout << "Im sorry, that selection was invalid";
    }
    
    return 0;
}
