
#!/bin/bash

# check if an argument is provided
if [ -z "$1" ]; then
  echo "Usage: ./script.sh <id de l'algorithme>"
  exit 1
fi

# get the number of executions from the first argument
n="$1"

# execute tron 100 times
t=0
for i in $(seq 1 100);
do
    # ./tron 10 1 5 3 2 0 0 2 4
    # get the time of execution
    time=$( { time -p ./tron 10 $n 5 $n 5 $n 5 $n 5 $n 5; } 2>&1 | grep real | awk '{print $2}' | tr ',' '.')
    t=$(bc -l <<< "$t + $time")
done
average=$(bc -l <<< "$t / 100")
echo "Average time: $average"
