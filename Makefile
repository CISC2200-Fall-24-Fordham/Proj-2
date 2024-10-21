CXX := g++
CXXFLAGS := -O0 -g -Wall -std=c++20 -Werror=return-type

%.out: %.cpp
	@$(CXX) $(CXXFLAGS) $^ BigInt.cpp Calculator.cpp Transformer.cpp -o $@

main: main.out
	./$<

test: test.out
	./$< -tc="$(TC)" -sc="$(SC)"

check: Calculator.cpp BigInt.cpp Transformer.cpp
	@dos2unix $^ > /dev/null 2>&1
	@echo "Suggestions are for reference only ..."
	@cppcheck --language=c++ --enable=style,warning --suppress=copyCtorAndEqOperator $^

clean:
	@rm -f *.out

all: clean test.out check test
