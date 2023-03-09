#include "Hero.h"
#include <iostream>

Hero::Hero()
{
    currentState = new IdleState();
    currentState->entryAction();
}

Hero::~Hero()
{
    delete currentState;
}

void Hero::doAction()
{
    currentState->action();
}

void Hero::handleEvent(Event ev)
{
    AbstractState *toTransit = currentState->handleEvent(ev);

    if (nullptr != toTransit)
    {
        delete currentState;
        currentState = toTransit;
        toTransit->entryAction();
    }
}
void JumpState::entryAction()
{
    std::cout << "Enter Jump State" << std::endl;
} 

void JumpState::exitAction()
{
    std::cout << "Exit Jump State" << std::endl;
}

void JumpState::action()
{
    std::cout << "Do Jump State Job" << std::endl;
}

AbstractState* JumpState::handleEvent(Event ev)
{
    return nullptr;
}

void DuckState::entryAction()
{
    std::cout << "Enter Duck State" << std::endl;
} 

void DuckState::exitAction()
{
    std::cout << "Exit Duck State" << std::endl;
}

void DuckState::action()
{
    std::cout << "Do Duck State Job" << std::endl;
}

AbstractState* DuckState::handleEvent(Event ev)
{
    AbstractState *toTransit = nullptr;

    switch (ev)
    {
    case Event::DuckKeyReleased:
        toTransit = new IdleState();
        break;
    default:
        break;
    } 

    return toTransit;
}

void IdleState::entryAction()
{
    std::cout << "Enter Idle State" << std::endl;
} 

void IdleState::exitAction()
{
    std::cout << "Exit Idle State" << std::endl;
}

void IdleState::action()
{
    std::cout << "Do Idle State Job" << std::endl;
}

AbstractState* IdleState::handleEvent(Event ev)
{
    AbstractState *toTransit = nullptr;

    switch (ev)
    {
    case Event::JumpKeyPressed:
        toTransit = new JumpState();
        break;
    case Event::DuckKeyPressed:
        toTransit = new DuckState();
        break;
    default:
        break;
    } 

    return toTransit;
}