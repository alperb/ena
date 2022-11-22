#pragma once
#include <string>
#include "messages.h"


namespace ENA {

    class Events {

    public:
        static Message getEvent(std::string message);
    };

}