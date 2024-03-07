#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class PlaceHolderDict {
private:
    std::unordered_map<std::string, std::string> data;

public:
    // Insert a key-value pair into the PlaceHolderDict
    void insert(const std::string& key, const std::string& value) {
        data[key] = value;
    }

    // Retrieve a value given a key from the PlaceHolderDict
    std::string get(const std::string& key) const {
        if (data.find(key) != data.end()) {
            return data.at(key);
        } else {
            return "";
        }
    }

    // Delete a key-value pair given a key from the PlaceHolderDict
    void remove(const std::string& key) {
        if (data.find(key) != data.end()) {
            data.erase(key);
        }
    }
};

// int main() {
//     PlaceHolderDict dict;

//     // Insert key-value pairs
//     dict.insert("key1", "value1");
//     dict.insert("key2", "value2");
//     dict.insert("key3", "value3");

//     // Retrieve and print values
//     std::cout << "Value for key1: " << dict.get("key1") << std::endl;
//     std::cout << "Value for key2: " << dict.get("key2") << std::endl;
//     std::cout << "Value for key3: " << dict.get("key3") << std::endl;

//     // Remove a key-value pair
//     dict.remove("key2");
//     std::cout << "Value for key2 after removal: " << dict.get("key2") << std::endl;

//     return 0;
// }