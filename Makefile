all:	comp

comp:	bin
	gcc -o bin/multibyte checker.c

bin:	
	mkdir bin

samp:
	./bin/multibyte samp_multibyte.c

clean:
	rm -rf *~

distclean:
	rm -rf *~
	rm -rf bin/
