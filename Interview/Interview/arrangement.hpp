//
//  arrangement.hpp
//  Interview
//
//  Created by Solon Chen on 12/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef arrangement_hpp
#define arrangement_hpp

#include <memory>
#include <vector>

class Arrangement {
public:
    typedef std::shared_ptr<Arrangement> ptr;

public:
    static Arrangement::ptr CreateAsPermutation(size_t n, size_t r);
    static Arrangement::ptr CreateAsCombination(size_t n, size_t r);

    static size_t Permutation(size_t n, size_t r);
    static size_t Combination(size_t n, size_t r);

    const std::vector<std::vector<size_t>> & Values() const;
    void Print() const;

private:
    Arrangement(const std::vector<std::vector<size_t>>& values);

    static std::vector<std::vector<size_t>>
    calculatePermutation(const std::vector<size_t>& digits,
                         size_t r);

    static std::vector<std::vector<size_t>>
    calculateCombination(size_t n_s,
                         size_t n,
                         size_t r);

    static size_t factorial(size_t n);

private:
    std::vector<std::vector<size_t>> m_values;
};

#endif /* arrangement_hpp */
