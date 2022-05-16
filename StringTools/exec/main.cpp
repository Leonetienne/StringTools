#include <iostream>
#include <StringTools/StringTools.h>

using namespace Leonetienne::StringTools;

int main()
{
    std::vector<std::string> foo =
      StringTools::Split(",,Hello,,lol,,test,,", ",,");

    for (const auto& it : foo)
      std::cout << "'" << it << "'" << std::endl;

    return 0;
}
