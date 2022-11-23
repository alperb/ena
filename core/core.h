#pragma once

#include <mutex>
#include "../queue/queue.h"
#include "../events/messages.h"

#include "../newton/newton.h"
#include "../salvador/salvador.h"

namespace ENA {
    class Core {
    
    public:
        Core() = default;
        Core(const Core&) = delete;
        Core& operator=(const Core&) = delete;
        ~Core();

        void init();

    private:
        void _startEventLoop();

        Newton* _newton;
        void _initNewton();

        Salvador* _salvador;
        void _initSalvador();

        void _initQueues();
        Queue<SystemEvent>* _messageQueue;
        Queue<Event>* _eventQueue;
    };
}