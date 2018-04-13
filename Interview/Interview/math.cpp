//
//  math.cpp
//  Interview
//
//  Created by Solon Chen on 21/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include "math.hpp"

#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_set>

double Math::mySqrt(int x) const {
    double left = 1.0;
    double right = x / 2.0 + 1.0;
    double mid = (left + right) / 2.0;
    while (true) {
        if (mid * mid > x)
            right = mid;
        else
            left = mid;

        double newMid = (left + right) / 2.0;
        if (std::abs(mid - newMid) <= 0.0001) {
            mid = newMid;
            break;
        }

        mid = newMid;
    }

    return mid;
}

double Math::newtonSqrt(int x) const {
    auto calcNext = [x](double i) {
        return (i + x / i) / 2.0;
    };

    auto next = calcNext(x / 2.0 + 1);
    while (true) {
        auto newNext = calcNext(next);

        if (next - newNext <= 0.01) {
            next = newNext;
            break;
        }

        next = newNext;
    }

    return next;
}

double Math::myPow(double x, int n) const {
    unsigned int absN = abs(n);
    bool isNegativeN = (n < 0);

    double pow = 1.0;
    double currentValue = 1.0;
    unsigned int bit = 1;
    unsigned int maxBit = (1 << (sizeof(unsigned int) * 8 - 1));
    while (bit <= absN) {
        bool needCalc = ((bit & absN) != 0);

        if (bit == 1)
            currentValue = x;
        else
            currentValue *= currentValue;

        if (needCalc) {
            double newPow = pow;
            if (isNegativeN)
                newPow /= currentValue;
            else
                newPow *= currentValue;

            if (abs(newPow - pow) < 0.00001)
                break;

            pow = newPow;
        }

        if (bit == maxBit)
            break;

        bit <<= 1;
    }

    return pow;
}

int Math::titleToNumber(const std::string& s) const {
    int colNum = 0;
    for (auto c : s) {
        colNum = colNum * 26 + (c - 'A') + 1;
    }

    return colNum;
}

int Math::trailingZeroes(int n) const {
    int res = 0;
    while (n) {
        res += n / 5;
        n /= 5;
    }
    return res;
}

bool Math::isHappy(int n) const {
    auto func = [](int n) -> int {
        int value = 0;
        while (n > 0) {
            auto unit = n % 10;
            value += unit * unit;

            n /= 10;
        }

        return value;
    };

    std::unordered_set<int> calculatedN;
    while (true) {
        if (n == 1)
            return true;

        if (calculatedN.find(n) != calculatedN.end())
            return false;
        calculatedN.insert(n);

        n = func(n);
    }

    return false;
}

int myDiv(int dividend, int divisor) {
    std::cout << dividend << "," << divisor << std::endl;
    if (dividend < divisor)
        return 0;
    else {
        auto up = myDiv(dividend >> 1, divisor);

        return (up << 1) + myDiv(dividend - divisor, divisor);
    }
}

int Math::divide(int dividend, int divisor) const {
    if (divisor == 0)
        return INT_MAX;

    bool negative = false;
    if (dividend > 0 && divisor < 0)
        negative = true;
    else if (dividend < 0 && divisor > 0)
        negative = true;

    if (dividend == INT_MIN)
        dividend = INT_MAX;
    else
        dividend = abs(dividend);

    if (divisor == INT_MIN)
        divisor = INT_MAX;
    else
        divisor = abs(divisor);

    auto result = myDiv(dividend, divisor);

    return negative ? -1 * result : result;

//    bool negative = false;
//    if (dividend > 0 && divisor < 0)
//        negative = true;
//    else if (dividend < 0 && divisor > 0)
//        negative = true;
//
//    dividend = abs(dividend);
//    divisor = abs(divisor);
//
//    auto func = [](int& dividend, int divisor) -> int {
//        if (dividend < divisor) {
//            dividend = 0;
//            return 0;
//        }
//
//        int level = 1;
//        int current = divisor;
//        for (int i = 0;; i++) {
//            auto next = divisor * level * 10;
//            if (next > dividend)
//                break;
//
//            current = next;
//            level *= 10;
//        }
//
//        int remaining = 0;
//        for (int i = 1; i < 10; i++) {
//            if (current * i <= dividend) {
//                remaining = dividend - current * i;
//            }
//            else {
//                dividend = remaining;
//                return level * (i - 1);
//            }
//        }
//
//        throw std::runtime_error("shouldn't be here");
//    };
//
//    int result = 0;
//    int remaining = dividend;
//    while (remaining > 0) {
//        result += func(remaining, divisor);
//    }
//
//    return negative ? -1 * result : result;
}

void Math::test() const {
//    std::vector<int> tests {10, 4, 10000, 3, 2, 1, 2147395599};
//    for (auto value : tests) {
//        std::cout << value << ": " << mySqrt(value) << std::endl;
//    }
//
//    std::cout << std::endl;
//
//    for (auto value : tests) {
//        std::cout << value << ": " << newtonSqrt(value) << std::endl;
//    }

//    std::cout << myPow(2.00000, 10) << std::endl;
//    std::cout << myPow(0.00001, 2147483647) << std::endl;
//    std::cout << myPow(-2.0, 2) << std::endl;
//    std::cout << myPow(2.0000, -2147483648) << std::endl;

//    std::cout << titleToNumber("AA") << std::endl;

//    std::cout << trailingZeroes(1808548329) << std::endl;

//    std::cout << std::boolalpha << isHappy(2) << std::endl;

//    std::cout << divide(8, 7) << std::endl;
//    std::cout << divide(320, 5) << std::endl;
//    std::cout << divide(-2147483648, -1) << std::endl;

    struct C
    {
        char b;
        int a;
        short c;
    };

    auto kk = sizeof(C);
    kk = sizeof(int);
    kk = sizeof(short);
    kk = sizeof(long);
    const char *str = "aa";
    kk = sizeof(str);
}

