/* ===================================================
 * NumeralConverter.cpp
 *
 * This is a class to convert between roman and arabic
 * numerals
 *
 *  Created on: Nov 4, 2016
 *      Author: Aisha Steege
 *===================================================*/

#include "NumeralConverter.h"

std::string NumeralConverter::ArabicToRoman ( int arabic_num )
{
    std::string roman_num;
    
	while ( arabic_num > 0 )
	{
		if ( arabic_num <= 3 )
		{
			roman_num += "I";
			arabic_num -= 1;
		}
		else if ( arabic_num == 4 || arabic_num == 9 )
		{
			roman_num += "I";
			arabic_num += 1;
		}
		else if ( arabic_num <= 8 )
		{
			roman_num += "V";
			arabic_num -= 5;
		}
		else
		{
			roman_num += "X";
			arabic_num -= 10;
		}
	}

    return roman_num;
}