NB=100

while [seq $NB > test && shuf test > new_test && vim -c "argdo %s/\n/ /g | wq" new_test && ARG2=$(cat new_test) && ./push_swap $ARG2 > res && cat res | wc -l]
