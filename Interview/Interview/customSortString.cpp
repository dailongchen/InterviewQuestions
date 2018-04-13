//
//  customSortString.cpp
//  Interview
//
//  Created by Solon Chen on 15/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include "customSortString.hpp"

CustomSortString::CustomSortString(const std::string& str) {
    memset(m_order, 0, sizeof(m_order));

    int i = 1;
    for (auto c : str) {
        m_order[c - 'a'] = i++;
    }
}

std::string CustomSortString::sort(const std::string& str) const {
    auto orderedStr = str;
    std::sort(orderedStr.begin(), orderedStr.end(), [&](auto a, auto b) -> bool {
        return m_order[a - 'a'] < m_order[b];
    });

    return orderedStr;
}
