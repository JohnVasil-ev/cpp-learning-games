#pragma once

#include <iostream>

namespace learning {

void print_title(std::string title = "")
{
    std::string border(title.size() + 2, '-');
    title.push_back(' ');
    printf("= === === === === %s === === === === =\n", border.c_str());
    printf("= Welcome to the %sgame! Good luck ;) =\n", title.c_str());
    printf("= === === === === %s === === === === =\n\n", border.c_str());
}

} // end namespace learning
