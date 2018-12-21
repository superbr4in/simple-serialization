#pragma once
#include <sstream>

namespace bin
{
    /**
     * Serializes a generic value.
     */
    template <typename T>
    void serialize(std::ostream& stream, T const& value)
    {
        stream.write(reinterpret_cast<char const*>(&value), sizeof value);
    }

    /**
     * Deserializes a generic value.
     */
    template <typename T>
    void deserialize(std::istream& stream, T& value)
    {
        stream.read(reinterpret_cast<char*>(&value), sizeof value);
    }
}
