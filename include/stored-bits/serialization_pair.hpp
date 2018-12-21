#pragma once

#include <sstream>

namespace bit
{
    template <typename T>
    void serialize(std::ostream& stream, T const& value);

    template <typename T>
    void deserialize(std::istream& stream, T& value);

    /*!
     *  Serializes a generic value pair.
     */
    template <typename T1, typename T2>
    void serialize(std::ostream& stream, std::pair<T1, T2> const& pair)
    {
        serialize(stream, pair.first);
        serialize(stream, pair.second);
    }

    /*!
     *  Deserializes a generic value pair.
     */
    template <typename T1, typename T2>
    void deserialize(std::istream& stream, std::pair<T1, T2>& pair)
    {
        deserialize(stream, pair.first);
        deserialize(stream, pair.second);
    }
}
