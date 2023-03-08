#pragma once

#include <iostream>
#include <string>

namespace lib::parser::json
{
class JsonParser
{
public:
    template <typename T>
    static void parse(const std::string& json, const std::string& key, T& value)
    {
        size_t index = json.find("\"" + key + "\""); // find the value corresponding to the given key in the Json string

        if (index == std::string::npos)
        {
            throw std::runtime_error("Key not found !");
        }

        index = json.find(':', index);

        if (index == std::string::npos)
        {
            throw std::runtime_error("Invalid Json format");
        }
        index++;

        while (index < json.length() and json[index] == ' ')
        {
            index++;
        }

        parseValue<T>(json, index, value); // parse the value based on its type
    }

private:
    template <typename T>
    static void parseValue(const std::string& json, size_t& index, T& value) // Recursive helper function to parse values to different types
    {
        static_assert(sizeof(T) == 0, "Invalid type");
    }

    // String specialization
    template<>
    static void parseValue<std::string>(const std::string& json, size_t& index, std::string& value)
    {
        size_t start = index;

        index = json.find('"', start + 1);

        while (index not_eq std::string::npos and json[index - 1] == '\\')
        {
            index = json.find('"', index + 1);
        }

        if(index == std::string::npos)
        {
            throw std::runtime_error("Invalid Json format");
        }

        value = json.substr(start + 1, index - start - 1);
        index++;           
    }

    // Integer Specialization
    template <>
    static void parseValue<int>(const std::string& json, size_t& index, int& value) 
    {
        // Find the end of the integer value
        size_t start = index;
        while (index < json.length() && std::isdigit(json[index]))
        {
            index++;
        }

        // Extract and convert the integer value
        value = std::stoi(json.substr(start, index - start));
    }

};   
} // namespace lib::parser::json
