TARFILE = ../Michael_Zheng_C++.tar
REPODIR = ./*
ZIPFILE = ${TARFILE}.gz

all: submission

submission: submission.cpp
	g++ -o submission submission.cpp -std=c++11 -O3 -Wall -Wextra -Werror -pedantic
clean:
	rm -rf submission *.o output*.txt
test: submission
	rm -f output*.txt
	./submission input.txt output.txt
	./submission inputDuplicates.txt outputDuplicates.txt
	./submission inputNoAnswer.txt outputNoAnswer.txt
	./submission inputSimple.txt outputSimple.txt
	./submission inputZero.txt outputZero.txt

tar:	clean
	tar cvvf $(TARFILE) ${REPODIR}
	gzip $(TARFILE)
	@echo "Tarred and gzipped file is in the directory one level up"
	@echo $(ZIPFILE)