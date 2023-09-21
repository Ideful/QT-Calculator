gcc = g++ -std=c++17 -Wall -Werror -Wextra
CFLAGS = -Wall -fprofile-arcs -ftest-coverage

all: install

clean:
	rm -rf *.o test_exec *.a *.gcda report *.gcno *.info a.out gcov_report index latex

test: Controller.a
	$(gcc) -g test.cc Model.cc Controller.a -lgtest -lgtest_main -lpthread $(CFLAGS) -o test_exec 
	./test_exec

Controller.a: Controller.o
	ar rcs Controller.a *.o

Controller.o: Controller.h
	$(gcc) -c *.cc 

gcov_report: clean test
	lcov -t "test_exec" -o test_exec.info --ignore-errors mismatch --no-external -c -d .
	genhtml -o report test_exec.info
	open ./report/index.html

dvi:
	doxygen Doxyfile
	open html/index.html

install: uninstall
	mkdir app
	cp -r *.cc *.h QT/* app
	cd app/QT-Calculator && qmake QT-Calculator.pro && make
	# cd app && rm *.o *.c *.cpp *.h
	cp -r app/QT-Calculator/QT-Calculator.app ~/Desktop
	rm -rf app
	open ~/Desktop/

uninstall: 
	rm -rf app
	rm -rf ~/Desktop/QT-Calculator.app ~/Desktop/QT-Calculator.tar.gz

dist: uninstall install
	tar -cvzf ~/Desktop/QT-Calculator.tar.gz ~/Desktop/QT-Calculator.app

# style:
# 	cp ../materials/linters/.clang-format ./
# 	clang-format -i *.cpp *.cc *.h
# 	clang-format -n *.cc *.h
# 	rm .clang-format

