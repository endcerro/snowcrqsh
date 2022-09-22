#!/bin/bash

while true
do
    ln -sf /home/user/level10/token /tmp/link
    echo 'token on'
    ln -sf /tmp/mpty /tmp/link
    echo 'token offf'
done