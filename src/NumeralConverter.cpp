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

using namespace std;

int NumeralConverter::RomanToArabic( string roman_num )
{
	int arabic_num = 0;

	while ( roman_num.size() > 0 )
	{
		int character_conversion;
		switch ( toupper( roman_num[0] ) )
		{
			case 'I':
				character_conversion = 1;
				if ( roman_num.size() > 1 )
				{
					if ( toupper( roman_num[1] ) == 'V' )
					{
		    			character_conversion = -1;
					}
				}
				arabic_num += character_conversion;
		    	break;
		    case 'V':
		    	arabic_num += 5;
		    	break;
	    	default:
	    		//the string is invalid
	    		return 0;
		}
    	roman_num.erase( roman_num.begin() );
	}

    return arabic_num;
}

string NumeralConverter::ArabicToRoman ( int arabic_num )
{
    string roman_num;
    
    if ( arabic_num >= 4999 )
	{
		arabic_num = 4999;
	}
    
	int arabic_hundreds = ( arabic_num / 100 );
	int arabic_tens = ( arabic_num / 10 ) % 10;
	int arabic_ones = arabic_num % 10;
    
	roman_num += BasicRomanConversion( 'C', 'D', 'M', arabic_hundreds );
	roman_num += BasicRomanConversion( 'X', 'L', 'C', arabic_tens );
	roman_num += BasicRomanConversion( 'I', 'V', 'X', arabic_ones );

    return roman_num;
}

string NumeralConverter::BasicRomanConversion( char one, char five, char ten, int arabic_num )
{
    string roman_num;
    
	while ( arabic_num > 0 )
	{
		if ( arabic_num <= 3 )
		{
			roman_num += one;
			arabic_num -= 1;
		}
		else if ( arabic_num == 4 || arabic_num == 9 )
		{
			roman_num += one;
			arabic_num += 1;
		}
		else if ( arabic_num <= 8 )
		{
			roman_num += five;
			arabic_num -= 5;
		}
		else
		{
			roman_num += ten;
			arabic_num -= 10;
		}
	}

    return roman_num;
}