#include "ena.h"
#include "../logs/logs.cpp"
#include "../queue/queue.h"

void ENA::Core::init() {
    // start message queues
    this->_initQueues();

    // start newton
    this->_initNewton();

    // start salvador
    this->_initSalvador();

    // start message listeners

    // start event listeners
}

void ENA::Core::_initNewton() {
    this->_newton = new ENA::Newton();
    this->_newton->init();
}

void ENA::Core::_initSalvador() {
    this->_salvador = new ENA::Salvador();
}

void ENA::Core::_initQueues() {
    _messageQueue = new Queue<SystemEvent>();
    ENA::Log::debug("Message queue initialized");

    _eventQueue = new Queue<Event>();
    ENA::Log::debug("Event queue initialized");
}