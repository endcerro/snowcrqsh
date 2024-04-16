# Snowcrash09

Again, binary and token

```bash
~$ ls -l
total 12
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token
~$ ltrace ./level09
ptrace(0, 0, 1, 0, 0xb7e2fe38)= -1
puts("You should not reverse this"You should not reverse this)= 28
+++ exited (status 1) +++
```
Is this bait or not ? It seems not to do anything whith ptrace enable, without we get some output

```bash
level09@SnowCrash:~$ cat token 
f4kmm6p|=�p�n��DB�Du{��
~$ ./level09 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
abcdefghijklmnopqrstuvwxyz{|}~�������
~$ ./level09 111111111111111
123456789:;<=>?

```
Ok so this is incrementing the value of the char by its index


```sh
level09@SnowCrash:~$ hexdump -C ./token
00000000  66 34 6b 6d 6d 36 70 7c  3d 82 7f 70 82 6e 83 82  |f4kmm6p|=..p.n..|
00000010  44 42 83 44 75 7b 7f 8c  89 0a                    |DB.Du{....|
0000001a
```
Maybe we can try reversing the effects since the token has non printable chars

See reverse.c

Go getflag