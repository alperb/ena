#include "queue.h"

template<typename T>
void ENA::Queue<T>::push(const T& value) {
    std::lock_guard<std::mutex> lock(_mutex);
    _queue.push(value);
}

template<typename T>
T ENA::Queue<T>::pop() {
    std::lock_guard<std::mutex> lock(_mutex);
    T value = _queue.front();
    _queue.pop();
    return value;
}

template<typename T>
bool ENA::Queue<T>::isEmpty() const {
    std::lock_guard<std::mutex> lock(_mutex);
    return _queue.empty();
}