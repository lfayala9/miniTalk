# miniTalk
In this project we create a program that transmit messages between processes using a custom minitalk communication protocol

Signals are a form of communiaction between processes, can be defined as messages

in this project signals are used to transmit messages between processes using the minitalk communication protocol

The PID of a process is its identifier, like a passport, and to send a signal to a certtain process you need that PID

## Functions used:

signal()

<code>void __cdecl *signal(int sig, int (*func)(int, int));</code>

