#ifndef DATATYPE_H
#define DATATYPE_H
#include "datatype.h"
#include <iostream>
int main() {
    PlaceHolderDict dict;

    // Insert key-value pairs
    dict.insert("key1", "value1");
    dict.insert("key2", "value2");
    dict.insert("key3", "value3");

    // Retrieve and print values
    std::cout << "Value for key1: " << dict.get("key1") << std::endl;
    std::cout << "Value for key2: " << dict.get("key2") << std::endl;
    std::cout << "Value for key3: " << dict.get("key3") << std::endl;

    // Remove a key-value pair
    dict.remove("key2");
    std::cout << "Value for key2 after removal: " << dict.get("key2") << std::endl;

    return 0;
}

#endif // DATATYPE_H