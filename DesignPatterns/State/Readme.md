# State 
## Finite State Machine (FSM)
A finite state machine is a mechanism that allows to define an object that has internal states. The object can change these states when an event happens.

For ex., we can have an object called Hero. The hero can be idle and do nothing or can jump, run or sprint whilst already running. 

![Hero State Machine](State-Machine.jpg "Hero State Machine")

Every state change is initiated by an incoming event like a controller or a keyboard button press.
So if we press an Up button the hero's gonna jump or if we hold a run button they're gonna run and so on.

## States and Events
Hero  is in fact the State Machine.
There's a fixed set of states and events spawning state transitions. 

You need to come up with the possible states that the hero has and transitions that spawn a new state change.

To describe all possible states and transitions between them you can use a transition table like below

|   	|Idle	        | Run  	        |
|---	|---	        |---	        |
|Idle  	|x   	        | Run pressed  	|
|Run   	|Run released   |x   	        |
|   	|   	        |   	        |

The first column and row contain states to transit from and to respectively.

We keep transition events in row and column intersections. So if the Hero is in the Run state and the run button is released the state is changed to Idle.

## Gun State Machine
|   	    |Idle	            |Shooting           |Reloading          |
|---	    |---	            |---	            |---                |
|Idle  	    |x   	            |Fire pressed       |Reload key pressed |
|Shooting   |Fire released      |x   	            |Reload key pressed |
|Reloading  |Reload finished    |Fire pressed       |x                  |

## References
- [Refactoring Guru. State](https://refactoring.guru/design-patterns/state)
- [SOLID Design Principles](https://hackernoon.com/10-oop-design-principles-every-programmer-should-know-f187436caf65)