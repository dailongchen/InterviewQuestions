//
//  arrangement.cpp
//  Interview
//
//  Created by Solon Chen on 12/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include "arrangement.hpp"

#include <iostream>
#include <stdexcept>

Arrangement::Arrangement(const std::vector<std::vector<size_t>>& values)
: m_values(values){
}

Arrangement::ptr Arrangement::CreateAsPermutation(size_t n, size_t r) {
    if (r > n)
        throw std::invalid_argument("r cannot larger than n");

    std::vector<std::vector<size_t>> values;
    if (r > 0) {
        std::vector<size_t> digits;
        for (auto i = 0; i < n; i++) {
            digits.push_back(i);
        }

        values = calculatePermutation(digits, r);
    }

    return Arrangement::ptr(new Arrangement(values));
}

Arrangement::ptr Arrangement::CreateAsCombination(size_t n, size_t r) {
    if (r > n)
        throw std::invalid_argument("r cannot larger than n");

    std::vector<std::vector<size_t>> values;
    if (r > 0) {
        values = calculateCombination(0, n, r);
    }

    return Arrangement::ptr(new Arrangement(values));
}

size_t Arrangement::Permutation(size_t n, size_t r) {
    if (r > n)
        throw std::invalid_argument("r cannot larger than n");

    return factorial(n) / factorial(n - r);
}

size_t Arrangement::Combination(size_t n, size_t r) {
    if (r > n)
        throw std::invalid_argument("r cannot larger than n");

    return Permutation(n, r) / factorial(r);
}

const std::vector<std::vector<size_t>> & Arrangement::Values() const {
    return m_values;
}

void Arrangement::Print() const {
    for (auto& oneRow : m_values) {
        for (auto val : oneRow) {
            std::cout << val << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "total: " << m_values.size() << std::endl;
}

std::vector<std::vector<size_t>> Arrangement::calculatePermutation(const std::vector<size_t>& digits,
                                                                   size_t r) {
    std::vector<std::vector<size_t>> results;

    if (r == 1) {
        for (auto num : digits) {
            results.push_back({num});
        }
        return results;
    }

    for (int i = 0; i < digits.size(); i++) {
        auto newDigits = digits;
        newDigits.erase(newDigits.begin() + i);

        auto subSequence = calculatePermutation(newDigits, r - 1);
        for (auto& array : subSequence) {
            auto newArray = array;
            newArray.insert(newArray.begin(), digits[i]);
            results.push_back(newArray);
        }
    }

    return results;
}


std::vector<std::vector<size_t>> Arrangement::calculateCombination(size_t n_s,
                                                                   size_t n,
                                                                   size_t r) {
    std::vector<std::vector<size_t>> results;
    
    if (r == 1) {
        for (auto i = n_s; i < n; i++) {
            results.push_back({i});
        }
    }
    else {
        for (auto i = n_s; i <= n - r; i++) {
            auto subSequence = calculateCombination(i + 1, n, r - 1);
            for (auto& array : subSequence) {
                auto newArray = array;
                newArray.insert(newArray.begin(), i);
                results.push_back(newArray);
            }
        }
    }

    return results;
}

size_t Arrangement::factorial(size_t n) {
    size_t result = 1;
    for (auto i = n; i > 1; i--) {
        result *= i;
    }

    return result;
}
