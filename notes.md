Signals are a form of communiaction between processes, can be defined as messages

in this project signals are used to transmit messages between processes using the minitalk communication protocol

The PID of a process is its identifier, like a passport, and to send a signal to a certtain process you need that PID

<h1>Functions used:<h1>

signal()

<code>void __cdecl *signal(int sig, int (*func)(int, int));</code>

This function recieves two params, the first is the PID of a given signal, and the second is a pointer to a function. The signal() function returns the previous value of the function associated to the given signal