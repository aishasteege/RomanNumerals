#include "gtest/gtest.h"

#include "NumeralConverter.h"

class ArabicToRoman : public ::testing::Test {
 protected:
  // virtual void SetUp() {}
  // virtual void TearDown() {}

    NumeralConverter c;
};

TEST_F( ArabicToRoman, One )
{
    ASSERT_STREQ( "I", c.ArabicToRoman(1).c_str() );     
}

TEST_F( ArabicToRoman, Two )
{
    ASSERT_STREQ( "II", c.ArabicToRoman(2).c_str() );
}

TEST_F( ArabicToRoman, Three )
{
    ASSERT_STREQ( "III", c.ArabicToRoman(3).c_str() );
}


//todo:out of range values -1 and 5000