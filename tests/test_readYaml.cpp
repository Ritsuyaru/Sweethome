#include <gtest/gtest.h>

#include "../src/settings.h"

TEST(testSuite, readYaml)
{

    const std::filesystem::path file_path{"./tests/conf/devices.yml"};
    sweethome::Settings setting{file_path};
    // if (file_path.has_relative_path()) {
    //     // setting.GetDevices("actuators");
    // }
    auto devices = setting.GetDevices("actuators");
    EXPECT_STREQ(devices[0].name.c_str(), "act1");
    EXPECT_STREQ(devices[0].location.c_str(), "loc1");
    EXPECT_STREQ(devices[0].type.c_str(), "actu");
    //test conf
    // actuators:
    // - name: act1
    //     type: actua
    //     location: loc1
    // EXPECT_STREQ(, );
}