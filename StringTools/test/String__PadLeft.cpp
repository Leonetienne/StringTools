#include <StringTools/StringTools.h>
#include "Catch2.h"

// Tests that padding to a length shorter adds no padding 
TEST_CASE(__FILE__"/PadToShorterLength", "[Strings][PadLeft]")
{
    // Setup
    const std::string in = "hello";

    // Exercise
    const std::string out = StringTools::PadLeft(in, '0', 3);

    // Verify
    REQUIRE(out == "hello");
    return;
}

// Tests that padding to a length equal adds no padding 
TEST_CASE(__FILE__"/PadToEqualLength", "[Strings][PadLeft]")
{
  // Setup
  const std::string in = "hello";

  // Exercise
  const std::string out = StringTools::PadLeft(in, '0', 5);

  // Verify
  REQUIRE(out == "hello");
  return;
}

// Tests that adding padding works
TEST_CASE(__FILE__"/Padding", "[Strings][PadLeft]")
{
    // Setup
    const std::string in = "hello";

    // Exercise
    const std::string out = StringTools::PadLeft(in, '0', 7);

    // Verify
    REQUIRE(out == "00hello");
    return;
}
