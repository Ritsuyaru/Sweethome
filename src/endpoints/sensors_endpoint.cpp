
// #include <crow.h>
#include "sensors_endpoint.h"

namespace sweethome
{

SensorEndpoint::SensorEndpoint() : BaseEndpoint("sensors/")
{
    CROW_BP_ROUTE(m_blueprint, "").methods(crow::HTTPMethod::POST)([this](const crow::request& request) {
    // CROW_BP_ROUTE(m_blueprint, "temp1")([]() {
        crow::json::rvalue json = crow::json::load(request.body);
        // if (bad json) {
        //     return crow::response(400, "bad request: bad json");
        // }
        // if (name not exist) {
        //     return crow::response(400, "bad request: name not exist");
        // }
        // setValue(json);
        return crow::response(200);
    });

    // CROW_BP_ROUTE()
}

}