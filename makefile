CC=g++
CFLAGS=-I.
DEPS = fileReader.h
OBJ = fileReader.o friendDBCli.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

friendDBCli: $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

clean:
	rm *.o friendDBCli
