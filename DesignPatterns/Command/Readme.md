# Command Design Pattern
## Input data

You can find the list of requests (commands) to a web media player in  `rpc.json`

Every request is a JSON object with the following info:

- method - command name
- params - optional argument list

For example, the following command allows to get the selected media format:

```
{
    "method": "getVideoFormat",
}
```
The command is called getVideoFormat and it doesn't take any arguments

Another example is a media format set command with 3 arguments `width, height, framerate`:

```
{
    "method": "setVideoFormat",
    "params": {
        "width": 1920,
        "height": 1080,
        "framerate": 60
    }
}
```

This command called `setVideoFormat` sets new propeties of a media content:
- width: 1920 (picture width in px)
- height: 1080 (picture height in px)
- framerate: 60 (video framerate in fps)

You don't necessarily need to parse the given .json file. Just use it as a description of all supported commands.
> You can also parse the file but it's a bit out of scope of the main task

## Class hierarchy
This task is a good example of a practical use of a command pattern giving us the following advantages:
 1. Protocol extension simplicity. If you need to add a new command you just create a new command class ([Open Closed Design](https://en.wikipedia.org/wiki/Open%E2%80%93closed_principle)
 2. Request handling and the actual command actions are decoupled from each other wich makes the code more readable and easier to mantain [Single Responsibility](https://en.wikipedia.org/wiki/Single-responsibility_principle) principles)

### class Command
Abstract class which is a base class for all commands. Declares a general command interface:
    
    ```
    public:
        virtual void execute() = 0;
    ```

### class ConcreteCommand
A concrete command derived from a Command interface.

```
class GetVideoFormatCommand : public Command
{
private:
    /* Command Reciever */
public:
    void execute() override {
        /* Command actions */
    };
}
```

> Every command is represented by its own class. Command handling logic is descibed in an `execute` method ([Single Responsibility Principle again](https://en.wikipedia.org/wiki/Single-responsibility_principle))

> Reciever - lies on a level of buisness logic with all the low level details about what should be done in response to a given command. `Command` itself, tells the `Reciever` what actions and in which order should be done (within an `executed` body)

### class Invoker
This class is a command container (apart from all its other duties). Commands can be save in a vector or map, for ex.

```
class Invoker
{
private:
    /* Available commands as Command& */
public:
    void setCommand(Command&) {
        /* Add a new command */
    };
    void executeCommand(/* Command ID */) {
        /* Call a corresponding command */
    };

}
```

### class Reciever
All buisiness logic lies here. All respective command actions with their low level details are done here.

```
class Reciever
{
public:
    /* Methods to do different actions. 
     * These are called from Command objects.
     */
}
```

> Recievers are command attributes so every command knows what reciever should be called. Different commands might have different recievers or vice versa. Recievers are called within the code of `execute`.

## main
main function has at least one Invoker one command and its reciever. Reciever in fact is an object controlling the media player

```
/* Reciever Example */
class VideoPlayer 
{
public:
    void play();
    void stop();
    void setMediaFormat();
    void getMediaFormat();
}
```
## References
- [Refactoring Guru. Command](https://refactoring.guru/design-patterns/command)
- [SOLID Design Principles](https://hackernoon.com/10-oop-design-principles-every-programmer-should-know-f187436caf65)