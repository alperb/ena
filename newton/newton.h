#pragma once

namespace ENA {
    
    class Newton {
    public:
        Newton() = default;
        Newton(const Newton&) = delete;
        Newton& operator=(const Newton&) = delete;
        
        void init();
    };

}