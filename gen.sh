 seq $NB > test && shuf test > new_test && ARG=$(cat new_test) &&  vim -c "argdo %s/\n/ /g | wq" new_test
