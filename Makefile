#########################################################
# File: Makefile
# # Description: A makefile for CS325 Project 1.
# #########################################################

CXX = gcc -std=c99 

SRC1 = enumeration.c
SRC2 = betterenum.c
SRC3 = divideandconquer.c
SRC4 = lineartime.c
SRC5 = filefunctions.c
SRC6 = timing.c

PROG1 = enum 
PROG2 = betterenum 
PROG3 = dandc
PROG4 = lineartime
PROG6 = timing
PROGS = ${PROG1} ${PROG2} ${PROG3} ${PROG4} ${PROG6}

HEADER1 = filefunctions.h
HEADERS = ${HEADER1}

all: program1 program2 program3 program4 program6

program1: ${SRC1}
	${CXX} ${SRC1} ${SRC5} ${HEADERS} -o ${PROG1}  

program2: ${SRC2}
	${CXX} ${SRC2} ${SRC5} ${HEADERS} -o ${PROG2}  

program3: ${SRC3}
	${CXX} ${SRC3} ${SRC5} ${HEADERS} -o ${PROG3}  

program4: ${SRC4}
	${CXX} ${SRC4} ${SRC5} ${HEADERS} -o ${PROG4}  

program6: ${SRC5}
	${CXX} ${SRC6} ${SRC5} ${HEADERS} -o ${PROG6}

clean:
	rm -rf ${PROGS} MSS_Results.txt
