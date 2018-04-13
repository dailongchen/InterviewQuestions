//
//  math.hpp
//  Interview
//
//  Created by Solon Chen on 21/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef math_hpp
#define math_hpp

#include "iTestable.h"

#include <string>

class Math : public iTestable {
public:
    double mySqrt(int x) const;
    double newtonSqrt(int x) const;
    double myPow(double x, int n) const;
    int titleToNumber(const std::string& s) const;
    int trailingZeroes(int n) const;
    bool isHappy(int n) const;
    int divide(int dividend, int divisor) const;

    virtual void test() const;
};

#endif /* math_hpp */
