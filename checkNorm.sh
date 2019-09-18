#!/bin/bash
NORMOUTPUT=$($(which norminette) $1 | grep -B 1 'Error\|Warning')
NORMPLUSOUTPUT=$(python ~/norminette+/run.py $1 Makefile | grep -B 1 'Error')

if [ -n "$NORMOUTPUT" ] || [ -n "$NORMPLUSOUTPUT" ]; then
    echo "$NORMOUTPUT"
    echo "$NORMPLUSOUTPUT"
    exit 255
fi
exit 0
