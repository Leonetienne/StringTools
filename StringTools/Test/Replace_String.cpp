#include "CppUnitTest.h"
#include "../StringTools/StringTools.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace _StringTools
{
	TEST_CLASS(_Replace_String)
	{
	public:

		// Tests that replacing something in an empty string returns an empty string
		TEST_METHOD(EmptyString)
		{
			// Setup
			const std::string in = "";

			// Exercise
			const std::string out = StringTools::Replace(in, "burger", "Subst");

			// Verify
			Assert::AreEqual(out.c_str(), "");
			return;
		}

		// Tests that replacing a string to an empty string works
		TEST_METHOD(Single_ReplaceToEmpty)
		{
			// Setup
			const std::string in = "Squarepants";

			// Exercise
			const std::string out = StringTools::Replace(in, "Squarepants", "");

			// Verify
			Assert::AreEqual(out.c_str(), "");
			return;
		}

		// Tests that replacing to a single char works
		TEST_METHOD(Single_ReplaceToSingleChar)
		{
			// Setup
			const std::string in = "Squarepants";

			// Exercise
			const std::string out = StringTools::Replace(in, "Squarepants", "i");

			// Verify
			Assert::AreEqual(out.c_str(), "i");
			return;
		}

		// Tests that replacing to a single char works, passing a char
		TEST_METHOD(Single_ReplaceToSingleChar_AsChar)
		{
			// Setup
			const std::string in = "Oilbanger";

			// Exercise
			const std::string out = StringTools::Replace(in, "Oilbanger", 'i');

			// Verify
			Assert::AreEqual(out.c_str(), "i");
			return;
		}

		// Tests that replacing the find to something longer works
		TEST_METHOD(Single_ReplaceToLonger)
		{
			// Setup
			const std::string in = "LittleDong";

			// Exercise
			const std::string out = StringTools::Replace(in, "Dong", "Binger");

			// Verify
			Assert::AreEqual(out.c_str(), "LittleBinger");
			return;
		}

		// Tests that replacing a string to an empty string works
		TEST_METHOD(Multiple_ReplaceToEmpty)
		{
			// Setup
			const std::string in = "The fucking dogs are fucking eating the fucking chicken.";

			// Exercise
			const std::string out = StringTools::Replace(in, "fucking ", "");

			// Verify
			Assert::AreEqual(out.c_str(), "The dogs are eating the chicken.");
			return;
		}

		// Tests that replacing to a single char works
		TEST_METHOD(Multiple_ReplaceToSingleChar)
		{
			// Setup
			const std::string in = "Oilbsmearynger, Bsmearyngerfsmearynger, Lsmearyttle brsmearyttle osmearyly sksmearyttle.";

			// Exercise
			const std::string out = StringTools::Replace(in, "smeary", "i");

			// Verify
			Assert::AreEqual(out.c_str(), "Oilbinger, Bingerfinger, Little brittle oily skittle.");
			return;
		}

		// Tests that replacing to a single char works, passing a char
		TEST_METHOD(Multiple_ReplaceToSingleChar_AsChar)
		{
			// Setup
			const std::string in = "Oilbsmearynger, Bsmearyngerfsmearynger, Lsmearyttle brsmearyttle osmearyly sksmearyttle.";

			// Exercise
			const std::string out = StringTools::Replace(in, "smeary", 'i');

			// Verify
			Assert::AreEqual(out.c_str(), "Oilbinger, Bingerfinger, Little brittle oily skittle.");
			return;
		}

		// Tests that replacing the find to something longer works
		TEST_METHOD(Multiple_ReplaceToLonger)
		{
			// Setup
			const std::string in = "honk honk honk honk honk honk honk honk";

			// Exercise
			const std::string out = StringTools::Replace(in, "honk", "hallery");

			// Verify
			Assert::AreEqual(out.c_str(), "hallery hallery hallery hallery hallery hallery hallery hallery");
			return;
		}

		// Tests that the replacer ignores chars put in by the replacer
		TEST_METHOD(ReplacerIgnoresReplaced)
		{
			// Setup
			const std::string in = "honk honk honk honk honk honk honk honk";

			// Exercise
			const std::string out = StringTools::Replace(in, "honk", "honka");

			// Verify
			Assert::AreEqual(out.c_str(), "honka honka honka honka honka honka honka honka");
			return;
		}

		// Tests that replacing succesive findings works
		TEST_METHOD(Replace_Successive)
		{
			// Setup
			const std::string in = "honkhonkhonkhonkhonkhonkhonkhonk";

			// Exercise
			const std::string out = StringTools::Replace(in, "honk", "hallery");

			// Verify
			Assert::AreEqual(out.c_str(), "halleryhalleryhalleryhalleryhalleryhalleryhalleryhallery");
			return;
		}

		// Tests that if find.length() == 0, it returns just the input
		TEST_METHOD(Find_Length0_Returns_Input)
		{
			// Setup
			const std::string in = "Littled";

			// Exercise
			const std::string out = StringTools::Replace(in, "", "binger");

				// Verify
				Assert::AreEqual(out.c_str(), "Littled");
			return;
		}
	};
}
