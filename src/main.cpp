#include <iostream>
#include <thread>
#include <chrono>

// #include <pamela/pamela.h>
// #include <yaml-cpp/yaml.h>


int main(int argc, char ** argv)
{
    const std::chrono::duration<float> time_sample_dt{2};

    // Sensors sensors;
    // Commands command;
    // Communication communication;

    // sensors.Load(GetConf());
    // commands.Load(GetPath("yml_commands.yml"));
    // communication.load(GetConf());

    // Launch comm thread

    while (true)
    {
        //control.Update();
        std::cout << "Update" << std::endl;
        std::this_thread::sleep_for(time_sample_dt);
    }

    return 0;
}


