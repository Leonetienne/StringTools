#include "CppUnitTest.h"
#include "../StringTools/StringTools.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace _StringTools
{
	TEST_CLASS(_Lower)
	{
	public:

		// Tests that lowering an empty string returns an empty string
		TEST_METHOD(EmptyString)
		{
			// Setup
			const std::string in = "";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("", out.c_str());
			return;
		}

		// Tests that lowering a string without any letters returns an itself
		TEST_METHOD(Symbols)
		{
			// Setup
			const std::string in = "66! _-\n*";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("66! _-\n*", out.c_str());
			return;
		}

		// Tests that lowering a string of lowercase letters returns itself
		TEST_METHOD(AlreadyLowered)
		{
			// Setup
			const std::string in = "ughareyouserious";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("ughareyouserious", out.c_str());
			return;
		}

		// Tests that lowering a string of uppercase letters returns the lowercase version
		TEST_METHOD(Uppercase)
		{
			// Setup
			const std::string in = "UGHAREYOUSERIOUS";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("ughareyouserious", out.c_str());
			return;
		}

		// Tests that lowering a string of uppercase, lowercase letters and symbols returns the lowercase version
		TEST_METHOD(Mixed)
		{
			// Setup
			const std::string in = "Ugh, Are You Serious?! DON'T DO THAT!!!";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("ugh, are you serious?! don't do that!!!", out.c_str());
			return;
		}

		// Tests that lowering already lowered umlautes returns itself
		TEST_METHOD(Umlautes_already_lower_a)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that lowering uppercase umlautes returns the lowered umlautes
		TEST_METHOD(Umlautes_upper_a)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that lowering already lowered umlautes returns itself
		TEST_METHOD(Umlautes_already_lower_e)
		{
			// Setup
			const std::string in = "���";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("���", out.c_str());
		}

		// Tests that lowering uppercase umlautes returns the lowered umlautes
		TEST_METHOD(Umlautes_upper_e)
		{
			// Setup
			const std::string in = "���";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("���", out.c_str());
		}

		// Tests that lowering already lowered umlautes returns itself
		TEST_METHOD(Umlautes_already_lower_u)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that lowering uppercase umlautes returns the lowered umlautes
		TEST_METHOD(Umlautes_upper_u)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that lowering already lowered umlautes returns itself
		TEST_METHOD(Umlautes_already_lower_o)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that lowering uppercase umlautes returns the lowered umlautes
		TEST_METHOD(Umlautes_upper_o)
		{
			// Setup
			const std::string in = "����";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("����", out.c_str());
		}

		// Tests that lowering a string of uppercase, lowercase letters and symbols returns the lowercase version, even with umlauts
		TEST_METHOD(Mixed_with_umlautes)
		{
			// Setup
			const std::string in = "�gh, �r� Y�� Seri��s?! D�N'T D� TH�T!!!";

			// Exercise
			const std::string out = StringTools::Lower(in);

			// Verify
			Assert::AreEqual("�gh, �r� y�� seri��s?! d�n't d� th�t!!!", out.c_str());
			return;
		}
	};
}
