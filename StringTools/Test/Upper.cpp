#include "CppUnitTest.h"
#include "../StringTools/StringTools.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace _StringTools
{
	TEST_CLASS(_Upper)
	{
	public:

		// Tests that uppering an empty string returns an empty string
		TEST_METHOD(EmptyString)
		{
			// Setup
			const std::string in = "";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("", out.c_str());
			return;
		}

		// Tests that uppering a string without any letters returns an itself
		TEST_METHOD(Symbols)
		{
			// Setup
			const std::string in = "66! _-\n*";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("66! _-\n*", out.c_str());
			return;
		}

		// Tests that uppering a string of uppercase letters returns itself
		TEST_METHOD(AlreadyUppered)
		{
			// Setup
			const std::string in = "UGHAREYOUSERIOUS";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("UGHAREYOUSERIOUS", out.c_str());
			return;
		}

		// Tests that uppering a string of lowercase letters returns the uppercase version
		TEST_METHOD(Lowercase)
		{
			// Setup
			const std::string in = "ughareyouserious";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("UGHAREYOUSERIOUS", out.c_str());
			return;
		}

		// Tests that uppering a string of uppercase, lowercase letters and symbols returns the uppercase version
		TEST_METHOD(Mixed)
		{
			// Setup
			const std::string in = "Ugh, Are You Serious?! DON'T do that!!!";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("UGH, ARE YOU SERIOUS?! DON'T DO THAT!!!", out.c_str());
			return;
		}

		// Tests that uppering already uppered umlautes returns itself
		TEST_METHOD(Umlautes_already_upper_a)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that uppering uppercase umlautes returns the upper umlautes
		TEST_METHOD(Umlautes_upper_a)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that uppering already uppered umlautes returns itself
		TEST_METHOD(Umlautes_already_upper_e)
		{
			// Setup
			const std::string in = "���";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("���", out.c_str());
		}

		// Tests that uppering uppercase umlautes returns the upper umlautes
		TEST_METHOD(Umlautes_upper_e)
		{
			// Setup
			const std::string in = "���";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("���", out.c_str());
		}

		// Tests that uppering already uppered umlautes returns itself
		TEST_METHOD(Umlautes_already_upper_u)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that uppering uppercase umlautes returns the upper umlautes
		TEST_METHOD(Umlautes_upper_u)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that uppering already uppered umlautes returns itself
		TEST_METHOD(Umlautes_already_upper_o)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that uppering uppercase umlautes returns the upper umlautes
		TEST_METHOD(Umlautes_upper_o)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that uppering a string of uppercase, lowercase letters and symbols returns the lowercase version, even with umlauts
		TEST_METHOD(Mixed_with_umlautes)
		{
			// Setup
			const std::string in = "�gh, �r� Y�� Seri��s?! D�N'T D� TH�T!!!";

			// Exercise
			const std::string out = StringTools::Upper(in);

			// Verify
			Assert::AreEqual("�GH, �R� Y�� SERI��S?! D�N'T D� TH�T!!!", out.c_str());
			return;
		}
	};
}
