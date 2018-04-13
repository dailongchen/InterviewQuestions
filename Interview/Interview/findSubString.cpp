//
//  findSubString.cpp
//  Interview
//
//  Created by Solon Chen on 20/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include "findSubString.hpp"

#include <iostream>
#include <map>
#include <vector>

int FindSubString::sunday(const std::string& from,
                          const std::string& match) const {
    auto matchStringLength = match.size();
    if (matchStringLength == 0 || from.size() < matchStringLength)
        return -1;

    std::map<char, size_t> steps;
    for (auto i = 0; i < matchStringLength; i++) {
        steps.insert({match[i], matchStringLength - i});
    }

    for (auto i = 0; i <= from.size() - matchStringLength;) {
        bool found = true;
        for (auto j = 0; j < matchStringLength; j++) {
            if (from[i + j] != match[j]) {
                found = false;
                break;
            }
        }

        if (found)
            return i;

        if (i + matchStringLength >= from.size())
            return -1;

        auto iter = steps.find(from[i + matchStringLength]);
        if (iter == steps.end())
            i += matchStringLength + 1;
        else
            i += iter->second;
    }

    return -1;
}

void FindSubString::test() const {
    std::vector<std::pair<std::string, std::string> > tests {
        {"", "aaa"},
        {"aaa", ""},
        {"abccccdd", "cb"},
        {"abccdccdd", "cbcc"},
        {"abccdccdd", "cdcc"},
        {"12343322455", "432245"},
        {"1234", "2345"},
        {"1234", "1234"},
    };

    for (auto kv : tests) {
        std::cout << "\"" << kv.first << "\", \"" << kv.second << "\", " << sunday(kv.first, kv.second) << std::endl;
    }
}
