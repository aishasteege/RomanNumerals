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

TEST_F( ArabicToRoman, ArabicToRomanCapConversionAt4999 )
{
  	ASSERT_STREQ( "MMMMCMXCIX", c.ArabicToRoman(4999).c_str() );
    ASSERT_STREQ( "MMMMCMXCIX", c.ArabicToRoman(5000).c_str() ); 
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
  	
//  	ASSERT_EQ( 3, c.RomanToArabic( "IiI" ) );
//  	
//  	ASSERT_EQ( 4, c.RomanToArabic( "iV" ) );
//
//  	ASSERT_EQ( 5, c.RomanToArabic( "V" ) );
//  	ASSERT_EQ( 5, c.RomanToArabic( "v" ) );
}
