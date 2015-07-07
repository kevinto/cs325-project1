#########################################################
# File: Makefile
# # Description: A makefile for CS325 Project 1.
# #########################################################

CXX = gcc

SRC1 = enumeration.c
SRC2 = betterenum.c
SRC3 = divideandconquer.c
SRC4 = lineartime.c
SRC5 = filefunctions.c

PROG1 = enum 
PROG2 = betterenum 
PROG3 = dandc
PROG4 = lineartime
PROGS = ${PROG1} ${PROG2} ${PROG3} ${PROG4}

HEADER1 = filefunctions.h
HEADERS = ${HEADER1}

all: program1 program2 program3 program4

program1: ${SRC1}
	gcc ${SRC1} ${SRC5} ${HEADERS} -o ${PROG1}  

program2: ${SRC2}
	gcc ${SRC2} ${SRC5} ${HEADERS} -o ${PROG2}  

program3: ${SRC3}
	gcc ${SRC3} ${SRC5} ${HEADERS} -o ${PROG3}  

program4: ${SRC4}
	gcc ${SRC4} ${SRC5} ${HEADERS} -o ${PROG4}  

clean:
	rm -rf ${PROGS}
