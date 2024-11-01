export PROG="TAB"

g++ ${PROG}.cpp -std=c++20 -O2 -Wall -Wconversion -Wfatal-errors -fsanitize=undefined,address -o ${PROG}
./${PROG}
rm -rf ${PROG}