# Snowcrash10

Mandatory part done, hopefully it gets spicy
This time we have a suid binary and a token which we can't access


```sh
level10@SnowCrash:~$ ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
```

After inspecting the binary it seems that the app wants to connect to a host on port 6969

So let's write a dirty server...done
Let it run on the client

We still can't open the token even if we bypass the syscall access check
While looking at documentation on access , it came clear that this piece is exploitable, and how to right here :
https://stackoverflow.com/questions/7925177/access-security-hole

We need to have one link pointing to one file we own so that checks are ok and then getting the proper file.

Stepping in with GDB doesn't seem to do the trick, i assume it is because i changed the link after the end of the access call and not during

What does work is doing it very fast a lot of time and you're bound to get a hit.
Let's do this in three parts
	- changing the link value
	- launching the executable untill we get the flag
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
