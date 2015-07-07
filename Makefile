#########################################################
# File: Makefile
# # Description: A makefile for CS325 Project 1.
# #########################################################

CXX = gcc

SRC1 = enumeration.c
SRC2 = betterenum.c
SRC3 = divideandconquer.c
SRC4 = lineartime.c
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4}

PROG1 = enum 
PROG2 = betterenum 
PROG3 = dandc
PROG4 = lineartime
PROGS = ${PROG1} ${PROG2} ${PROG3} ${PROG4}

all: program1 program2 program3 program4

program1: ${SRC1}
	gcc -o ${PROG1} ${SRC1} 

program2: ${SRC2}
	gcc -o ${PROG2} ${SRC2} 

program3: ${SRC3}
	gcc -o ${PROG3} ${SRC3}

program4: ${SRC4}
	gcc -o ${PROG4} ${SRC4} 

clean:
	rm -rf ${PROGS}
