//
//  charBoard.cpp
//  Interview
//
//  Created by Solon Chen on 12/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include "charBoard.hpp"

#include <string>

CharBoard::CharBoard(const std::vector<std::vector<char>>& board)
: m_board(board) {
    m_rowCount = m_board.size();
    m_columnCount = 0;
    if (m_rowCount > 0)
        m_columnCount = m_board[0].size();
}

bool CharBoard::Exist(const std::string& word) const {
    std::set<std::pair<int, int>> path;
    for (int x = 0; x < m_rowCount; x++) {
        for (int y = 0; y < m_columnCount; y++) {
            if (exist(x, y, word, 0, path))
                return true;
        }
    }

    return false;
}

bool CharBoard::exist(int x, int y,
                      const std::string& word,
                      size_t n,
                      const std::set<std::pair<int, int>>& path) const {
    if (n >= word.size())
        return true;
    if (x < 0 || y < 0 || x >= m_rowCount || y >= m_columnCount)
        return false;
    if (path.find({x, y}) != path.end())
        return false;

    char c = word.at(n);
    if (m_board[x][y] != c)
        return false;

    auto newPath = path;
    newPath.insert({x, y});

    if (exist(x + 1, y, word, n + 1, newPath))
        return true;
    if (exist(x - 1, y, word, n + 1, newPath))
        return true;
    if (exist(x, y + 1, word, n + 1, newPath))
        return true;
    if (exist(x, y - 1, word, n + 1, newPath))
        return true;

    return false;
}
