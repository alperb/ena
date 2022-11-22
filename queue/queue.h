#pragma once

#include <mutex>
#include <queue>

namespace ENA {
    template <typename T>
    class Queue {
    public:
        Queue() = default;
        Queue(const Queue&) = delete;
        Queue& operator=(const Queue&) = delete;

        void push(const T& value);
        T pop();
        bool isEmpty() const;

    private:
        std::queue<T> _queue;
        mutable std::mutex _mutex;
    };
}