# Snowcrash14

Finally

This time we have nothing that I could find.  
Let's reverse getflag i guess ?

```sh
level14:~$ gdb getflag
(gdb)b *0x08048b0a
(gdb)b *0x08048989
(gdb)r
(gdb)stepi
(gdb)finish
(gdb)set $eax = 0
(gdb)c
(gdb)set $eax = 3014
(gdb)c
Check flag.Here is your token : REDACTED
```

Tadaaaaa