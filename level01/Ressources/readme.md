# Snowcrash01

Empty home again, and no files owened by our and the flag user.
Let's check the /etc/passwd file (https://www.cyberciti.biz/faq/understanding-etcpasswd-file-format/) as well as the /etc/shadow file.

In passwd we can see that the line regarding the flag account has something different that the others.

We cannot access shadow. While shadow is supposed to contain passwords in a secure manner, passwd has not been a proper way to store passwords, and yet we have something.

Still, the passwords in passwd are encrypted, not encoded, so maybe this time john will help ?

Ok so there's none this time, is there something is passwd ?
```sh
┌──(root㉿88f4e5b50056)-[/]
└─ echo "flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash" > passwd.txt ; john ./passwd.txt --show
flag01:abcdefg:3001:3001::/home/flag/flag01:/bin/bash

1 password hash cracked, 0 left
```
Very nice.