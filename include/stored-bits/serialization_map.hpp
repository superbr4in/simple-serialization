#pragma once

#include <map>
#include <sstream>

namespace bit
{
    template <typename T>
    void serialize(std::ostream& stream, T const& value);

    template <typename T1, typename T2>
    void serialize(std::ostream& stream, std::pair<T1, T2> const& pair);

    template <typename T>
    void deserialize(std::istream& stream, T& value);

    template <typename T1, typename T2>
    void deserialize(std::istream& stream, std::pair<T1, T2>& pair);

    /*!
     *  Serializes a generic map.
     */
    template <typename T1, typename T2>
    void serialize(std::ostream& stream, std::map<T1, T2> const& map)
    {
        serialize(stream, static_cast<uint64_t>(map.size()));
        for (auto const& elem : map)
            serialize(stream, elem);
    }

    /*!
     *  Deserializes a generic map.
     */
    template <typename T1, typename T2>
    void deserialize(std::istream& stream, std::map<T1, T2>& map)
    {
        uint64_t size;
        deserialize(stream, size);

        for (uint64_t i = 0; i < size; ++i)
        {
            std::pair<T1, T2> elem;
            deserialize(stream, elem);

            map.insert(elem);
        }
    }
}
