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