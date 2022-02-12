#ifndef STRINGTOOLS_CHARTOOLS_H
#define STRINGTOOLS_CHARTOOLS_H

#include <string>

/* Handy utensils to manipulate characters */

class CharTools {
public:
    //! Checks whether or not `c` is a vowel. You can define custom vowel characters.
    static bool IsVowel(const char c, const std::string& vowels = "euioay");

    //! Returns whether or not `c` is a letter.
    static bool IsLetter(const char c);

    //! Returns whether or not `c` is a generic character (that contains JUST the sign)
    static bool IsGeneric(const char c);

    //! Checks whether or not `c` is an uppercase character.
    static bool IsUpper(const char c);

    //! Will return `c` as an uppercase character.
    static char MakeUpper(char c);

    //! Will return `c` as a lowercase character.
    static char MakeLower(char c);

    //! Will return an empty character with the same sign/capitalization as `c`.
    static char GetSign(char c);

    //! Will return `c` with the same capitalization as `sign`.
    static char CopySign(char sign, char c);

    //! Generic uppercase character.
    static constexpr char UPPERCASE = 0;

    //! Generic lowercase character.
    static constexpr char LOWERCASE = (1<<5);
};

#endif //STRINGTOOLS_CHARTOOLS_H
