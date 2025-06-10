#pragma once

// #include <iostream>
#include <utility>

#include <spdlog/spdlog.h>
#include <crow.h>

namespace sweethome
{

class BaseEndpoint
{
    public:
        BaseEndpoint(const std::string& prefix);

        crow::Blueprint& Blueprint();

    protected:
        crow::Blueprint m_blueprint;
};

}