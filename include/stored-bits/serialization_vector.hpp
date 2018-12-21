#pragma once

#include <sstream>
#include <vector>

namespace bit
{
    template <typename T>
    void serialize(std::ostream& stream, T const& value);

    /*!
     *  Serializes a generic vector.
     */
    template <typename T>
    void serialize(std::ostream& stream, std::vector<T> const& vector)
    {
        serialize(stream, static_cast<uint64_t>(vector.size()));
        for (auto const& elem : vector)
            serialize(stream, elem);
    }

    template <typename T>
    void deserialize(std::istream& stream, T& value);

    /*!
     *  Deserializes a generic vector.
     */
    template <typename T>
    void deserialize(std::istream& stream, std::vector<T>& vector)
    {
        uint64_t size;
        deserialize(stream, size);

        for (uint64_t i = 0; i < size; ++i)
        {
            T elem;
            deserialize(stream, elem);

            vector.push_back(elem);
        }
    }
}
