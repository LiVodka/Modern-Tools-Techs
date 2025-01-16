#!/bin/bash

gcc Hello.c -o Hello

INPUT=(
    "fflush newline"
    "fflush"
    "newline"
    ""
)

OUTPUT_DIR="./outputs"
mkdir -p "$OUTPUT_DIR"

for i in "${!INPUT[@]}"; do
    ARGS=${INPUT[$i]}
    OUTPUT_FILE="$OUTPUT_DIR/test_$i.txt"

    ./Hello $ARGS > "$OUTPUT_FILE" 2>&1

    wait
done
