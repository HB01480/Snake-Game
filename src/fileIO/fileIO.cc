#include "../global.hh"

#include "fileIO.hh"


SizedString::SizedString(c_string str, u64 size)
: str(str), size(size)
{}
SizedString::SizedString(c_string str)
: str(str), size(strlen(str))
{}

std::ostream& operator<<(std::ostream& os, const SizedString& ss)
{
    os << ss.str;
    return os;
}
