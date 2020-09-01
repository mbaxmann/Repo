#!bin/sh

EXEC=./Cub3D
ARGS=./map2.cub
SAVE=--save
valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --log-file=valgrin.log --track-origins=yes ./$EXEC $ARGS #$SAVE
grep -A1 "valgrind" valgrin.log | grep $EXEC
