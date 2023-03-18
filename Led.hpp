#pragma

#include <chrono>
#include <thread>

namespace lib::hw::led
{
enum class STATE
{
    OFF,
    ON
};

class Led
{
public:
    Led();
    ~Led();

    void turnOn();
    void turnOff();
    void blink(uint16_t delayMs);

private:
    uint8_t pin;
    STATE isOn;
};    
} // namespace lib::hw::led
