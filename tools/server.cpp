#include <spdlog/spdlog.h>
#include <chrono>
#include <thread>
#include <crow.h>

int main(int argc, char **argv)
{
    spdlog::info("Hello World");

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        spdlog::info("hey");
        crow::json::wvalue temp;
        temp["temperature"] = std::string("12.4");
        return temp;
    });

    app.port(3333).multithreaded().run();

    std::chrono::duration<float> sleep{1};
    while(true)
    {
        std::this_thread::sleep_for(sleep);
    }

    return 0;
}