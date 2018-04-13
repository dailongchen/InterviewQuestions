//
//  taskScheduler.hpp
//  Interview
//
//  Created by Solon Chen on 13/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#ifndef taskScheduler_hpp
#define taskScheduler_hpp

#include <vector>

class TaskScheduler {
private:
    struct Task {
        char C;
        int Count;
    };

public:
    TaskScheduler(const std::vector<char>& tasks);

    int leastInterval(int n);

private:
    Task m_tasks[26];
    size_t m_tasksCount;
};

#endif /* taskScheduler_hpp */
