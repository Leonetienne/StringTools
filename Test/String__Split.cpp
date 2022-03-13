#include <StringTools.h>
#include "Catch2.h"

// Tests that splitting an empty string always returns {""}
TEST_CASE(__FILE__"/EmptyString", "[Strings][Split]")
{
  SECTION("Empty seperator") {
    // Setup
    const std::string in = "";
    const std::string sep = "";

    // Exercise
    const std::vector<std::string> out = StringTools::Split(in, sep);

    // Verify
    REQUIRE(out.size() == 1);
    REQUIRE(out[0] == "");
  }

  SECTION("Nonempty seperator") {
    // Setup
    const std::string in = "";
    const std::string sep = ",";

    // Exercise
    const std::vector<std::string> out = StringTools::Split(in, sep);

    // Verify
    REQUIRE(out.size() == 1);
    REQUIRE(out[0] == "");
  }


  return;
}

// Tests that splitting a string with an empty seperator returns all the chars
TEST_CASE(__FILE__"/EmptySeperator", "[Strings][Split]")
{
  // Setup
  const std::string in = "hello world";
  const std::string sep = "";
  const std::vector<std::string> expected = { "h", "e", "l", "l", "o", " ", "w", "o", "r", "l", "d" };

  // Exercise
  const std::vector<std::string> out = StringTools::Split(in, sep);

  // Verify
  REQUIRE(out == expected);

  return;
}

// Tests that splitting a string with a single-char seperator works
TEST_CASE(__FILE__"/SingleCharSeperator", "[Strings][Split]")
{
  // Setup
  const std::string in = "0,1,2,3,4,5,6,7,8,9";
  const std::string sep = ",";
  const std::vector<std::string> expected = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

  // Exercise
  const std::vector<std::string> out = StringTools::Split(in, sep);

  // Verify
  REQUIRE(out == expected);

  return;
}

// Tests that having seperators next to each other gets empty strings
TEST_CASE(__FILE__"/SingleCharSeperatorsNextToEachOther", "[Strings][Split]")
{
  // Setup
  const std::string in = "0,1,,3";
  const std::string sep = ",";
  const std::vector<std::string> expected = { "0", "1", "", "3" };

  // Exercise
  const std::vector<std::string> out = StringTools::Split(in, sep);

  // Verify
  REQUIRE(out == expected);

  return;
}

// Tests that having seperators at index 0 and -1 returns empty strings
TEST_CASE(__FILE__"/SingleCharSeperatorsAtExtremePoints", "[Strings][Split]")
{
  // Setup
  const std::string in = ",0,1,2,";
  const std::string sep = ",";
  const std::vector<std::string> expected = { "", "0", "1", "2", "" };

  // Exercise
  const std::vector<std::string> out = StringTools::Split(in, sep);

  // Verify
  REQUIRE(out == expected);

  return;
}


// Tests that splitting a string with a multi-char seperator works
TEST_CASE(__FILE__"/MultiCharSeperator", "[Strings][Split]")
{
  // Setup
  const std::string in = "0;;1;;2;;3;;4;;5;;6;;7;;8;;9";
  const std::string sep = ";;";
  const std::vector<std::string> expected = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

  // Exercise
  const std::vector<std::string> out = StringTools::Split(in, sep);

  // Verify
  REQUIRE(out == expected);

  return;
}

// Tests that having seperators next to each other gets empty strings
TEST_CASE(__FILE__"/MultiCharSeperatorsNextToEachOther", "[Strings][Split]")
{
  // Setup
  const std::string in = "0;;1;;;;3";
  const std::string sep = ";;";
  const std::vector<std::string> expected = { "0", "1", "", "3" };

  // Exercise
  const std::vector<std::string> out = StringTools::Split(in, sep);

  // Verify
  REQUIRE(out == expected);

  return;
}

// Tests that having seperators at index 0 and -1 returns empty strings
TEST_CASE(__FILE__"/MultiCharSeperatorsAtExtremePoints", "[Strings][Split]")
{
  // Setup
  const std::string in = ";;0;;1;;2;;";
  const std::string sep = ";;";
  const std::vector<std::string> expected = { "", "0", "1", "2", "" };

  // Exercise
  const std::vector<std::string> out = StringTools::Split(in, sep);

  // Verify
  REQUIRE(out == expected);

  return;
}

