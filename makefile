
cc=gcc
CC=g++
cpp_flags=-g
link_flags=
include_path=-I/home/lishen/Compile/include/pcre -I/home/lishen/Compile/include
lib_path=-L/home/lishen/Compile/lib
libs=-lpcrecpp -lgtest -lpthread
objects=FormulaParser.o StrUtils.o Token.o TokenArray.o TokenStack.o
#objects=StrUtils.o Token.o TokenArray.o TokenStack.o
main_objs=main.o
test_objs=test_main.o

excel : $(objects) $(main_objs)
	$(CC) -o excel $(link_flags) $(lib_path) $(libs) $(objects) $(main_objs)

test: $(objects) $(test_objs)
	$(CC) -o test_excel $(link_flags) $(lib_path) $(libs) $(objects) $(test_objs)
	./test_excel

$(objects) $(main_objs) $(test_objs) : %.o: %.cpp 
	$(CC) -c $(include_path) $(cpp_flags) $< 

token: Token.o
array: TokenArray.o
stack: TokenStack.o

.PHONY : clean
clean :
	-rm excel test_excel $(objects) $(main_objs) $(test_objs) output *~ 2>/dev/null

