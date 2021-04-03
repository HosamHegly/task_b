.PHONY: all
all: task1  task2 task3 task4

task1: main2_1.c 
	gcc -o main2_1 main2_1.c

task2: main2_2.c 
	gcc main2_2.c -o main2_2

task3: main2_3.c 
	gcc main2_3.c  -o main2_3

task4: main2_4.c
	gcc main2_4.c -o main2_4 


.PHONY: clean
clean: 
	-rm main2_1 main2_2 main2_3 main2_4 
