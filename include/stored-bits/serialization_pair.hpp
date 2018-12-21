#pragma once
#include <sstream>

#include <utility>

namespace bin
{
    template <typename T>
    void serialize(std::ostream& stream, T const& value);

    /**
     * Serializes a generic value pair.
     */
    template <typename T1, typename T2>
    void serialize(std::ostream& stream, std::pair<T1, T2> const& pair)
    {
        serialize(stream, pair.first);
        serialize(stream, pair.second);
    }

    template <typename T>
    void deserialize(std::istream& stream, T& value);

    /**
     * Deserializes a generic value pair.
     */
    template <typename T1, typename T2>
    void deserialize(std::istream& stream, std::pair<T1, T2>& pair)
    {
        deserialize(stream, pair.first);
        deserialize(stream, pair.second);
    }
}
