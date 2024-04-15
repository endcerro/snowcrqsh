# Snowcrash02

Ah so this time we have stuff

```bash
level02@SnowCrash:~$ ls -l
total 12
----r--r-- 1 flag02 level02 8302 Aug 30  2015 level02.pcap
```

Pcap is a format describing a network capture, so we can pull out good old wireshark and load it in

```bash
scp -P 6969 level02@localhost:~/level02.pcap ./level02.pcap
chmod 644 ./level02.pcap
wireshark ./level02.pcap
```
The packets by themselves aren't that useful but there is interesting data in packet 43 and 91, so there is probably somthing good in between

Wireshark is a really powerful and versatile tool, and we have an option to follow the TCP stream in order to view the content without the stuff that isnt interesting and yep this seems promising

While viewing in a hex format, we can fill the gaps and get the password for the flag account