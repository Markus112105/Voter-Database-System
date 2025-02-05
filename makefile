COURSE = cs310
SEMESTER = fall2024
CP_NUMBER = 4
LASTNAME = Team
GITUSERID = 11
EXE = lets_vote 

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = ../CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g -std=c++20
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/Voter.o $(OBJ)/driver.o $(OBJ)/BST.o $(OBJ)/Heap.o $(OBJ)/List.o
	$(CC) $(FLAGS) $(OBJ)/Voter.o $(OBJ)/List.o $(OBJ)/BST.o $(OBJ)/Heap.o \
		$(OBJ)/driver.o -o $@

$(OBJ)/Voter.o: Voter.cpp Voter.h
	$(CC) $(FLAGS) -c Voter.cpp -o $@

$(OBJ)/BST.o: BST.cpp BST.h Voter.h
	$(CC) $(FLAGS) -c BST.cpp -o $@

$(OBJ)/Heap.o: Heap.cpp Heap.h Voter.h
	$(CC) $(FLAGS) -c Heap.cpp -o $@

$(OBJ)/List.o: List.cpp List.h Voter.h
	$(CC) $(FLAGS) -c List.cpp -o $@

$(OBJ)/driver.o: driver.cpp BST.h Heap.h List.h Voter.h
	$(CC) $(FLAGS) -c driver.cpp -o $@


tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)
	@echo "Tarred and gzipped file is in the directory one level up"
	@echo $(TARFILE)".gz"

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
