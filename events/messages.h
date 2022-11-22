#pragma once


namespace ENA {

    class Message {
    public:
        Message() = default;
        Message(const Message&) = default;
        Message& operator=(const Message&) = default;

        virtual ~Message() = default;
    };

    class Event : public Message {
    public:
        Event() = default;
        Event(const Event&) = default;
        Event& operator=(const Event&) = default;

        virtual ~Event() = default;
    };

    class SystemEvent : public Event {
    public:
        SystemEvent() = default;
        SystemEvent(const SystemEvent&) = default;
        SystemEvent& operator=(const SystemEvent&) = default;

        virtual ~SystemEvent() = default;
    };

}