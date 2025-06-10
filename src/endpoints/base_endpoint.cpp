// #include <crow.h>
#include "base_endpoint.h"

namespace sweethome
{

BaseEndpoint::BaseEndpoint(const std::string& prefix) :
    m_blueprint(prefix)
{
}

crow::Blueprint &BaseEndpoint::Blueprint()
{
    return m_blueprint;
}

}