NB=100 && echo "Gen: " $NB;seq $NB > test && shuf test > new_test && vim -c "argdo %s/\n/ /g | wq" new_test && ARG2=$(cat new_test) && ./push_swap $ARG2 > res && wc -l res && cat res | grep OK
