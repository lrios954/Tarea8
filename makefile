a.out: main.c
	@cc main.c -lm
	@./a.out
	@python plot.py
	@cc main2.c -lm
	@./a.out
	@python plot2.py

all: a.out

clean: 
	@rm -f a.out
	@rm -f *.dat
	@rm -f *.jpg

