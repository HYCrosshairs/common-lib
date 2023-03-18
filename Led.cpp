#include "Led.hpp"

using namespace lib::hw::led;


Led::Led()
{
}

Led::~Led()
{
}

void Led::turnOn()
{
    isOn = STATE::ON;
    // TODO:
}

void Led::turnOff()
{
    isOff = STATE::OFF;
    // TODO:
}

void Led::blink(uint16_t delayMs)
{
    turnOn();
    std::this_thread::sleep_for(std::chrono::microseconds(delayMs));
    turnOff();
    std::this_thread::sleep_for(std::chrono::microseconds(delayMs));
}