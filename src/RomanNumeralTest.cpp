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
//todo:out of range values -1 and 5000