# Snowcrash13

Classic

```sh
level13@SnowCrash:~$ ls -l
total 8
-rwsr-sr-x 1 flag13 level13 7303 Aug 30  2015 level13
~$ ./level13 
UID 2013 started us but we we expect 4242
```

When launched the app tells you that you need a different uid, but as far as i know we can't change it.
Ltrace isnt helping, so we can try gdb and see.

A basic run shows the same output

We can see that after the getuid call, at 0x0804859a eax contains the UID 2013 but the programs wants 4242, fine with me


```(gdb)b *0x0804859a
(gdb)r
(gdb)set $eax = 4242
(gdb)c
your token is REDACTED
```
While we could think this is the flag account password it's for the leve14 one, but no sign of getflag, but calls to a ft_des function, weird
