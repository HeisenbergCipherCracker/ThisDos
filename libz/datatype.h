/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
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

PlaceHolderDict conf;
PlaceHolderDict kb;
