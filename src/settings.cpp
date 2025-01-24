#include "settings.h"

namespace sweethome
{
Settings::Settings(std::filesystem::path yaml_file)
{
    Load(yaml_file);
}

bool Settings::Load(std::filesystem::path yaml_file)
{
    // auto yaml_file = YAML::LoadFile(yaml_file.string());
    m_yaml_file = yaml_file;
    return false;
        
}

std::vector<Settings::NameTemplate> Settings::TemplatesForName(const std::string& name) const
{
    std::vector<NameTemplate> templates;
    static const std::regex template_regex(R"(\{(\d+)-(\d+)\})");
    std::smatch match;
    if (std::regex_search(name, match, template_regex)) {
        int start = std::stoi(match[1]);
        int end = std::stoi(match[2]);
        for (int i = start; i <= end; ++i) {
        const std::string templated_name = match.prefix().str() + std::to_string(i) + match.suffix().str();
        templates.emplace_back(templated_name);
        }
    } else {
        templates.emplace_back(name);
    }
    return templates;
}

void Settings::GetSensors()
{
    // getyaml("sensor");
}

std::vector<Device> Settings::GetDevices(std::string type_device)
{
    // std::string file  = "./devices.yaml";
    auto device_mappings = YAML::LoadFile(m_yaml_file);
    spdlog::info("Load File: {}", m_yaml_file.string());
    std::vector<Device> devices;
    for (auto actuator: device_mappings[type_device]) {
        spdlog::info("name: {}", actuator["name"].as<std::string>());
        spdlog::info("type: {}", actuator["type"].as<std::string>());
        spdlog::info("location: {}", actuator["location"].as<std::string>());
        Device device;
        device.name = actuator["name"].as<std::string>();
        device.type = actuator["type"].as<std::string>();
        device.location = actuator["location"].as<std::string>();
        devices.push_back(device);
    }
    // search "actuator"
    // auto Data_name = LoadStringFromNode(device_mappings, "name");
    // for (const auto& templated_device_name : TemplatesForName(data_name)) {
    //     std::cout << templated_device_name << std::endl;
    //     // LoadActuator();
    // }
    // while(!device_actuators.end()) {
    //     actuators.add(actuator)
    // }
    return devices;
}   

void Settings::ReadYaml()
{

}

}