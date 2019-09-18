#!/bin/bash
if [ -z "$(norminette -v 2>&1 | grep 'command not found')" ]; then
    NORMOUTPUT=$(norminette $1 | grep -B 1 'Error\|Warning')
fi
NORMPLUSOUTPUT=$(python ~/norminette+/run.py $1 Makefile | grep -B 1 'Error')

if [ -n "$NORMOUTPUT" ] || [ -n "$NORMPLUSOUTPUT" ]; then
    echo "$NORMOUTPUT"
    echo "$NORMPLUSOUTPUT"
    exit 255
fi
exit 0
