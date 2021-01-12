#!/bin/bash
sed -n "2~2p" | cut -d: -f 1  | rev | sort -r | head -n "$MY_LINE1" | tail -n $(($MY_LINE1-$MY_LINE2+1)) | sed "s/$/, /g" | tr -d '\n' | sed "s/, $/.\n/"
exit 0
