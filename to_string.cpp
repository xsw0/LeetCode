#include "to_string.h"

std::string TO_STRING::emptyString;

size_t TO_STRING::CONSOLE_WIDTH = 80;

std::string TO_STRING::stringPrefix = "\"";
std::string TO_STRING::stringSuffix = "\"";
std::string TO_STRING::stringIndent = "    ";

std::string TO_STRING::arrayPrefix = "{";
std::string TO_STRING::arraySuffix = "}";
std::string TO_STRING::arraySeparator = ",";
std::string TO_STRING::arraySpace = " ";
std::string TO_STRING::arrayNewline = "\n";
std::string TO_STRING::arrayIndent = "    ";

#define DEFINE(container)                              \
    template <>                                        \
    std::string TO_STRING::prefix<container> = "{";    \
    template <>                                        \
    std::string TO_STRING::suffix<container> = "}";    \
    template <>                                        \
    std::string TO_STRING::separator<container> = ","; \
    template <>                                        \
    std::string TO_STRING::space<container> = " ";     \
    template <>                                        \
    std::string TO_STRING::newline<container> = "\n";  \
    template <>                                        \
    std::string TO_STRING::indent<container> = "    ";

DEFINE(std::vector);
DEFINE(std::deque);
DEFINE(std::forward_list);
DEFINE(std::list);
DEFINE(std::set);
DEFINE(std::map);
DEFINE(std::multiset);
DEFINE(std::multimap);
DEFINE(std::unordered_set);
DEFINE(std::unordered_map);
DEFINE(std::unordered_multiset);
DEFINE(std::unordered_multimap);
DEFINE(std::stack);
DEFINE(std::queue);

DEFINE(std::pair);
#undef DEFINE
