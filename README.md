# Low-Level TCP in C

Minimal TCP client-server implementation using POSIX sockets in C.

## Overview

This project explores how a TCP connection is established and handled at a low level, without abstractions or external libraries.

The server accepts a client, reads incoming data into a buffer, and sends back a simple response. The client reads input from stdin and sends it through the socket.

## Key Concepts

- Socket descriptors managed by the kernel  
- IPv4 addressing with sockaddr_in  
- Network byte order (htons)  
- Direct I/O with read and write  
- Manual buffer handling in memory  

## Structure

server/tcp_server.c  
client/tcp_client.c  

## Build

gcc server/tcp_server.c -o server  
gcc client/tcp_client.c -o client  

## Run

./server  
./client  

## Scope

This is a minimal implementation focused on understanding TCP communication and system-level behavior in C.
