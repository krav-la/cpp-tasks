#if !defined(HERO_H)
#define HERO_H

#include <iostream>

enum class Event
{
    JumpKeyPressed = 0,
    JumpKeyReleased,
    DuckKeyPressed,
    DuckKeyReleased
};

class AbstractState
{
private:
    /* data */
public:
    virtual void entryAction() = 0;
    virtual void exitAction() = 0;
    virtual AbstractState *handleEvent(Event ev) = 0;
    virtual void action() = 0;
};

class Hero
{
private:
    AbstractState *currentState;

public:
    Hero();
    ~Hero();
    void handleEvent(Event ev);
    void doAction();
};

class IdleState : public AbstractState
{
private:
    /* data */
public:
    void entryAction() override;
    void exitAction() override;
    AbstractState *handleEvent(Event ev) override;
    void action() override;
};

class JumpState : public AbstractState
{
private:
    /* data */
public:
    void entryAction() override;
    void exitAction() override;
    AbstractState *handleEvent(Event ev) override;
    void action() override;
};

class DuckState : public AbstractState
{
private:
    /* data */
public:
    void entryAction() override;
    void exitAction() override;
    AbstractState *handleEvent(Event ev) override;
    void action() override;
};

#endif //HERO_H
