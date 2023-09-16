gcc = g++ -std=c++17 -Wall -Werror -Wextra
CFLAGS = -Wall -fprofile-arcs -ftest-coverage
all: test

clean:
	rm -rf *.o test_exec *.a *.gcda report *.gcno *.info a.out gcov_report

test: Controller.a
	$(gcc) -g test.cpp Model.cpp Controller.a -lgtest -lgtest_main -lpthread $(CFLAGS) -o test_exec 
	./test_exec

Controller.a: Controller.o
	ar rcs Controller.a *.o

Controller.o: Controller.h
	$(gcc) -c *.cpp 

gcov_report: clean test

	lcov -t "test_exec" -o test_exec.info --ignore-errors mismatch --no-external -c -d .
	genhtml -o report test_exec.info
	open ./report/index.html



style:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.cc *.h
	clang-format -n *.cc *.h
	rm .clang-format

