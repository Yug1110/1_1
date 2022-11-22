default:
	gcc first.c -lpthread
	./a.out
	python3 hist.py
