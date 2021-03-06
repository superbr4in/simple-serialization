#pragma once

#include <optional>
#include <sstream>

namespace bit
{
    template <typename T>
    void serialize(std::ostream& stream, T const& value);

    template <typename T>
    void deserialize(std::istream& stream, T& value);

    /*!
     *  Serializes a generic optional value.
     */
    template <typename T>
    void serialize(std::ostream& stream, std::optional<T> const& optional)
    {
        auto const has_value = optional.has_value();

        stream.put(has_value);
        if (has_value)
            serialize(stream, *optional);
    }

    /*!
     *  Deserializes a generic optional value.
     */
    template <typename T>
    void deserialize(std::istream& stream, std::optional<T>& optional)
    {
        if (stream.get())
        {
            T value;
            deserialize(stream, value);

            optional = value;
        }
        else optional = std::nullopt;
    }
}
