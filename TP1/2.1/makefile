run: myprog.hello
	./$<

myprog.hello: myfirstprogram.o
	gcc -o $@ $<

myfirstprogram.o: myfirstprogram.c
	gcc -c $<

clean:
	rm myfirstprogram.o myprog.hello