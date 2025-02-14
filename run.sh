#!/bin/bash

# Collect all arguments except the script name
args="$@"

# Execute the command with the arguments
./push_swap $args | ./visualiser.py $args