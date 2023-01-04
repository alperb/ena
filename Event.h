#pragma once

enum EVENT_ACTION {
    QUIT_GAME = 0,
    MOVE_OBJECT = 1,
};

enum MOVE_DIRECTION {
    RIGHT = 0,
    LEFT = 1,
};

struct Event {
    int key;
    EVENT_ACTION action;
    MOVE_DIRECTION direction;

    Event(int key, EVENT_ACTION action, MOVE_DIRECTION direction) {
        this->key = key;
        this->action = action;
        this->direction = direction;
    }

    Event() = default;
};

namespace EVENTS {
    static std::vector<Event> Events;
}

