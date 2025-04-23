/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	ASSERT_EQ(1, Password().count_leading_characters("Z"));
}

TEST(PasswordTest, two_leading_a)
{
	ASSERT_EQ(2, Password().count_leading_characters("aab"));
}

TEST(PasswordTest, aardvark)
{
	ASSERT_EQ(2, Password().count_leading_characters("aardvark"));
}

TEST(PasswordTest, Aardvark)
{
	ASSERT_EQ(1, Password().count_leading_characters("Aardvark"));
}

TEST(PasswordTest, snake)
{
	ASSERT_EQ(8, Password().count_leading_characters("ssssssss"));
}

TEST(PasswordTest, angry_snake)
{
	ASSERT_EQ(6, Password().count_leading_characters("ssssssSs"));
}

TEST(PasswordTest, palindromic)
{
	ASSERT_EQ(1, Password().count_leading_characters("stackcats"));
}

TEST(PasswordTest, gibberish)
{
	ASSERT_EQ(3, Password().count_leading_characters("aaaAaaoodjoaaaomcfejq"));
}

TEST(PasswordTest, empty)
{
	ASSERT_EQ(0, Password().count_leading_characters(""));
}

TEST(PasswordTest, strange)
{
	ASSERT_EQ(2, Password().count_leading_characters("--3123@@391-2"));
}

TEST(PasswordTest, long_one)
{
	ASSERT_EQ(1040, Password().count_leading_characters("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
}

TEST(PasswordTest, wrong_one)
{
	ASSERT_EQ(72, Password().count_leading_characters("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaawefilwjmfioewnjfiu;onndewfnkewnaerkjlsn aerkjq34wofnmaerwfnmgkmaergmewfmew,fraer,mesmgkmerpgf34k,[,ldf'[qw;,few';g,er'[l,kg4l][;dew][fewl.e,gw;pefw['few]]]]"));
}

TEST(PasswordTest, space_jockey)
{
	ASSERT_EQ(10, Password().count_leading_characters("          joewn           "));
}

TEST(PasswordTest, space_jockey_two)
{
	ASSERT_EQ(1, Password().count_leading_characters("9         joewn           "));
}

TEST(PasswordTest, space_jockey_three)
{
	ASSERT_EQ(35, Password().count_leading_characters("                                   "));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(PasswordTest, mixed_case_both)
{
	ASSERT_TRUE(Password().has_mixed_case("AbAbAbA"));
}

TEST(PasswordTest, mixed_case_lower)
{
	ASSERT_FALSE(Password().has_mixed_case("abababab"));
}

TEST(PasswordTest, mixed_case_upper)
{
	ASSERT_FALSE(Password().has_mixed_case("ABABABAB"));
}

TEST(PasswordTest, mixed_case_empty)
{
	ASSERT_FALSE(Password().has_mixed_case(""));
}

TEST(PasswordTest, mixed_case_non_an)
{
	ASSERT_FALSE(Password().has_mixed_case("-"));
}

TEST(PasswordTest, mixed_case_digit)
{
	ASSERT_FALSE(Password().has_mixed_case("4"));
}

TEST(PasswordTest, mixed_case_digits)
{
	ASSERT_FALSE(Password().has_mixed_case("123"));
}

TEST(PasswordTest, mixed_case_space)
{
	ASSERT_FALSE(Password().has_mixed_case(" "));
}

TEST(PasswordTest, mixed_case_long_non_an)
{
	ASSERT_FALSE(Password().has_mixed_case("-- +-*-"));
}

TEST(PasswordTest, mixed_case_long_non_alpha)
{
	ASSERT_FALSE(Password().has_mixed_case("-0 +-60 --"));
}

TEST(PasswordTest, mixed_case_letter_in_others)
{
	ASSERT_FALSE(Password().has_mixed_case("-- +-+ A-"));
}

TEST(PasswordTest, mixed_case_letters_in_others)
{
	ASSERT_TRUE(Password().has_mixed_case("-t- +-+ A-"));
}

TEST(PasswordTest, complicated_one)
{
	ASSERT_FALSE(Password().has_mixed_case("!#!$SDFEF@#$@$EFEWFEWFEWDFQEWQEWDWQ$$!@002123---1291**"));
}

TEST(PasswordTest, complicated_two)
{
	ASSERT_TRUE(Password().has_mixed_case("!#!$cnj@#$@$pasopwaUisiuch$$!@002123---1291**"));
}