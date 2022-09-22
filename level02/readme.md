# Snowcrash02

There's a .pcap file in our home
That's a network trace, let's open it in wireshark
Analyze -> Follow -> Follow TCP stream
We find the string 
```sh
ft_wandr...NDRel.L0L
```
Looking in binary format we understant that the dots are backspaces
So it gives us

```sh
ft_waNDReL0L
```

And here it is