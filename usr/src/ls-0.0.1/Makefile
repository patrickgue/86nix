main:
	cc src/ls.c -o src/ls -isysroot 
clean:
	rm src/ls
install:
	mkdir -p ../../prg/ls-0.0.1/
	cp src/ls ../../prg/ls-0.0.1/
	ln -s $(pwd)/src/cat ../../../bin/ 
uninstall:
	rm -rf ../../prg/ls-0.0.1/
