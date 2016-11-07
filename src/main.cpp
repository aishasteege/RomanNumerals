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
    int arabic = 0;
    
    cout << "\nWelcome to the Roman Numeral Converter\n\n";    
    cout << "Please enter a number (1-3999) to be converted\n";
    cout << "Arabic: ";
    std::getline ( std::cin, input );    
    std::stringstream( input ) >> arabic;
    cout << "Roman : " << converter.ArabicToRoman( arabic ) << endl;
    
    return 0;
}
