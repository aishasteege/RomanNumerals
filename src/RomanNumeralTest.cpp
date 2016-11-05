#include "gtest/gtest.h"

#include "NumeralConverter.h"

TEST(ArabicToRoman, First)
{
    NumeralConverter c;
    
      EXPECT_EQ( "I", c.ArabicToRoman(1));
}