# Snowcrash13

Classic

```sh
level13@SnowCrash:~$ ls -l
total 8
-rwsr-sr-x 1 flag13 level13 7303 Aug 30  2015 level13
```
When launched the app tells you that you need a different uid. Seems fine to me.

Let's break at 0x0804859a and see

```(gdb)b *0x08048595
(gdb)r
(gdb)stepi
(gdb)finish
(gdb)set $eax = 4242
(gdb)continue
your token is REDACTED
(gdb)
```
Nice
