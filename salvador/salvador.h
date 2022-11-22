#pragma once

namespace ENA {

    class Salvador {
    public:
        Salvador() = default;
        Salvador(const Salvador&) = delete;
        Salvador& operator=(const Salvador&) = delete;

        void init();
    };

}