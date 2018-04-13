//
//  randomizedSet.hpp
//  Interview
//
//  Created by Solon Chen on 12/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef randomizedSet_hpp
#define randomizedSet_hpp

#include <memory>

class RandomizedSet {
public:
    class BinaryTreeNode : public std::enable_shared_from_this<BinaryTreeNode> {
    public:
        typedef std::shared_ptr<BinaryTreeNode> ptr;
        typedef struct {
            BinaryTreeNode::ptr remainingRoot;
            bool success;
        } RemoveNodeResult;

    public:
        BinaryTreeNode(int val);

        bool insert(int val);
        RemoveNodeResult remove(int val);

        bool get(int& n, int& val) const;

        std::string toString() const;

    private:
        BinaryTreeNode::ptr m_left;
        BinaryTreeNode::ptr m_right;
        int m_val;
    };

public:
    /** Initialize your data structure here. */
    RandomizedSet();

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val);

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val);

    /** Get a random element from the set. */
    int getRandom() const;

    std::string toString() const;

private:
    BinaryTreeNode::ptr m_root;

    int m_count;
};

#endif /* randomizedSet_hpp */
