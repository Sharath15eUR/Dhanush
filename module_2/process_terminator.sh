#!/bin/bash

# Find the process with the highest memory usage
highest_mem_pid=$(ps --sort=-%mem -eo pid | head -2 | tail -1)

# Terminate the process
if [ -n "$highest_mem_pid" ]; then
    kill -9 "$highest_mem_pid"
    echo "Process with PID $highest_mem_pid was terminated."
else
    echo "No process found."
fi

