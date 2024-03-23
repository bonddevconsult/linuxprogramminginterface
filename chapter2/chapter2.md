# Chapter 2 Fundamentals

## Definitions

1. **CPU** - Central processing unit. Computers will have multiple cpus running at the same time. Hence the need for a scheduler.
2. **RAM** - Random Access Memory. The memory allocated for the kernel to run programs
3. **Devices** - network cards, hard disks, monitors, keyboards, mice, etc.
4. **[Computer] resources** - the CPU, RAM, and devices
5. **Kernel** - the central software that manages and allocates computer resources
6. **Preemptive multitasking** - Used to describe the action of the scheduler to pull multiple programs into RAM and the fact that the scheduler handles this process instead of the programs themselves
7. **virtual memory** - physical storage addresses mapped to virtual addresses for use by the kernel to allocate to processes
8. **Virtual memory management** - a technique for organizing and allocating physical memmory into virtual memory
9. **process** - a running program with access to CPU,memory, and file I/O
10. **API** - Application Programming Interfaces
11. **System Call** - Entrypoints for processes to request the kernel to perform kernel space tasks
12. **User space** - An area of virtual memory specifically for non-kernel processes
13. **Kernel space** - An area of virtual memory specifically for kernel processes
14. **user mode** - A CPU mode that only has access to user space memory
15. **kernel mode** - AKA supervisor mode. A CPU mode that access to user and kernel space memory 
16. **asynchronous** - out of order. Opposite of synchronous. Synchronous tasks finish in the order they are started every time. Asynchronous tasks may: resolve immediately, resolve in any order, or timeout.
17. **swap [disk] space** - extra memory for the kernel to use if it runs out of RAM
18. **login shell** - The process that is created to run a shell when the user first logs in
19. **Shell scripts** - text files containing shell commands

## What Is The Kernel

- Operating System has two definitions

  1. Denoting the central software managing a computer's resources in addition to all the accompanying software that uses those resources like: command line interpreters(**cli**), graphical user interfaces(**gui**), and file editiors.

  2. Denoting just that central software that manages the computers resources. AKA the **kernel**, like a popcorn kernel

- The kernel provides a software layer for users and programs to interact with

- kernel location is normally at `/boot/vmlinuz`, z denoting that it is a compressed executable of linux

## Kernel Tasks

- **Process Scheduling** - The kernel is responsible for using preemptive multitasking to decide which programs should be running when.

- **Memory Management** - The linux kernel uses virtual memory management to keep processes from reading or modifying the memory of another process or the kernel and to minimize how much of a program needs to be loaded into physical memory to run.

- **Provision of a Filesystesm** - Allows files to be created, retrieved, updated, and deleted

- **Creation and termination of processes**

- **Access to Devices** - The kernel simultaneous provides multiple programs with an interface that standardizes and simplifies device access.

- **Networking** - The kernel routes, transmits, and receives network messages on behalf of users processes.

- **Provision of a system call API** - The kernel is responsible for providing an application programming interface of system calls available to processes.

- **Virtual Private Computer** - Each user should be able to login and operate independently of the other users. like a home directory

- **Resolving conflicts in accessing hardware resources**

## Kernel Mode vs User Mode

- Some operations can only be performed when the CPU is in kernel mode. Like device I/O
- 

### The life of a process(user mode)

1. Processes operate in isolation
2. Many things happen asynchronously. Outside the purview of the process
3. Delivery of signals and communication to other processes is mediated by the kernel and can happen at any time for a process
4. Many things happen transparently for a process
5. Processes refer to files by name, not their location in memory
6. Processes cannot communicate directly with i/o devices
7. Processes cannot create a new process or end itself without using the kernel
7. Processes don't know
  a. where they are in RAM or if they're using swap space
  b where on disk, the files they access are 

### What the kernel does

1. knows and controls everything
2. Facilitates the running of all processes
3. Decides which process will next obtain access to the CPU, when, and for how long
4. Kernel maintains data about all running processes. Which includes

  - when processes are created, change state, and terminate
  - mappings between filenames and physical locations on disks
  - mappings between virtual memory of each process into the physical memory of the computer and the swap areas on disk

5. Provides interprocess communication mechanisms
6. Creates new processes and terminates existing processes(after being prompted by a userspace process)

## The Shell

- A special-purpose program designed to read user commands and execute programs in response to those commands.
- aka command interpreter
- On UNIX systems, the shell is a **user process**. It is a part of the kernel on other operating systems
- Many shells exist and a user may use many different shells simultaneously
- Designed for interactive use and the interpretation of shell scripts
- Each of the shells have programming language features like: variables, loops, conditional statements, functions, and I/O commands.

### Some cool shells

- Bourne Shell(sh): The oldest, written by Steve Bourne. Some features: I/O redirections, pipelines, filename globbing, variables, environment variables, background command execution. All later UNIX implementations include the Bourne shell along with their standard shell
- C shell(csh): Written by Bill Joy at UC Berkeley. Its flow-control constructs resembles that of C. Added the following to the features of the bourne shell: command history, command-line editing, job control, and aliases.
- Korn Shell(ksh): Written by David Korn. Essentially a backards sh compatible version of csh.
- Bourne Again Shell(bash): The GNU Project's reimplementation of the Bourne Shell. THe most widely used on linux. Alan's default

## Users and Groups