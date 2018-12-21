#pragma once

#include <sstream>
#include <string>

namespace bin
{
    /*!
     *  Serializes a string.
     */
    inline void serialize(std::ostream& stream, std::string const& string)
    {
        stream.write(string.c_str(), string.size());
        stream.put('\0');
    }

    /*!
     *  Deserializes a string.
     */
    inline void deserialize(std::istream& stream, std::string& string)
    {
        std::string result;
        while (true)
        {
            auto const c = stream.get();
            if (c == '\0')
                break;

            result += c;
        }

        string = result;
    }
}
