//
//  reversePolishNotation.cpp
//  Interview
//
//  Created by Solon Chen on 13/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include "reversePolishNotation.hpp"

#include <string>

ReversePolishNotation ReversePolishNotation::Create(const std::vector<std::string>& tokens) {
    std::vector<Node::ptr> nodes;

    auto pushOperator = [&nodes](OperatorNode::Func func, const std::string& operatorStr) {
        if (nodes.size() < 2)
            throw std::out_of_range("operator '" + operatorStr + "' appears in a wrong position");

        auto right = nodes.back();
        nodes.pop_back();
        auto left = nodes.back();
        nodes.pop_back();

        nodes.push_back(Node::ptr(new OperatorNode(func, left, right)));
    };

    for (auto str : tokens) {
        if (str == "+") {
            pushOperator([](int l, int r) -> int {
                return l + r;
            }, str);
        }
        else if (str == "-") {
            pushOperator([](int l, int r) -> int {
                return l - r;
            }, str);
        }
        else if (str == "*") {
            pushOperator([](int l, int r) -> int {
                return l * r;
            }, str);
        }
        else if (str == "/") {
            pushOperator([](int l, int r) -> int {
                return l / r;
            }, str);
        }
        else {
            int num = std::stoi(str);
            nodes.push_back(Node::ptr(new IntegerNode(num)));
        }
    }

    if (nodes.size() != 1)
        throw std::invalid_argument("tokens cannot be convert an expression");

    return ReversePolishNotation(nodes.front());
}

int ReversePolishNotation::Calculate() const {
    return m_root->GetValue();
}
