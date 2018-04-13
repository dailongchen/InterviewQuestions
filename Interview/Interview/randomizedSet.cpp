//
//  randomizedSet.cpp
//  Interview
//
//  Created by Solon Chen on 12/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include "randomizedSet.hpp"

#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>

RandomizedSet::BinaryTreeNode::BinaryTreeNode(int val)
: m_val(val) {
}

bool RandomizedSet::BinaryTreeNode::insert(int val) {
    if (m_val > val) {
        if (m_left != nullptr)
            return m_left->insert(val);

        m_left = std::make_shared<BinaryTreeNode>(val);
        return true;
    }
    if (m_val < val) {
        if (m_right != nullptr)
            return m_right->insert(val);

        m_right = std::make_shared<BinaryTreeNode>(val);
        return true;
    }

    return false;
}

RandomizedSet::BinaryTreeNode::RemoveNodeResult RandomizedSet::BinaryTreeNode::remove(int val) {
    if (m_val > val) {
        if (m_left != nullptr) {
            auto result = m_left->remove(val);
            if (result.success) {
                m_left = result.remainingRoot;
                return {shared_from_this(), true};
            }
        }

        return {nullptr, false};
    }
    if (m_val < val) {
        if (m_right != nullptr) {
            auto result = m_right->remove(val);
            if (result.success) {
                m_right = result.remainingRoot;
                return {shared_from_this(), true};
            }
        }

        return {nullptr, false};
    }

    auto newRoot = m_right;
    if (newRoot == nullptr)
        return {m_left, true};

    if (m_left != nullptr) {
        auto current = newRoot;
        while (true) {
            if (current->m_left == nullptr)
                break;
        }
        current->m_left = m_left;
    }

    return {newRoot, true};
}

bool RandomizedSet::BinaryTreeNode::get(int& n, int& val) const {
    n--;
    if (n == 0) {
        val = m_val;
        return true;
    }

    if (m_left != nullptr) {
        if (m_left->get(n, val))
            return true;
    }
    if (m_right != nullptr) {
        if (m_right->get(n, val))
            return true;
    }

    return false;
}

std::string RandomizedSet::BinaryTreeNode::toString() const {
    std::ostringstream ss;
    ss << m_val << ",";

    if (m_left != nullptr) {
        ss << m_left->toString();
    }
    if (m_right != nullptr) {
        ss << m_right->toString();
    }

    return ss.str();
}

RandomizedSet::RandomizedSet()
: m_count(0) {
}

bool RandomizedSet::insert(int val) {
    bool success = false;
    if (m_root)
        success = m_root->insert(val);
    else {
        m_root = std::make_shared<BinaryTreeNode>(val);
        success = true;
    }

    if (success)
        m_count++;

    return success;
}

bool RandomizedSet::remove(int val) {
    if (m_root) {
        auto result = m_root->remove(val);
        if (result.success) {
            m_root = result.remainingRoot;
            m_count--;
            return true;
        }
    }

    return false;
}

int RandomizedSet::getRandom() const {
    if (m_root == nullptr)
        throw std::out_of_range("cannot get random from empty set");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, m_count);

    int index = dis(gen);
    int val;
    if (!m_root->get(index, val))
        throw std::out_of_range("failed to get random from set");

    return val;
}

std::string RandomizedSet::toString() const {
    if (m_root == nullptr)
        return "";

    return m_root->toString();
}
