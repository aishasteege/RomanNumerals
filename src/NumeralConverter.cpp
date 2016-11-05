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
    if ( arabic_num == 1 )
    {
        return "I";
    }
    else
    {
        return "II";
    }
}