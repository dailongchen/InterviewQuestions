//
//  myString.hpp
//  Interview
//
//  Created by Solon Chen on 27/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef myString_hpp
#define myString_hpp

#include <cstddef>
#include <istream>
#include <ostream>

#include "iTestable.h"

class MyString : public iTestable {
public:
    MyString();
    MyString(const MyString &);
    MyString(const char *);
    MyString(size_t,char);
    ~MyString();

    size_t length();
    bool isEmpty();
    const char *c_str();
    friend std::ostream& operator<< (std::ostream&, const MyString&);
    friend std::istream& operator>> (std::istream&, MyString&);

    friend MyString operator+ (const MyString&,const MyString&);

    bool operator== (const MyString&);
    bool operator!= (const MyString&);
    bool operator<= (const MyString&);
    bool operator>= (const MyString&);

    char& operator[] (size_t);
    const char& operator[] (size_t)const;
    MyString& operator= (const MyString&);
    MyString& operator+= (const MyString&);

    MyString substr(size_t pos,const size_t n);
    MyString& append(const MyString&);
    MyString& insert(size_t,const MyString&);
    MyString& erase(size_t,size_t);
    int find(const char* str,size_t index=0);

    virtual void test() const;

private:
    char *p_str;
    size_t strLength;
};

#endif /* myString_hpp */
