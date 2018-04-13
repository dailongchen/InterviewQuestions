//
//  findSubString.hpp
//  Interview
//
//  Created by Solon Chen on 20/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef findSubString_hpp
#define findSubString_hpp

#include <string>

#include "iTestable.h"

class FindSubString : public iTestable {
public:
    int sunday(const std::string& from,
               const std::string& match) const;

    virtual void test() const;
};

#endif /* findSubString_hpp */
