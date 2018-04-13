//
//  taskScheduler.cpp
//  Interview
//
//  Created by Solon Chen on 13/03/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include "taskScheduler.hpp"

TaskScheduler::TaskScheduler(const std::vector<char>& tasks) {
    size_t tasksCacheCount = (sizeof(m_tasks) / sizeof(m_tasks[0]));
    for (size_t i = 0; i < tasksCacheCount; i++) {
        char c = 'A' + i;
        m_tasks[i] = {c, 0};
    }

    for (char c : tasks) {
        m_tasks[c - 'A'].Count++;
    }

    std::sort(m_tasks, m_tasks + tasksCacheCount, [](auto& a, auto& b) -> bool {
        return a.Count < b.Count;
    });

    m_tasksCount = tasks.size();
}

int TaskScheduler::leastInterval(int n) {
    int intervalCount = 0;
    int allCarriedTasks = 0;

    while (true) {
        int carriedTasks = 0;
        for (int i = 0; i < (sizeof(m_tasks) / sizeof(m_tasks[0])) && carriedTasks < n + 1; i++) {
            if (m_tasks[i].Count > 0) {
                m_tasks[i].Count--;
                carriedTasks++;
            }
        }

        intervalCount += carriedTasks;

        allCarriedTasks += carriedTasks;
        if (allCarriedTasks == m_tasksCount)
            break;

        intervalCount += n + 1 - carriedTasks;
    }

    return intervalCount;
}
