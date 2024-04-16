# Snowcrash14

This time we have nothing that I could find in the home or anywhere for level and flag acounts

Let's take a look at getflag i guess

```bash
~$ ltrace getflag
ptrace(0, 0, 1, 0, 0)= -1
puts("You should not reverse this"You should not reverse this)= 28
+++ exited (status 1) +++
```

I should not ? But i can right ?

Looking at gdb we can see a bunch of ft_des calls in the main function, it takes a string as input and returns one. Considering it was used in the main from the previous level, it seems clear to me that this is the function responsible for giving us the flags.

We can copy the ft_des function from ghicdra, make it compile, and feed it all of its input from main

And indeed we get all the flags from all the levels, if only i knew this earlier lol