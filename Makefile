CC_FLAGS=-std=c++11
all: create_bin create_binaries create_executable
	$(info Successfully Done.)

create_executable:
	g++  $(CC_FLAGS) -I src/headers bin/bf_messages.o bin/bf_tokenizer.o bin/bf_executor.o bin/bf_engine.o src/interpretor.cpp -o bin/interpretor

create_binaries:
	g++ $(CC_FLAGS) -I src/headers -c src/lib/bf_messages.cpp -o bin/bf_messages.o
	g++ $(CC_FLAGS) -I src/headers -c src/lib/bf_tokenizer.cpp -o bin/bf_tokenizer.o
		g++ $(CC_FLAGS) -I src/headers -c src/lib/bf_executor.cpp -o bin/bf_executor.o
	g++ $(CC_FLAGS) -I src/headers -c src/lib/bf_engine.cpp -o bin/bf_engine.o

create_bin:
	mkdir bin

clean:
	rm -r bin
