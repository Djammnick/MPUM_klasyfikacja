#!/bin/bash

SIZES=("5" "10" "15" "20" "25" "35" "50" "75" "100" "125" "150" "175" "200" "225" "250" "286" "300" "325" "350" "375" "400" "425" "457")
SEEDS=("10" "11" "12" "13" "14" "15" "16" "17" "18" "19" "20" "21" "22" "23" "24" "25")

for size in "${SIZES[@]}"; do
    for seed in "${SEEDS[@]}"; do
        echo "Executing with argument: $size $seed"
        ./prepare_data "$size" "$seed"
        ./prepare_classifiers "$size" "$seed"
        ./calculate_learn_error "$size" "$seed"
        ./calculate_test_error "$size" "$seed"
    done
done
./results

echo "Finished all tasks."