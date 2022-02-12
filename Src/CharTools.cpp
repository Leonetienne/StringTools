#include "CharTools.h"
#include <algorithm>

bool CharTools::IsVowel(const char c, const std::string &vowels) {
    return std::any_of(
            vowels.cbegin(),
            vowels.cend(),
            [c](const char vowel) {
                return c == vowel;
            }
    );
}

bool CharTools::IsLetter(const char c) {
    // Re-implementing IsUpper and MakeLower to prevent stack-overflow by endless recursion
    const char lowercase_c = !(c & (1<<5)) ? (c | (1<<5)) : c;

    return (lowercase_c >= 'a') && (lowercase_c <= 'z');
}

bool CharTools::IsGeneric(const char c) {
    return (c == UPPERCASE) || (c == LOWERCASE);
}

bool CharTools::IsUpper(const char c) {
    if ((!IsLetter(c)) && (!IsGeneric(c)))
        return false;
    else
        return !(c & (1<<5));
}

char CharTools::MakeUpper(char c) {
    if ((!IsLetter(c)) && (!IsGeneric(c)))
        return c;
    else if (IsUpper(c))
        return c;
    else
        return c & ~(1<<5);
}

char CharTools::MakeLower(char c) {
    if ((!IsLetter(c)) && (!IsGeneric(c)))
        return c;
    else if (!IsUpper(c))
        return c;
    else
        return c | (1<<5);
}

char CharTools::GetSign(char c) {
    if (IsUpper(c))
        return UPPERCASE;
    else
        return LOWERCASE;
}

char CharTools::CopySign(char sign, char c) {
    if ((!IsLetter(c)) && (!IsGeneric(c)))
        return c;
    if (IsUpper(sign))
        return MakeUpper(c);
    else
        return MakeLower(c);
}
