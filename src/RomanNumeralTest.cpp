#include "gtest/gtest.h"

#include "NumeralConverter.h"

class ArabicToRoman : public ::testing::Test {
 protected:
  // virtual void SetUp() {}
  // virtual void TearDown() {}

    NumeralConverter c;
};

TEST_F( ArabicToRoman, OneThroughFive )
{
    ASSERT_STREQ( "I", c.ArabicToRoman(1).c_str() );     
    ASSERT_STREQ( "II", c.ArabicToRoman(2).c_str() );
    ASSERT_STREQ( "III", c.ArabicToRoman(3).c_str() );
    ASSERT_STREQ( "IV", c.ArabicToRoman(4).c_str() );
    ASSERT_STREQ( "V", c.ArabicToRoman(5).c_str() );
}

TEST_F( ArabicToRoman, SixThoughTen )
{
    ASSERT_STREQ( "VI", c.ArabicToRoman(6).c_str() );     
    ASSERT_STREQ( "VII", c.ArabicToRoman(7).c_str() );
    ASSERT_STREQ( "VIII", c.ArabicToRoman(8).c_str() );
    ASSERT_STREQ( "IX", c.ArabicToRoman(9).c_str() );
    ASSERT_STREQ( "X", c.ArabicToRoman(10).c_str() );
}

TEST_F( ArabicToRoman, Teens )
{
    ASSERT_STREQ( "XI", c.ArabicToRoman(11).c_str() );
    ASSERT_STREQ( "XIV", c.ArabicToRoman(14).c_str() );
    ASSERT_STREQ( "XV", c.ArabicToRoman(15).c_str() );
    ASSERT_STREQ( "XVIII", c.ArabicToRoman(18).c_str() );
    ASSERT_STREQ( "XIX", c.ArabicToRoman(19).c_str() );
}

TEST_F( ArabicToRoman, Tens )
{
    ASSERT_STREQ( "XXI", c.ArabicToRoman(21).c_str() );
    ASSERT_STREQ( "XL", c.ArabicToRoman(40).c_str() );   
    ASSERT_STREQ( "L", c.ArabicToRoman(50).c_str() );
    ASSERT_STREQ( "LXXV", c.ArabicToRoman(75).c_str() );
    ASSERT_STREQ( "LXXXIV", c.ArabicToRoman(84).c_str() );
    ASSERT_STREQ( "XCIX", c.ArabicToRoman(99).c_str() );
}

TEST_F( ArabicToRoman, hundreds )
{
    ASSERT_STREQ( "C", c.ArabicToRoman(100).c_str() );
    ASSERT_STREQ( "CDL", c.ArabicToRoman(450).c_str() );   
    ASSERT_STREQ( "D", c.ArabicToRoman(500).c_str() );
    ASSERT_STREQ( "DCCLXXXV", c.ArabicToRoman(785).c_str() );
    ASSERT_STREQ( "CMXCIX", c.ArabicToRoman(999).c_str() );
    ASSERT_STREQ( "M", c.ArabicToRoman(1000).c_str() );
}

TEST_F( ArabicToRoman, ArabicToRomanCapConversionAt3999 )
{
  	ASSERT_STREQ( "MMMCMXCIX", c.ArabicToRoman(3999).c_str() );
    ASSERT_STREQ( "MMMCMXCIX", c.ArabicToRoman(4000).c_str() ); 
}

TEST_F( ArabicToRoman, ArabicToRomanNoNegativeNumbers )
{
  	ASSERT_STREQ( "", c.ArabicToRoman(-1).c_str() );
    ASSERT_STREQ( "", c.ArabicToRoman(0).c_str() ); 
}

class RomanToArabic : public ::testing::Test {
 protected:
  // virtual void SetUp() {}
  // virtual void TearDown() {}

    NumeralConverter c;
};

TEST_F( RomanToArabic, oneThroughfive)
{
  	ASSERT_EQ( 1, c.RomanToArabic( "I" ) );
  	ASSERT_EQ( 1, c.RomanToArabic( "i" ) );
  	
  	ASSERT_EQ( 2, c.RomanToArabic( "II" ) );
  	ASSERT_EQ( 2, c.RomanToArabic( "ii" ) );
  	
  	ASSERT_EQ( 3, c.RomanToArabic( "IiI" ) );
  	
  	ASSERT_EQ( 4, c.RomanToArabic( "IV" ) );  	
  	ASSERT_EQ( 4, c.RomanToArabic( "iV" ) );

  	ASSERT_EQ( 5, c.RomanToArabic( "V" ) );
  	ASSERT_EQ( 5, c.RomanToArabic( "v" ) );
}

TEST_F( RomanToArabic, sixThroughTen )
{
	ASSERT_EQ( 6, c.RomanToArabic( "Vi" ) );
	ASSERT_EQ( 7, c.RomanToArabic( "ViI" ) );
	ASSERT_EQ( 8, c.RomanToArabic( "viii" ) );
	ASSERT_EQ( 9, c.RomanToArabic( "iX" ) );
	ASSERT_EQ( 10, c.RomanToArabic( "x" ) );
}

TEST_F( RomanToArabic, teens )
{
	ASSERT_EQ( 11, c.RomanToArabic( "Xi" ) );
	ASSERT_EQ( 14, c.RomanToArabic( "xIv" ) );
	ASSERT_EQ( 18, c.RomanToArabic( "xviii" ) );
	ASSERT_EQ( 19, c.RomanToArabic( "XiX" ) );
	ASSERT_EQ( 20, c.RomanToArabic( "xx" ) );
}

TEST_F( RomanToArabic, tens )
{
	ASSERT_EQ( 34, c.RomanToArabic( "xxxiv" ) );
	ASSERT_EQ( 40, c.RomanToArabic( "XL" ) );
	ASSERT_EQ( 50, c.RomanToArabic( "L" ) );
	ASSERT_EQ( 90, c.RomanToArabic( "XC" ) );
	ASSERT_EQ( 100, c.RomanToArabic( "C" ) );
}


TEST_F( RomanToArabic, hundreds )
{
	ASSERT_EQ( 300, c.RomanToArabic( "ccC" ) );
	ASSERT_EQ( 500, c.RomanToArabic( "D" ) );
	ASSERT_EQ( 1000, c.RomanToArabic( "M" ) );
	ASSERT_EQ( 1400, c.RomanToArabic( "MCD" ) );
}

TEST_F( RomanToArabic, ValidateString )
{
	ASSERT_EQ( 0, c.RomanToArabic( "" ) );
	ASSERT_EQ( 0, c.RomanToArabic( "invalidChars" ) );
	ASSERT_EQ( 0, c.RomanToArabic( "vximdc" ) );
	ASSERT_EQ( 0, c.RomanToArabic( "vx" ) );
}

TEST_F( RomanToArabic, CheckValidNumberOfChars )
{
	ASSERT_EQ( 0, c.RomanToArabic( "iiii" ) );
	ASSERT_EQ( 0, c.RomanToArabic( "vv" ) );
	ASSERT_EQ( 0, c.RomanToArabic( "xxxx" ) );
	ASSERT_EQ( 0, c.RomanToArabic( "ll" ) );
}

//TEST_F( RomanToArabic, CheckRangeOfString )
//{
//	ASSERT_EQ( 3999, c.RomanToArabic( "MMMCMXCIX" ) );
//	ASSERT_EQ( 3999, c.RomanToArabic( "MMMM" ) );
//}