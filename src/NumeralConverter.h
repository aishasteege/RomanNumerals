#ifndef SRC_NUMERALCONVERTER_H_
#define SRC_NUMERALCONVERTER_H_
/* ===================================================
 * NumeralConverter.h
 *
 * This is a class to convert between roman and arabic
 * numerals
 *
 *  Created on: Nov 4, 2016
 *      Author: Aisha Steege
 *===================================================*/

#include <string>

class NumeralConverter {
public:
	std::string ArabicToRoman( int arabic_num );
	
private:
	std::string BasicRomanConversion( char one, char five, char ten, int arabic_numeral );
};

#endif /* SRC_NUMERALCONVERTER_H_ */