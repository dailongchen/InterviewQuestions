//
//  reversePolishNotation.hpp
//  Interview
//
//  Created by Solon Chen on 13/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef reversePolishNotation_hpp
#define reversePolishNotation_hpp

#include <cassert>
#include <functional>
#include <memory>
#include <stdexcept>
#include <vector>

class ReversePolishNotation {
private:
    class Node {
    public:
        typedef std::shared_ptr<Node> ptr;

    public:
        Node() {
        }

        Node(Node::ptr left,
             Node::ptr right)
        : m_left(left), m_right(right) {
        }
        virtual ~Node() {
        }

        virtual int GetValue() const = 0;

    protected:
        Node::ptr m_left;
        Node::ptr m_right;
    };

    class OperatorNode : public Node {
    public:
        typedef std::function<int(int, int)> Func;

    public:
        OperatorNode(Func func,
                     Node::ptr left,
                     Node::ptr right)
        : m_func(func), Node(left, right) {
        }

        virtual int GetValue() const {
            if (m_left == nullptr || m_right == nullptr)
                throw std::runtime_error("");

            return m_func(m_left->GetValue(), m_right->GetValue());
        }
    private:
        Func m_func;
    };

    class IntegerNode: public Node {
    public:
        IntegerNode(int val)
        : m_val(val), Node() {
        }

        virtual int GetValue() const {
            return m_val;
        }
    private:
        int m_val;
    };
public:
    static ReversePolishNotation Create(const std::vector<std::string>& tokens);

    int Calculate() const;

private:
    ReversePolishNotation(Node::ptr root)
    : m_root(root) {
    }

private:
    Node::ptr m_root;
};

#endif /* reversePolishNotation_hpp */
