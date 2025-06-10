#ifndef SERVER_H
#define SERVER_H

#include <crow>

#include "settings.h"

namespace sweethome
{

class Server : public Setting
{
    public:
        Server();
        void LaunchServer();

    private:
        std::string adress;
}

}

#endif