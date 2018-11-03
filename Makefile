p04: Knight.o Player.o Weapon.o Name.o Random.o p04.o
	rm -rf build
	mkdir build
	g++ Knight.o Player.o Weapon.o Name.o Random.o p04.o -o ./build/p04
	make clean

clean:
	@rm -f $(PROGRAMS) *.o core