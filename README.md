# miniTalk
In this project we create a program that transmit messages between processes using a custom minitalk communication protocol

Signals are a form of communiaction between processes, can be defined as messages. And a process is a special environment created for the execution of a program. For instance, when you open Chrome or VSCode or any program in the background the OS creates a series of processes associated with that program. And when we manipulate that program, either we close it or execute it in the background for instance. We send a signal to that process. 

in this project signals are used to transmit messages between processes using the minitalk communication protocol

The PID of a process is its identifier, like a passport, and to send a signal to a certtain process you need that PID

So for this project we need the client to send messages to the server, like a websocket come on. But we can't send those strings directly and there's the challenge. We need to send that message encrypted and the server has to interpret that message.

## Functions used:

signal()

<code>void __cdecl *signal(int sig, int (*func)(int, int));</code>

