TRGDIR=.
OBJ=./obj
SRC=./src
INC=./inc
TESTS=./tests
TBIN=./tests/bin
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/test_arytm_zesp
	${TRGDIR}/test_arytm_zesp  latwy

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyka.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyka.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: ${SRC}/main.cpp inc/LZespolona.hh inc/BazaTestu.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o ${SRC}/main.cpp

${OBJ}/LZespolona.o: ${SRC}/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/LZespolona.o ${SRC}/LZespolona.cpp

${OBJ}/BazaTestu.o: ${SRC}/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o ${SRC}/BazaTestu.cpp

${OBJ}/WyrazenieZesp.o: ${SRC}/WyrazenieZesp.cpp inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o ${SRC}/WyrazenieZesp.cpp

${OBJ}/Statystyka.o: ${SRC}/Statystyka.cpp inc/Statystyka.hh
	g++ -c ${FLAGS} -o ${OBJ}/Statystyka.o ${SRC}/Statystyka.cpp

${TBIN}/test_1: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_1 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test1.cpp ${OBJ}/LZespolona.o

${TBIN}/test_2: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_2 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test2.cpp ${OBJ}/LZespolona.o

${TBIN}/test_3: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_3 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test3.cpp ${OBJ}/LZespolona.o

${TBIN}/test_4: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_4 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test4.cpp ${OBJ}/LZespolona.o

${TBIN}/test_5: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_5 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test5.cpp ${OBJ}/LZespolona.o
	
${TBIN}/test_6: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_6 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test6.cpp ${OBJ}/LZespolona.o

${TBIN}/test_7: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_7 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test7.cpp ${OBJ}/LZespolona.o

${TBIN}/test_8: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_8 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test8.cpp ${OBJ}/LZespolona.o

${TBIN}/test_9: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_9 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test9.cpp ${OBJ}/LZespolona.o

${TBIN}/test_10: ${TBIN} ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o 
	g++ -o ${TESTS}/bin/test_10 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test10.cpp ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o

${TBIN}/test_11: ${TBIN} ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o 
	g++ -o ${TESTS}/bin/test_11 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test11.cpp ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o

${TBIN}/test_12: ${TBIN} ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o 
	g++ -o ${TESTS}/bin/test_12 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test12.cpp ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o

${TBIN}/test_13: ${TBIN} ${OBJ}/Statystyka.o
	g++ -o ${TESTS}/bin/test_13 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test13.cpp ${OBJ}/Statystyka.o

${TBIN}/test_14: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_14 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test14.cpp ${OBJ}/LZespolona.o

${TBIN}:
	mkdir ${TBIN}

test:  ${TBIN}/test_1 ${TBIN}/test_2 ${TBIN}/test_3 ${TBIN}/test_4 ${TBIN}/test_5 ${TBIN}/test_6 ${TBIN}/test_7 ${TBIN}/test_8 ${TBIN}/test_9 ${TBIN}/test_10 ${TBIN}/test_11 ${TBIN}/test_12 ${TBIN}/test_13 ${TBIN}/test_14
	${TBIN}/test_1 
	${TBIN}/test_2
	${TBIN}/test_3
	${TBIN}/test_4
	${TBIN}/test_5
	${TBIN}/test_6
	${TBIN}/test_7
	${TBIN}/test_8
	${TBIN}/test_9
	${TBIN}/test_10
	${TBIN}/test_11
	${TBIN}/test_12
	${TBIN}/test_13
	${TBIN}/test_14

run:
	${TRGDIR}/test_arytm_zesp latwy

clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/* ${TBIN}/*
