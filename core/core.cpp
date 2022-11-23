#include "core.h"
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

ENA::Core::~Core() {
    delete this->_newton;
    this->_newton = nullptr;

    delete this->_salvador;
    this->_salvador = nullptr;

    delete this->_messageQueue;
    this->_messageQueue = nullptr;

    delete this->_eventQueue;
    this->_eventQueue = nullptr;
}