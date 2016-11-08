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

///=============================================================================
/// convert an arabic number to roman numerals 
/// \param[in] string	a roman numeral representation
/// \return int 		arabic_number, or zero if string is invalid
int NumeralConverter::RomanToArabic( string roman_num )
{
	int arabic_num = 0;

	if ( !ValidateRomanString( roman_num ) )
	{
		// invalid string, return zero
		return 0;
	}
	
	for ( unsigned int i = 0; i < roman_num.size(); i++)
	{
		if ( i < ( roman_num.size() - 1 ) )
		{
			//if first character is less than the next its subtraction
			if ( ConvertRomanChar( roman_num[i] ) < 
				 ConvertRomanChar( roman_num[i+1] ) )
			{
				arabic_num -= ConvertRomanChar( roman_num[i] );
			}
			else
			{
				arabic_num += ConvertRomanChar( roman_num[i] );	
			}
		}
		else
		{
			arabic_num += ConvertRomanChar( roman_num[i] );	
		}
		
	}
    return arabic_num;
}

///=============================================================================
/// convert a roman numeral character
///\param[in] string	roman numeral character string
///\return bool			true if the string is a valid roman numeral string
int NumeralConverter::ConvertRomanChar( char roman_numeral )
{
	switch ( toupper( roman_numeral ) )
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

///=============================================================================
/// check that the roman numeral string is has valid ordering and valid chars
///\param[in] string	roman numeral character string
///\return bool			true if the string is a valid roman numeral string
bool NumeralConverter::ValidateRomanString( string roman_num )
{
	//test for invalid characters
	for ( unsigned int i = 0; i < roman_num.size(); i++ )
	{
		if ( ConvertRomanChar( roman_num[i] ) == 0 )
		{
			return false;
		}
	}
	
	//test for correct character ordering
	for ( unsigned int i = 0; i < (roman_num.size() - 1); i++ )
	{
		if ( !CheckValidRomanSubString( roman_num[i], roman_num[i+1] ) )
		{
			return false;
		}
	}
	
	return true;
}

///=============================================================================
/// check that the two characters are in a valid order 
///\param[in] char 		first roman numeral character 
///\param[in] char 		second roman numeral character
///\return bool			true if the characters ordering
bool NumeralConverter::CheckValidRomanSubString( char first, char second )
{
	first = toupper( first );
	second = toupper( second );
	
	if ( ConvertRomanChar( first ) < ConvertRomanChar( second ) )
	{
		if ( ( (first == 'I') && ( (second == 'V') || (second == 'X') ) ) || 
		     ( (first == 'X') && ( (second == 'L') || (second == 'C') ) ) ||
		     ( (first == 'C') && ( (second == 'D') || (second == 'M') ) ) )
		{
			return true;
		}
		return false;
	}
	
	return true;
}

///=============================================================================
/// convert an arabic number to roman numerals 
/// \param[in] int 	arabic_number ( 0 - 3999 )
/// \return string	the roman numeral representation	
string NumeralConverter::ArabicToRoman ( int arabic_num )
{
    string roman_num;
    
    if ( arabic_num >= 3999 )
	{
		arabic_num = 3999;
	}
    
	int arabic_hundreds = ( arabic_num / 100 );
	int arabic_tens = ( arabic_num / 10 ) % 10;
	int arabic_ones = arabic_num % 10;
    
	roman_num += BasicRomanConversion( 'C', 'D', 'M', arabic_hundreds );
	roman_num += BasicRomanConversion( 'X', 'L', 'C', arabic_tens );
	roman_num += BasicRomanConversion( 'I', 'V', 'X', arabic_ones );

    return roman_num;
}

///=============================================================================
/// convert an arabic number to roman numerals 
/// \param[in] one			string to represent one of the power of 10 
/// \param[in] five			string to represent five of the power of 10
/// \param[in] ten			string to represent ten of the power of 10
/// \param[in] arabic_num	int number to be converted devided by the power of 10 
///							being represented ( accurate for 0-39 )
string NumeralConverter::BasicRomanConversion( char one, char five, char ten,
	int arabic_num )
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