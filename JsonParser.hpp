#pragma once

#include <string>

namespace lib::parser::json
{
class JsonParser
{
public:
    template <class T>
    static void parse(const std::string& json, const std::string& key, T& value)
    {
        size_t position = json.find("\"" + key + "\""); // find the value corresponding to the given key in the Json string

        if (position == std::string::npos)
        {
            throw std::runtime_error("Key not found !");
        }

        position = json.find(':', position);

        if (position == std::string::npos)
        {
            throw std::runtime_error("Invalid Json format");
        }
        position++;

        while (position < json.length() and json[position] == ' ')
        {
            position++;
        }

        parseValue<>(json, position, value); // parse the value based on its type
    }

private:
    template<typename T>
    static void parseValue(const std::string& json, std::size_t& position, T& value) // Recursive helper function to parse values to different types
    {
        static_assert(sizeof(T) == 0, "Invalid type");
    }

    // String specialization
    template<>
    static void parseValue<std::string>(const std::string& json, std::size_t& position, std::string& value)
    {
        
    }

};   
} // namespace lib::parser::json
