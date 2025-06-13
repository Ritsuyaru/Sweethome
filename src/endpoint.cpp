#include "endpoint.h"

namespace sweethome {

EndPoint::EndPoint(const std::string& prefix) :
    m_blueprint(prefix)
{
    CROW_BP_ROUTE(m_blueprint, "").methods(crow::HTTPMethod::POST)([this](const crow::request& request) {
    // CROW_BP_ROUTE(m_blueprint, "temp1")([]() {
        crow::json::rvalue json = crow::json::load(request.body);
        std::string temp = json["temperature"].s();
        spdlog::info("temp: {}", temp);
        return crow::response(200);
    });
}

crow::Blueprint& EndPoint::Blueprint() {
    return m_blueprint;
}

}