# miniTalk
In this project we create a program that transmit messages between processes using a custom minitalk communication protocol

Signals are a form of communiaction between processes, can be defined as messages. And a process is a special environment created for the execution of a program. For instance, when you open Chrome or VSCode or any program in the background the OS creates a series of processes associated with that program. And when we manipulate that program, either we close it or execute it in the background for instance. We send a signal to that process. 

in this project signals are used to transmit messages between processes using the minitalk communication protocol

The PID of a process is its identifier, like a passport, and to send a signal to a certain process you need that PID

So for this project we need the client to send messages to the server, like a websocket come on. But we can't send those strings directly and there's the challenge. We need to send that message byte to byte and the server has to re-build the message that we sent in binary

## **Functions I used:**

- **sigaction()**
    
    This function is used to change the way a program handles the siganls. The signals as we know are a asynchronous form of communication in UNIX. So, sigaction() allows the programmer to specify an personalized action that has to be executed when the process receives a signal. 

    This is the basic prototype of sigaction():

    ```c
    int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
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
- **sigemptyset()**
    
    This one is complex, sigemptyset() is used to initialize a signal set to be empty. It sets all the signals in the signal set to not be included, it clears the signal set so that is doesnt contain any signals 

    ```c
    int sigemptyset(sigset_t *set);
    ```
    <code>sigset_t *set</code>  Represents a pointer to a sigset_t variable that will be initialized to an empty signal set. That special type is used to represent a set of signals and sigemptyset() initializes this set to be empty, meaning it contains no signals.

- **kill()**

    This function is a bit more simple, we use kill() to send a signal to a certain process. Easy, isn't it?

    This is the prototype of the kill() function

    ```c
    int kill(pid_t pid, int sig);
    ```
    <code>pid_t pid</code> Here represents the identifier of the process (Process ID) There you define which process is going to receive the signal. If the process id is a positive integer, you send the signal to that certain process BUT, if the process id is -1 you send the signal to EVERY user process that the program is executing...

    But if we are using a positive integer to represent the process id why the kill function have in its prototype the type *pid_t* instead of *int*... Well it's a semantic reason but also it is used to handle special values, which can be negative. Also, it is a system-defined type that represents processes. Using pid_t instead of int or unsigned int ensures that the code will work in every platform... I say it is a semantic reason also because you are indicating that the variable or parameter defined with pid_t holds the value of a process ID, making easier for other developers to read the code and the purpose of any given variable
- **exit()**
    
    The exit() function in C is used to stop a program immediately and return a status code to the OS

    ```c
    void exit(int status);
    ```
    
    As we know void means that it doesn't return any value, this function stops the program, and int status represents, of course, the status code. It could be 0 to represent EXIT_SUCCESS or 1 to represent EXIT_FAILURE, also, 2 and so on could be use to represent an abnormal termination

- **usleep()**
    
    This one function is even more simple, with usleep() you tell the program to create a small delay of a given amount of microseconds (A million microseconds delay the execution of a given instruction one second)

    This is the prototype of the kill() function

    ```c
    int usleep(useconds_t microseconds);
    ```

## **How does this project works?**