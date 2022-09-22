# Snowcrash01

Empty home again, let's do this  
Let's try and find some files
```sh
level01:~$ find / -user flag01 2> /dev/null
```
Ok so there's none this time, is there something is passwd ?
```sh
level01:~$ cat /etc/passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```
Interesting, while other accounts have a x flag 
```sh
flag13:x:3013:3013::/home/flag/flag13:/bin/bash
```
Seems like we can do something with this string  
John on kali linux takes care of that, copy the file over there
```sh
kali:~$ john ./passwd --show
level01:abcdefg:3001:3001::/home/flag/flag01:/bin/bash
```
There it is