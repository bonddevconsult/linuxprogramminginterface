## References

 - GCC official docker docs - https://hub.docker.com/_/gcc/

## USAGE

### This will build(compile) and run the app
`$ docker build -t my-gcc-app .`
`$ docker run -it --rm --name my-running-app my-gcc-app`


### Compile the app inside the Docker container, but do not run it
There may be occasions where it is not appropriate to run your app inside a container. To compile, but not run your app inside the Docker instance, you can write something like:

`$ docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 gcc -o myapp myapp.c`

This will add your current directory, as a volume, to the container, set the working directory to the volume, and run the command gcc -o myapp myapp.c. This tells gcc to compile the code in myapp.c and output the executable to myapp. Alternatively, if you have a Makefile, you can instead run the make command inside your container:

`$ docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 make`
