#pragma once

#include <optional>
#include <ostream>
#include <string>

void serialize(std::ostream& stream, std::string const& value);

template <typename T>
void serialize(std::ostream& stream, T const& value);
template <typename T>
void serialize(std::ostream& stream, std::optional<T> optional);

template <typename T1, typename T2>
void serialize(std::ostream& stream, std::pair<T1, T2> const& pair);

template <typename Container>
void serialize_container(std::ostream& stream, Container container);

inline void serialize(std::ostream& stream, std::string const& value)
{
    stream.write(value.c_str(), value.size());
    stream.put('\0');
}

template <typename T>
void serialize(std::ostream& stream, T const& value)
{
    stream.write(reinterpret_cast<char const*>(&value), sizeof value);
}
template <typename T>
void serialize(std::ostream& stream, std::optional<T> optional)
{
    auto const has_value = optional.has_value();
    
    stream.put(has_value);
    if (has_value)
        serialize(stream, *optional);
}

template <typename T1, typename T2>
void serialize(std::ostream& stream, std::pair<T1, T2> const& pair)
{
    serialize(stream, pair.first);
    serialize(stream, pair.second);
}

template <typename Container>
void serialize_container(std::ostream& stream, Container container)
{
    serialize(stream, static_cast<uint64_t>(container.size()));
    for (auto const& elem : container)
        serialize(stream, elem);
}
