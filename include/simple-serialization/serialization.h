#pragma once

#include <map>
#include <optional>
#include <string>
#include <vector>

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

#include "serialization.cpp"
