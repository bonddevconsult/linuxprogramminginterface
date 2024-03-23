# linuxprogramminginterface

## Folder Structure
```
\_Chapter name
  \_chapter_summary.md
  \_Dockerfile
  \_hello.py
```

## Background

This repository is intended as a guide for working through the concepts presented in the book "The Linux Programming interface" The goal is to provide both a summary of the information provided and a working linux environment to test out the concepts presented

## Prerequisites

1. [Docker Desktop](https://docs.docker.com/desktop/) 
2. [Github](https://github.com/bonddevconsult/linuxprogramminginterface)
3. Some text editor(i.e, [vscode](https://code.visualstudio.com))

## Usage

1. Open a terminal. This can be done using your code editor or you can use shell provided to you by your laptop

2. clone this directory using the command: `git clone git@github.com:bonddevconsult/linuxprogramminginterface.git`

3. open the chapter you're working on: `cd ./linuxprogramminginterface/chapter1`. If you have a code editor, you still need to open the directory in your terminal even if you're already opened the `linuxprogramminginterface` when you opened your code editor. You just might need to do `cd ./chapter1` instead

4. run `docker build -t <chapter_name>:latest .` to build your dev environment. This will overwrite whatever other build you have tagged as latest for the chapter

5. open docker and start a container using the we just built.
