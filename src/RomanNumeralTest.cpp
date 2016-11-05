#include "gtest/gtest.h"

#include "NumeralConverter.h"

TEST( ArabicToRoman, One )
{
    NumeralConverter c;
    
      EXPECT_EQ( "I", c.ArabicToRoman(1) );     
      EXPECT_EQ( "II", c.ArabicToRoman(2) );
}

TEST( ArabicToRoman, Two )
{
    NumeralConverter c;
    
      EXPECT_EQ( "II", c.ArabicToRoman(2) );
}