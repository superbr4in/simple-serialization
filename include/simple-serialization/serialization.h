#pragma once

#include <optional>
#include <ostream>
#include <string>

/**
 * Serializes a string.
 */
void serialize(std::ostream& stream, std::string const& string);
/**
 * Deserializes a string.
 */
void deserialize(std::istream& stream, std::string& string);

/**
 * Serializes a generic value.
 */
template <typename T>
void serialize(std::ostream& stream, T const& value);
/**
 * Deserializes a generic value.
 */
template <typename T>
void deserialize(std::istream& stream, T& value);

/**
 * Serializes a generic optional value.
 */
template <typename T>
void serialize(std::ostream& stream, std::optional<T> const& optional);
/**
 * Deserializes a generic optional value.
 */
template <typename T>
void deserialize(std::istream& stream, std::optional<T>& optional);

/**
 * Serializes a generic vector.
 */
template <typename T>
void serialize(std::ostream& stream, std::vector<T> const& vector);
/**
 * Deserializes a generic vector.
 */
template <typename T>
void deserialize(std::istream& stream, std::vector<T>& vector);

/**
 * Serializes a generic value pair.
 */
template <typename T1, typename T2>
void serialize(std::ostream& stream, std::pair<T1, T2> const& pair);
/**
 * Deserializes a generic value pair.
 */
template <typename T1, typename T2>
void deserialize(std::istream& stream, std::pair<T1, T2>& pair);

/**
 * Serializes a generic map.
 */
template <typename T1, typename T2>
void serialize(std::ostream& stream, std::map<T1, T2> const& map);
/**
 * Deserializes a generic map.
 */
template <typename T1, typename T2>
void deserialize(std::istream& stream, std::map<T1, T2>& map);

inline void serialize(std::ostream& stream, std::string const& string)
{
    stream.write(string.c_str(), string.size());
    stream.put('\0');
}
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

template <typename T>
void serialize(std::ostream& stream, T const& value)
{
    stream.write(reinterpret_cast<char const*>(&value), sizeof value);
}
template <typename T>
void deserialize(std::istream& stream, T& value)
{
    stream.read(reinterpret_cast<char*>(&value), sizeof value);
}

template <typename T>
void serialize(std::ostream& stream, std::optional<T> const& optional)
{
    auto const has_value = optional.has_value();
    
    stream.put(has_value);
    if (has_value)
        serialize(stream, *optional);
}
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

template <typename T>
void serialize(std::ostream& stream, std::vector<T> const& vector)
{
    serialize(stream, static_cast<uint64_t>(vector.size()));
    for (auto const& elem : vector)
        serialize(stream, elem);
}
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

template <typename T1, typename T2>
void serialize(std::ostream& stream, std::pair<T1, T2> const& pair)
{
    serialize(stream, pair.first);
    serialize(stream, pair.second);
}
template <typename T1, typename T2>
void deserialize(std::istream& stream, std::pair<T1, T2>& pair)
{
    deserialize(stream, pair.first);
    deserialize(stream, pair.second);
}

template <typename T1, typename T2>
void serialize(std::ostream& stream, std::map<T1, T2> const& map)
{
    serialize(stream, static_cast<uint64_t>(map.size()));
    for (auto const& elem : map)
        serialize(stream, elem);
}
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
