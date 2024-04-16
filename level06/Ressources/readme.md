# Snowcrash06

This time we have a binary as well as a php file.
The binary does way too much call with ltrace for me to show them here



```
~$ ls -la ./level06
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 ./level06
~$ ./level06 a
PHP Warning:  file_get_contents(a): failed to open stream: No such file or directory in /home/user/level06/level06.php on line 4
```

So it seems that the ./level06 runs the level06.php file, considering it refers to it

It does a bunch of preg_replace calls that seem pretty basic, but there is one that stands out, with a /e, https://captainnoob.medium.com/command-execution-preg-replace-php-function-exploit-62d6f746bda4

This flag makes it possible to inject code to be executed here
It seems that the second argument is not important, and the first argument must be a filename so our exploit will be in this file

This website is pretty useful to understant wtf is going in in thoses regexes https://regex101.com/

So the bare minimum we need to escape is 
```text
[x command]             //This is allowing us to get our text back from the escape
[x shell_exec(ls)]      //This is it with something that should launch an ls
[x ${shell_exec(ls)}]   //This doesnt sit right with the y function and complains
[x {${shell_exec(ls)}}] //Add a bit more encapsulation and now it works. Note that you can add even more now and it'll still be ok
```

Again, we don't need to go into the flag account since the level06 binary has a suid