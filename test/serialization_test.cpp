#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "simple-serialization/serialization.h"

static std::vector<uint8_t> extract_buffer(std::ostringstream const& sstream)
{
    auto const str = sstream.str();

    auto const* ptr = reinterpret_cast<uint8_t const*>(str.c_str());
    auto const size = str.size();

    return std::vector<uint8_t>(ptr, ptr + size);
}

static void print_buffer(std::vector<uint8_t> const& buffer)
{
    std::cout << "| ";

    for (char const byte : buffer)
    {
        if (byte >= 0x21 && byte <= 0x7E)
            std::cout << byte;
        else std::cout << " ";

        std::cout << "  ";
    }

    std::cout << "|" << std::endl << "| ";

    for (auto byte : buffer)
        std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << +byte << " ";

    std::cout << "| = " << std::dec << buffer.size() << " bytes" << std::endl;
}

namespace general
{
    TEST_CASE("test1")
    {
        std::vector<std::optional<unsigned>> const in = { std::nullopt, 5, 132847, std::nullopt, 0, 42 };
        std::vector<uint8_t> const out = { 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 0x00, 0x00, 0x00, 0x01, 0xEF, 0x06, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x2A, 0x00, 0x00, 0x00 };

        std::ostringstream sstream;
        serialize_container(sstream, in);

        auto const buffer = extract_buffer(sstream);

        print_buffer(buffer);
        REQUIRE(buffer == out);
    }

    TEST_CASE("test2")
    {
        std::string const in = "this is a test string!@#$%^&*()_+";
        std::vector<uint8_t> const out = { 0x74, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x74, 0x65, 0x73, 0x74, 0x20, 0x73, 0x74, 0x72, 0x69, 0x6E, 0x67, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5E, 0x26, 0x2A, 0x28, 0x29, 0x5F, 0x2B, 0x00 };

        std::ostringstream sstream;
        serialize(sstream, in);

        auto const buffer = extract_buffer(sstream);

        print_buffer(buffer);
        REQUIRE(buffer == out);
    }

    TEST_CASE("test3")
    {
        std::map<int16_t, bool> const in = { { 24, true }, { 16, false }, { -4, false } };
        std::vector<uint8_t> const out = { 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x10, 0x00, 0x00, 0x18, 0x00, 0x01 };

        std::ostringstream sstream;
        serialize_container(sstream, in);

        auto const buffer = extract_buffer(sstream);

        print_buffer(buffer);
        REQUIRE(buffer == out);
    }
}
