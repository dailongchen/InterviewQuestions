//
//  charBoard.hpp
//  Interview
//
//  Created by Solon Chen on 12/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef charBoard_hpp
#define charBoard_hpp

#include <map>
#include <set>
#include <vector>

class CharBoard {
public:
    CharBoard(const std::vector<std::vector<char>>& board);

    bool Exist(const std::string& word) const;

private:
    bool exist(int x, int y,
               const std::string& word, size_t n,
               const std::set<std::pair<int, int>>& path) const;

private:
    std::vector<std::vector<char>> m_board;
    size_t m_rowCount;
    size_t m_columnCount;
};

#endif /* charBoard_hpp */
