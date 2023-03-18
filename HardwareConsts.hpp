#pragma once

#include <stdint.h>

namespace hw::lib
{

constexpr char PWM_CHANNEL[] = "/dev/pwmchip%d";
constexpr char GPIO_PATH[] = "/sys/class/gpio/gpio%d/value";
constexpr char GPIO_MODE[] = "/sys/class/gpio/gpio%d/direction";
constexpr char GPIO_EXPORT_PATH[] = "/sys/class/gpio/export";

enum STATE : uint8_t
{
    LOW,
    HIGH
};

enum class MODE : uint8_t
{
    IN,
    OUT
};

constexpr const char* const DIRECTION[] = {
                            "in",
                            "out"
                          };
    
} // namespace hw::lib
