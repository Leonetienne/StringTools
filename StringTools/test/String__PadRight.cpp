#include <StringTools/StringTools.h>
#include "Catch2.h"

using namespace Leonetienne::StringTools;


// Tests that padding to a length shorter adds no padding 
TEST_CASE(__FILE__"/PadToShorterLength", "[Strings][PadRight]")
{
    // Setup
    const std::string in = "hello";

    // Exercise
    const std::string out = StringTools::PadRight(in, '0', 3);

    // Verify
    REQUIRE(out == "hello");
    return;
}

// Tests that padding to a length equal adds no padding 
TEST_CASE(__FILE__"/PadToEqualLength", "[Strings][PadRight]")
{
  // Setup
  const std::string in = "hello";

  // Exercise
  const std::string out = StringTools::PadRight(in, '0', 5);

  // Verify
  REQUIRE(out == "hello");
  return;
}

// Tests that adding padding works
TEST_CASE(__FILE__"/Padding", "[Strings][PadRight]")
{
    // Setup
    const std::string in = "hello";

    // Exercise
    const std::string out = StringTools::PadRight(in, '0', 7);

    // Verify
    REQUIRE(out == "hello00");
    return;
}
