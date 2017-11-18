main:
	cc src/cat.c -o src/cat
clean:
	rm src/cat
install:
	mkdir -p ../../prg/cat-0.0.1/
	cp src/cat ../../prg/cat-0.0.1/
	ln -s $(pwd)/src/cat ../../../bin/ 
uninstall:
	rm -rf ../../prg/cat-0.0.1/
