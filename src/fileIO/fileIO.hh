#pragma once
#include "../global.hh"


class SizedString {
public:
    SizedString(c_string str, u64 size);
    SizedString(c_string str);

    u64 getSize() { return size; }



    // first time using the 'friend' keyword in C++
    friend std::ostream& operator<<(std::ostream& os, const SizedString& ss);

private:
    c_string str;
    u64 size;

};
