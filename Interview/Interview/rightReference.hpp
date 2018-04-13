//
//  rightReference.hpp
//  Interview
//
//  Created by Solon Chen on 21/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef rightReference_hpp
#define rightReference_hpp

#include <string>

#include "iTestable.h"

class RightReference : public iTestable {
public:
    RightReference(const std::string& str);
    RightReference(std::string&& str);


    RightReference(const RightReference& l);
    RightReference(RightReference&& l);

    RightReference & operator= (const std::string& str);
    RightReference & operator= (std::string&& str);

    RightReference & operator= (const RightReference& l);
    RightReference & operator= (RightReference&& l);

    virtual void test() const;

private:
    std::string m_str;
};

#endif /* leftReference_hpp */
