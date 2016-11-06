#include "gtest/gtest.h"

#include "NumeralConverter.h"

TEST( ArabicToRoman, One )
{
    NumeralConverter c;
    
      ASSERT_STREQ( "I", c.ArabicToRoman(1).c_str() );     
}

TEST( ArabicToRoman, Two )
{
    NumeralConverter c;
    
      ASSERT_STREQ( "II", c.ArabicToRoman(2).c_str() );
}


TEST( ArabicToRoman, Three )
{
    NumeralConverter c;
    
      ASSERT_STREQ( "III", c.ArabicToRoman(3).c_str() );
}
//todo:out of range values -1 and 5000