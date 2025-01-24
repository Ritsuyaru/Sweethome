#ifndef SENSORS_H
#define SENSORS_H

#include <iostream>
#include <filesystem>
#include <unordered_map>

#include "settings.h"

namespace sweethome
{
enum Unit
{
    ampere,
    voltage,
    degree_celsius,
    unknow
};

static Unit GetUnit(std::string str_unit)
{
    if (str_unit == "ampere") return Unit::ampere;
    if (str_unit == "voltage") return Unit::voltage;
    if (str_unit == "degree_celcius") return Unit::degree_celsius;
    return Unit::unknow;
};

static std::string ToString(Unit unit)
{
    switch (unit)
    {
    case Unit::ampere : return "ampere";
    case Unit::voltage : return "voltage";
    case Unit::degree_celsius : return "degree_celsius";
    
    default : return "unknow";
    }
}

class Sensors : public Settings
{
    public:
        Sensors(std::filesystem::path yaml_file);
        void SetValue(float value) { m_value = value; };
        float GetValue() { return m_value; };
        void Update();
    private:
        std::string m_name;
        float m_value;
        Unit m_unit;
};

}

#endif