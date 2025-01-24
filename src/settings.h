#ifndef SETTING_H
#define SETTING_H

#include <iostream>
#include <filesystem>
#include <vector>
#include <regex>
#include <spdlog/spdlog.h>

// #include <pamela/pamela.h>
#include "yaml-cpp/yaml.h"

namespace sweethome
{

struct Device
{
    std::string name;
    std::string type;
    std::string location;
};

class Settings
{
    public:
        Settings(std::filesystem::path yaml_file);
        bool Load(std::filesystem::path yaml_file);

        std::string GetSetting(std::string setting) {
            std::string ret;
            return ret;
        };
        void GetSensors();
        std::vector<Device> GetDevices(std::string type_device);

    private:
        void ReadYaml();
        std::filesystem::path m_yaml_file;
        struct NameTemplate {
            std::string name;
            // std::optional<int> template_index;
            std::string type;
            std::string location;
        };
        std::vector<NameTemplate> TemplatesForName(const std::string& name) const;
};

}

#endif