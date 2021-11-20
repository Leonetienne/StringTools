#include "CppUnitTest.h"
#include "../StringTools/StringTools.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace _StringTools
{
	TEST_CLASS(_Replace_Char)
	{
	public:
		
		// Tests that replacing something in an empty string returns an empty string
		TEST_METHOD(EmptyString)
		{
			// Setup
			const std::string in = "";

			// Exercise
			const std::string out = StringTools::Replace(in, 'a', "Subst");

			// Verify
			Assert::AreEqual(out.c_str(), "");
			return;
		}

		// Tests that replacing a char to an empty string works
		TEST_METHOD(Single_ReplaceToEmpty)
		{
			// Setup
			const std::string in = "i";

			// Exercise
			const std::string out = StringTools::Replace(in, 'i', "");

			// Verify
			Assert::AreEqual(out.c_str(), "");
			return;
		}

		// Tests that replacing to a single char works
		TEST_METHOD(Single_ReplaceToSingleChar)
		{
			// Setup
			const std::string in = "a";

			// Exercise
			const std::string out = StringTools::Replace(in, 'a', "i");

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
			const std::string out = StringTools::Replace(in, 'a', 'i');

			// Verify
			Assert::AreEqual(out.c_str(), "Oilbinger");
			return;
		}

		// Tests that replacing the find to something longer works
		TEST_METHOD(Single_ReplaceToLonger)
		{
			// Setup
			const std::string in = "Littled";

			// Exercise
			const std::string out = StringTools::Replace(in, 'd', "binger");

			// Verify
			Assert::AreEqual(out.c_str(), "Littlebinger");
			return;
		}

		// Tests that replacing a char to an empty string works
		TEST_METHOD(Multiple_ReplaceToEmpty)
		{
			// Setup
			const std::string in = "dirty dogs dig dirt daringly";

			// Exercise
			const std::string out = StringTools::Replace(in, 'd', "");

			// Verify
			Assert::AreEqual(out.c_str(), "irty ogs ig irt aringly");
			return;
		}

		// Tests that replacing to a single char works
		TEST_METHOD(Multiple_ReplaceToSingleChar)
		{
			// Setup
			const std::string in = "Oilbanger, Bangerfanger, Lattle brattle oaly skattle.";

			// Exercise
			const std::string out = StringTools::Replace(in, 'a', "i");

			// Verify
			Assert::AreEqual(out.c_str(), "Oilbinger, Bingerfinger, Little brittle oily skittle.");
			return;
		}

		// Tests that replacing to a single char works, passing a char
		TEST_METHOD(Multiple_ReplaceToSingleChar_AsChar)
		{
			// Setup
			const std::string in = "Oilbanger, Bangerfanger, Lattle brattle oaly skattle.";

			// Exercise
			const std::string out = StringTools::Replace(in, 'a', 'i');

			// Verify
			Assert::AreEqual(out.c_str(), "Oilbinger, Bingerfinger, Little brittle oily skittle.");
			return;
		}

		// Tests that replacing the find to something longer works
		TEST_METHOD(Multiple_ReplaceToLonger)
		{
			// Setup
			const std::string in = "d d d d d d d d";

			// Exercise
			const std::string out = StringTools::Replace(in, 'd', "bla");

			// Verify
			Assert::AreEqual(out.c_str(), "bla bla bla bla bla bla bla bla");
			return;
		}

		// Tests that the replacer ignores chars put in by the replacer
		TEST_METHOD(ReplacerIgnoresReplaced)
		{
			// Setup
			const std::string in = "b b b b b b b b";

			// Exercise
			const std::string out = StringTools::Replace(in, 'b', "bla");

			// Verify
			Assert::AreEqual(out.c_str(), "bla bla bla bla bla bla bla bla");
			return;
		}

		// Tests that replacing succesive findings works
		TEST_METHOD(Replace_Successive)
		{
			// Setup
			const std::string in = "bbbbbbbb";

			// Exercise
			const std::string out = StringTools::Replace(in, 'b', "bla");

			// Verify
			Assert::AreEqual(out.c_str(), "blablablablablablablabla");
			return;
		}
	};
}
