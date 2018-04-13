//
//  customSortString.hpp
//  Interview
//
//  Created by Solon Chen on 15/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef customSortString_hpp
#define customSortString_hpp

#include <string>

class CustomSortString {
public:
    CustomSortString(const std::string& str);

    std::string sort(const std::string& str) const;

private:
    int m_order[26];
};

#endif /* customSortString_hpp */
