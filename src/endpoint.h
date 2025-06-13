// #ifndef ENDPOINT_H
// #define ENDPOINT_H
#pragma once

// #include <iostream>
#include <spdlog/spdlog.h>
#include <crow.h>

namespace sweethome {

class EndPoint {
    public:
        EndPoint(const std::string& prefix);
        crow::Blueprint& Blueprint();
    private:
        crow::Blueprint m_blueprint;
};

}

// #endif //ENDPOINT_H