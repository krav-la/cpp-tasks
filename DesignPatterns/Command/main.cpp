/**
 * @file main.cpp
 * @brief Example of a command pattern implementation
 * 
 * 
 */
#include <iostream>
#include <map>

/* Recievers */
class CoolingControl
{
public:
    void turnCoolingOn() { std::cout << "Cooling is turned on" << std::endl; };
    void turnCoolingOff() { std::cout << "Cooling is turned off" << std::endl; };
};
class LightControl
{
public:
    void turnLightOn() { std::cout << "Light is turned on" << std::endl; };
};

/* Commands */
class Command
{
public:
    virtual void execute() = 0;
};

class TurnLightOnCommand : public Command
{
private:
    /* Command reciever */
    LightControl ligthControlSystem;

public:
    void execute() override { ligthControlSystem.turnLightOn(); };
};

class ResetCoolingCommand : public Command
{
private:
    CoolingControl coolingControlSystem;

public:
    void execute() override {
        coolingControlSystem.turnCoolingOff();
        coolingControlSystem.turnCoolingOn();
    };
};

/* Command invoker */
class Invoker {

private:
    std::map<std::string, Command*> commands;

public:
    void setCommand(Command* newCommand, std::string name) {
        commands[name] = newCommand;
    };

    void resetCooling() {commands["reset_cooling_system"]->execute();}
    void turnOnLight() {commands["turn_light_on"]->execute();}
};

int main(int argc, char *argv[])
{
    Invoker smartHome;
    TurnLightOnCommand turnLightOnCommand;
    ResetCoolingCommand resetCoolingCommand;

    smartHome.setCommand(&turnLightOnCommand, "turn_light_on");
    smartHome.setCommand(&resetCoolingCommand, "reset_cooling_system");

    smartHome.resetCooling();
    smartHome.turnOnLight();

    return 0;
}
