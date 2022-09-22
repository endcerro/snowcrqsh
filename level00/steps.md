# Snowcrash00

In this first level, we're met with an empty home, nice
Let's try and find some files
```sh
level00:~$ find / -user flag00 2> /dev/null
/usr/sbin/john
rofs/usr/sbin/john
```
So the flag user has some files, let's look at them 
```sh
level00:~$ cat /usr/sbin/john ; cat /rofs/usr/sbin/john
cdiiddwpgswtgt
cdiiddwpgswtgt
```
Safe to say that looks like our flag, but it doesn't work
Logic got me trying random decode algos
(https://www.cachesleuth.com/multidecoder/)

First result gives us plain english, and that's flag00 in the pocket
