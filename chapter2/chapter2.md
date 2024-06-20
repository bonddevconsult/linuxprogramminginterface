# Chapter 2 Fundamentals

## Definitions

- **Bit** - A binary representation of some state. Bits have only two valid values, 1 or 0. It is the smallest unit of data a computer can store
- **CPU** - Central processing unit. Computers will have multiple cpus running at the same time. Hence the need for a scheduler.
- **RAM** - Random Access Memory. The memory allocated for the kernel to run programs
- **Devices** - network cards, hard disks, monitors, keyboards, mice, etc.
- **[Computer] resources** - the CPU, RAM, and devices
- **Kernel** - the central software that manages and allocates computer resources
- **Preemptive multitasking** - Used to describe the action of the scheduler to pull multiple programs into RAM and the fact that the scheduler handles this process instead of the programs themselves
- **virtual memory** - physical storage addresses mapped to virtual addresses for use by the kernel to allocate to processes
- **Virtual memory management** - a technique for organizing and allocating physical memmory into virtual memory
- **process** - a running program with access to CPU,memory, and file I/O
- **API** - Application Programming Interfaces
- **System Call** - Entrypoints for user space processes to request the kernel to perform kernel space tasks
- **User space** - An area of virtual memory specifically for non-kernel processes
- **Kernel space** - An area of virtual memory specifically for kernel processes
- **user mode** - A CPU mode that only has access to user space memory
- **kernel mode** - AKA supervisor mode. A CPU mode that access to user and kernel space memory 
- **asynchronous** - out of order. Opposite of synchronous. Synchronous tasks finish in the order they are started every time. Asynchronous tasks may: resolve immediately, resolve in any order, or timeout.
- **swap [disk] space** - extra memory for the kernel to use if it runs out of RAM
- **login shell** - The process that is created to run a shell when the user first logs in
- **Shell scripts** - text files containing shell commands
- **single hierarchical directory structure** - A directory hierarchy where every directory is a child of the root directory
– **directory** - a file containing a table of filenames coupled with references to the related files
- **link** - aka hard link. The combination of a filename and a reference to the location of the data associated with that filename
- **symbolic link** - aka soft link. a file containing a filename-plus-reference entry, but, the pointer refers to the string name of another file
- **dangling link** - A symbolic link referring to a file that does not exist
- **absolute path** - Specifies the location of a file with respect to the root directory. Ex: `/absolute/path`
- **relative pathname** - Specifies the location of a file relative to a processs's current working directory. Ex: `relative/path`
- **current working directory** - A process's "current location" within the single directory hierarchy
- **file descriptor** - _Usually_ a small, non-negative integer.
- **standard input** - The file from which a process takes its input
- **standard output** - The file to which the process writes its output
- **standard error** - the file to which the process writes error messages and notifications of exceptional or abnormal conditions
- **source code** - human-readable text consisting of a series of statements written in a programming language, like C.
- **script** - text file to be processed by some command interpreter(python, js, shell)
- **program** - either the source code, compiled binary code - generated using the source code, or a script containing some code.
- **filter** - a program that reads from stdin and performs some transformation of that input, then writes that data to stdout
- **commmand line arguments** - the words that are supplied on the command line when the program is run. Many languages provide interfaces for parsing these values into your program
- **process** - an instance of an executing program
- **process-segments** - a logical division of the process's individual parts
- **PID** - a unique Integer representing a Process Identifier for a process
- **PPID** - a unique Integer representing a Parent Process Identifier for a process

## Helpful tools

- `cd` - change the current working directory for a process
- `stdio library` - a C library for performing I/o. 
  - It includes functions like `fopen()`, `fclose()`, `scanf()`, `printf()`,`fgets()`, `fputs()`.
  - They are layered on top of the I/O system calls
- filters
  - `cat`
  - `grep`
  - `tr`
  - `sort`
  - `wc`
  - `sed`
  - `awk`

## System Calls

- `open(pathname: string)` 
  - used to retrieve a file descriptor for a specified file
- `read()`
- `write()`
- `close()`
- `lseek()` - used by the kernel to randomly access disk files disks and tape devices
- `fork()` - allows a process to create a child process
- `execve()`

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

### What the kernel does(kernel mode)

1. knows and controls everything
2. Facilitates the running of all processes
3. Decides which process will next obtain access to the CPU, when, and for how long
4. Kernel maintains data about all running processes. Which includes:
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

- each user on the system has a unique id
- each user **may** belong to groups
- groups are useful for controlling administrative access to files and other system resources
- Linux users may belong to multiple groups

### User properties

- `username` - login name
- `uid` - user id. Number
- Stored in `/etc/passwd`(the system password file)
  - `/etc/passwd` has additional info
    - **Group ID**: the numeric group ID of the first of the groups of which the user is a member
    - **Home directory**: the inital directory into which the user is placed after logging in
    - **Login shell**: the name of the program to be executed to interpret user commands
    - may also include an encrypted password
    - The password is normally stored in a separate *shadow password file*

### Group Properties

- `group name` - the unique name of the group
- `group id` - the numeric ID assoc with the group
- `User list` - Comma separated list of login names of users who are members of the group
- stoed in `/etc/group`

### Superuser Properties

- `UID`: 0
- `username`: root
- The superuser has special priviliges within the system.
- Passes all permission checks on a typical linux system
- Can access any file and send signals to any user process

## Single Directory Hierarchy, Directories, Links, and Files

- Kernel maintains a single hierarchical directory structure to organize **all** files on the system

### File Types

Each file within the filesysttem has a type

1. `plain files` - aka `regular files`. Ordinary data files
2. `devices`
3. `pipes`
4. `sockets`
5. `directories`
6. `symbolic links`

### Directories and links

- Directories may contain links to both files and other directories
- every directory contains at least two entries: .(dot), a link to the directory itself, and ..(dot-dot), which is a link to the above it in the directory hierarchy aka it's parent.
- Except, the root directory does not have a parent it's .. relates to itself

### Symbolic links

- the filename referenced by the symbolic link's pointer is known as it's target
- A symbolic link will "point" or "refer" to a target file
- The kernel will automatically resolve a symbolic link used in a system call to it's target

### Filenames

- Normally up to 255 characters long
- may contain any characters except slashes (\) and null characters (\0)
- The SUSV3 compliant names may only contain `[-._a-zA-Z0-9]`
- Do not begin filenames with hyphens

### Pathnames

- String Consisting of an optional inital slash `/` followed by a series of filenames separted by slashes. Ex:
  - `/this/is/an/example/absolute/path`
  - `this/is/an/example/relative/path`
- Each of the component filenames identifies a directory or symbolic link that resolves to a directory
- The last component of the path may identify any type of file

### Current Working Directory

- The current location of a process in the single directory hierarchy
- This is used to derive the relative path for a process
- A process inherits its current workind directory from its parent process

### File Permissions

- Each file has an associated user ID and group ID that define the owner of the file and the group to which it belongs.
- The three categories of users that access files:
  1. The owner of the file - also called the **user**
  2. Users who are members of the group matching the file's group ID (**group**)
  3. The rest of the world (**other**)
- Three permission bits may be set for each category of user, making a total of 9 permission bits per any one file. These bits have different meanings for directories as opposed to other file types.

- Here are the meanings of the permissions for all **non-directory file-types**

  1. **read** - allows the content of the file to be read
  2. **write** - allows for modification of the contents of the file
  3. **execute** - allows execution of the file, which should be either a program or script to be processed by some interpreter(like the shells)

- Here are the meanings of the permissions for all **Directory file-types**

  1. **read** - allows the filenames in the directory to be listed
  2. **write** - allows the filenames to be added removed or changed
  3. **execute/search** - allows access to files within the directory(subject to the permissions on the files themselves)

## File I/O Model

- In linux, the same system calls are used to perform I/O on all types of files, including devices
- The kernel translates the app's I/O requests to the appropriate filesystem or device-driver operations that perform I/O on the target file or device
- The kernel essentially provides one file-type: a sequential stream of bytes
- UNIX systems have no end-of-file character; the end of afile is detected by a read that returns no data

### File Descriptors

- Usually A small, non-negative Integer
- Obtained by a call to `open()`
- A process inherits three open file descriptors when it is started by the shell

  0 - standard input

  1 - standard output

  2 - standard error

- In an interactive shell these are normally connected to the terminal as opposed to in the `stdio` library

## Process

- When a program is loaded as a process, the kernel will:
  - load the code of the program into virtual memory
  - allocate space for program variables
  - setup kernel bookkeeping data structures about the process
    - process ID
    - Termination status
    - User IDs
    - Group IDs
- How the kernel allocates some of the various computer resources to processes:
  - Limited resources - like memory:
    - The kernel initally allocates some amount of the resource to the process
    - The kernel will adjust the allocation of the resource over time in response to the demands of the process and overall system demand for the resource
    - The kernel then releases all of these types of resources for use by other processes when the process stops
  - "Renewable resources" - Like CPU, network bandwith:
    - These are shared equitably among all processes

### Process memory layout

The four process segments:

- **Text** - the instructions of the program
- **Data** - the static variables used by the program
- **Heap** - An area from which programs can dynamically allocate extra memory.
- **Stack** - A piece of memory that grows and shrinks as functions are called and exited. Used to allocate storage for local variables and function call linkage information.

### Process creation and program execution

- A process can create a new process using the `fork()` system call.
  - The process that invokes `fork()` is known as the parent process
  - The new process is known as the child process.
  - The kernel creates the child process by duplicating the parent process
  - Then, the child process inherits copies of all the parent's segments except the text.
    - The text is placed in memory as read only and is shared by the two processes.
  - The child process will do one of the following
    - execute a different set of functions in the same code as the parent
    - use the `execve()` system call
      - `execve` has several C standard library function layered on top of it.
      - The book uses `exec()` to refere to these functions in general
      - Note: that C has no actual `exec()` interface

### Process ID and
