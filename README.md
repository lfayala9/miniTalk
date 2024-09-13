# miniTalk
In this project we create a program that transmit messages between processes using a custom minitalk communication protocol

Signals are a form of communiaction between processes, can be defined as messages. And a process is a special environment created for the execution of a program. For instance, when you open Chrome or VSCode or any program in the background the OS creates a series of processes associated with that program. And when we manipulate that program, either we close it or execute it in the background for instance. We send a signal to that process. 

in this project signals are used to transmit messages between processes using the minitalk communication protocol

The PID of a process is its identifier, like a passport, and to send a signal to a certain process you need that PID

So for this project we need the client to send messages to the server, like a websocket come on. But we can't send those strings directly and there's the challenge. We need to send that message byte to byte and the server has to re-build the message that we sent in binary

## Functions I used:

### sigaction()
This function is used to change the way a program handles the siganls. The signals as we know are a asynchronous form of communication in UNIX. So, sigaction() allows the programmer to specify an personalized action that has to be executed when the process receives a signal. 

This is the basic prototype of sigaction():

```c
<code>int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)</code>
```
<code>int signum</code> represents the signal number that you want to handle (i.e SIGINT (10), SIGUSR1(12), etc)

<code>const struct sigaction *act</code> Represents a pointer to a structure sigaction that defines the action that we are gonna use when we receive the signal

<code>struct sigaction *oldact</code> Represents a pointer to a sigaction structure where the previous action is going to be stored for that signal (we in this project set it to NULL)

So, sigaction is technically a function but actually it is a structure that have this definition

```c
struct sigaction {
    void (*sa_handler)(int);        // Pointer to the function that will handle the signal
    void (*sa_sigaction)(int, siginfo_t *, void *); // Alternative to receive aditional info
    sigset_t sa_mask;                // Set of signals that will be blocked during the signal handling
    int sa_flags;                    // Flags that modifies the signal behaviour
};
```
