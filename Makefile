gcc = g++ -std=c++17 -Wall -Werror -Wextra

all: test

clean:
	rm -rf *.o test_exec *.a *.gc* report *.info a.out gcov_report

test: Controller.a
	$(gcc) test.cpp Controller.a -lgtest -lgtest_main -lpthread -o test_exec 
	./test_exec

Controller.a: Controller.o
	ar rcs Controller.a *.o

Controller.o: Controller.h
	$(gcc) -c *.cpp 

gcov_report: clean
	$(gcc) --coverage -lgtest_main *.cpp -o gcov_report -lgtest -lstdc++
	./gcov_report
	lcov -t "stest" -o unit_test.info -c -d .
	genhtml -o report unit_test.info
	open ./report/index.html

style:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.cc *.h
	clang-format -n *.cc *.h
	rm .clang-format