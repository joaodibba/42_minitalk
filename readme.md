# Minitalk: Inter-Process Communication Simplified

Minitalk is a lightweight and efficient client-server application designed to enable inter-process communication between using UNIX signals. 

## Features

- **Server Process**: The server process is continuously listening for incoming messages, ensuring real-time communication.
- **Client Process**: The client process is responsible for sending messages to the server, providing a seamless communication experience.

## How it Works
Minitalk uses the power of UNIX signals to establish a communication channel between two processes. The client sends messages in the form of signals which the server "listens" to and processes accordingly.

The server process is responsible for handling incoming signals and converting them into human-readable messages.
The client process is responsible for converting the user message and sending that to the server process using the server's PID.

Stay tuned for more updates and features. Contributions are always welcome!

## Usage
To use minitalk, run this command:
```
https://github.com/joaodibba/42_minitalk.git; cd 42_minitalk; make
```
After running the command, open two terminals in the same directory.
```
./server
```
The server will print its own PID and will start listening for incoming messages. 

In the second terminal, run the client process with the following command:
```
./client <PID> <message>
```
The client process will send the message to the server process using the server's PID. The server will then print the message.