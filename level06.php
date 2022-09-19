#!/usr/bin/php
<?php
function y($key)
{   $key = preg_replace("/\./", " x ", $key); //Replace . by x ?
    $key = preg_replace("/@/", " y", $key); //Repalce @ by y
    print "here";
    return $key;
}
function x($y, $z)
{
    $a = file_get_contents($y); //Fill the file in A
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
    $a = preg_replace("/\[/", "(", $a);
    $a = preg_replace("/\]/", ")", $a);
    return $a;
}
    $r = x($argv[1], $argv[2]);
    print $r;
?>
