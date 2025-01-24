#include <iostream>
#include <optional>
#include <filesystem>
#include <thread>
#include <chrono>
#include <spdlog/spdlog.h>

#include "settings.h"
// #include "sensors.h"


int main(int argc, char ** argv)
{
    const std::chrono::duration<float> time_sample_dt{2};

    const std::filesystem::path conf_folder{"conf/"};
    const std::filesystem::path conf_override_folder{"conf/"};

    auto GetPathOptional = [&](std::string file_name) -> std::optional<std::filesystem::path>
    {
        if (!conf_override_folder.empty() && std::filesystem::exists(conf_override_folder / file_name)) 
            return conf_override_folder / file_name;
        if (std::filesystem::exists(conf_folder / file_name))
            return conf_folder / file_name; 
        spdlog::error("file {} not found in conf folders", file_name);
        return {};
    };

    auto GetPath = [&](std::string file_name) -> std::filesystem::path
    {
        auto optional_path = GetPathOptional(file_name);
        if (!optional_path.has_value()) {
            spdlog::error("file {} not found in conf folders", file_name);
            return {};
        }
        return optional_path.value();
    };
    
    // std::cout << GetPath("yaml_sensors.yml").string() << std::endl;
    const std::filesystem::path devices_file_path = GetPath("devices.yml");
    if (devices_file_path.has_relative_path()) {
        spdlog::info("file path : {}", devices_file_path.string());
        sweethome::Settings setting{devices_file_path};
        setting.GetDevices("actuators");
    }
    // Sensors sensors;
    // Commands command;
    // Communication communication;

    // sensors.Load(GetConf());
    // commands.Load(GetPath("yml_commands.yml"));
    // communication.load(GetConf());

    // Launch comm thread

    // while (true)
    // {
    //     //control.Update();
    //     std::cout << "Update" << std::endl;
    //     std::this_thread::sleep_for(time_sample_dt);
    // }

    return 0;
}


