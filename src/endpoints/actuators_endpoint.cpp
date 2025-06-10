
// #include <crow.h>
#include "actuators_endpoint.h"

namespace sweethome
{

ActuatorsEndpoint::ActuatorsEndpoint() : BaseEndpoint("actuators/")
{
    CROW_BP_ROUTE(m_blueprint, "")([this](const crow::request& request) {
        return (400, "Bad request");
        // return getActuator(request);
    });
}

}