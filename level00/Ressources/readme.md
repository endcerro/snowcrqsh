# Snowcrash00

In this first level so nothing evident
Let's try and find some files that we own
```bash
~$ find / -user level00 2> /dev/null | grep -v dev | grep -v proc
```
But if we look at the flag user we get some interesting stuff
```sh
~$ cat /usr/sbin/john ; cat /rofs/usr/sbin/john
cdiiddwpgswtgt
cdiiddwpgswtgt
```

Safe to say that looks like our flag, but it doesn't work
The file is a readonly file that is located in a directory where binaries are supposed to be. A quick search for "john linux" reveals us that there is a password cracking tool of the same name : https://fr.wikipedia.org/wiki/John_the_Ripper | https://www.openwall.com/john/

We can install this tool in a docker container and see if it helps to decipher the password (see Dockerfile)

John needs a file, so we retrieve the content and give it to john

```bash
~$ docker build . -t kali
~$ docker run -v $(pwd):/dockermount -it --rm kali
┌──(root㉿88f4e5b50056)-[/]
└─ echo "cdiiddwpgswtgt" > john.txt ; john ./john.txt
    Created directory: /root/.john
    Using default input encoding: UTF-8
    No password hashes loaded (see FAQ)
```
No luck at this point. John is supposed to be used to crack hashes by using dictionaries. We could try to add more than default dictionaries but it seems far fetched.

What if it's not encrypted ? Encryption and encoding isnt the same thing so let's try and look on the other side.

https://www.cachesleuth.com/multidecoder/ is a pretty good website that turns out to be useful