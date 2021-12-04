#include "StringTools.h"
#include <sstream>

std::string StringTools::Replace(const std::string& str, const char find, const std::string& subst)
{
    std::stringstream ss;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != find)
            ss << str[i];
        else
            ss << subst;
    }

    return ss.str();
}

std::string StringTools::Replace(const std::string& str, const std::string& find, const std::string& subst)
{
    if (find.length() == 0)
        return str;

    std::stringstream ss;

    std::size_t posFound = 0;
    std::size_t lastFound = 0;

    while (posFound != std::string::npos)
    {
        lastFound = posFound;
        posFound = str.find(find, posFound);

        if (posFound != std::string::npos)
        {
            ss << str.substr(lastFound, posFound - lastFound) << subst;
            posFound += find.length();
        }
        else
        {
            ss << str.substr(lastFound, (str.length()) - lastFound);
        }
    }

    return ss.str();
}

std::string StringTools::Replace(const std::string& str, const char find, const char subst)
{
    std::stringstream ss;
    ss << subst;

    return Replace(str, find, ss.str());
}

std::string StringTools::Replace(const std::string& str, const std::string& find, const char subst)
{
    std::stringstream ss;
    ss << subst;

    return Replace(str, find, ss.str());
}

std::string StringTools::Lower(const std::string& str)
{
    std::stringstream ss;

    for (std::size_t i = 0; i < str.size(); i++)
    {
        const char c = str[i];

        // Quick-accept: regular letters
        if ((c >= 'A') && (c <= 'Z'))
            ss << (char)(c + 32);

        // Damned umlautes:
        else if (c == 'Ä') ss << 'ä';
        else if (c == 'Á') ss << 'á';
        else if (c == 'À') ss << 'à';
        else if (c == 'Â') ss << 'â';
        else if (c == 'É') ss << 'é';
        else if (c == 'È') ss << 'è';
        else if (c == 'Ê') ss << 'ê';
        else if (c == 'Ü') ss << 'ü';
        else if (c == 'Ú') ss << 'ú';
        else if (c == 'Ù') ss << 'ù';
        else if (c == 'Û') ss << 'û';
        else if (c == 'Ö') ss << 'ö';
        else if (c == 'Ó') ss << 'ó';
        else if (c == 'Ò') ss << 'ò';
        else if (c == 'Ô') ss << 'ô';

        // Else: keep the character as is
        else ss << c;
    }

    return ss.str();
}

std::string StringTools::Upper(const std::string& str)
{
    std::stringstream ss;

    for (std::size_t i = 0; i < str.size(); i++)
    {
        const char c = str[i];

        // Quick-accept: regular letters
        if ((c >= 'a') && (c <= 'z'))
            ss << (char)(c - 32);

        // Damned umlautes:
        else if (c == 'ä') ss << 'Ä';
        else if (c == 'á') ss << 'Á';
        else if (c == 'à') ss << 'À';
        else if (c == 'â') ss << 'Â';
        else if (c == 'é') ss << 'É';
        else if (c == 'è') ss << 'È';
        else if (c == 'ê') ss << 'Ê';
        else if (c == 'ü') ss << 'Ü';
        else if (c == 'ú') ss << 'Ú';
        else if (c == 'ù') ss << 'Ù';
        else if (c == 'û') ss << 'Û';
        else if (c == 'ö') ss << 'Ö';
        else if (c == 'ó') ss << 'Ó';
        else if (c == 'ò') ss << 'Ò';
        else if (c == 'ô') ss << 'Ô';

        // Else: keep the character as is
        else ss << c;
    }

    return ss.str();
}
