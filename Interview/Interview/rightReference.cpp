//
//  leftReference.cpp
//  Interview
//
//  Created by Solon Chen on 21/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include "rightReference.hpp"

RightReference::RightReference(const std::string& str) : m_str(str) {

}

RightReference::RightReference(std::string&& str) {
    m_str = std::move(str);
}

RightReference::RightReference(const RightReference& l) {
    m_str = l.m_str;
}

RightReference::RightReference(RightReference&& l) {
    m_str = std::move(l.m_str);
}

RightReference & RightReference::operator= (const std::string& str) {
    m_str = str;
    return *this;
}

RightReference & RightReference::operator= (std::string&& str) {
    m_str = std::move(str);
    return *this;
}

RightReference & RightReference::operator= (const RightReference& l) {
    m_str = l.m_str;
    return *this;
}

RightReference & RightReference::operator= (RightReference&& l) {
    m_str = std::move(l.m_str);
    return *this;
}

void RightReference::test() const {
    RightReference a("a");
    RightReference d = std::move(a);
    RightReference c(std::move("c"));
    c = "d";
    c = a;
    c = std::move(d);
}
