SRC= ../src
OBJ= ../obj
INC= ../inc
BIN= ../bin
LOG= ../log_dir

CC= gcc
CFLAGS= -c -g -Wall -Werror
OFLAGS= -o
IFLAGS= -I$(INC)
COVFLAGS= -fprofile-arcs -ftest-coverage

VFLAGS = valgrind --tool=memcheck --log-file=val_log --leak-check=yes --show-reachable=yes <./exec_LSE>

all : $(BIN)/exec_LSE

$(BIN)/exec_LSE : $(OBJ)/logging_report.o $(OBJ)/crawl_dir.o $(OBJ)/match_pattern.o $(OBJ)/get_path_and_display.o $(OBJ)/open_entered_file.o $(OBJ)/trim_string.o $(OBJ)/main_interface.o 
	$(CC) $(COVFLAGS) $(OBJ)/logging_report.o $(OBJ)/crawl_dir.o $(OBJ)/match_pattern.o $(OBJ)/get_path_and_display.o $(OBJ)/open_entered_file.o $(OBJ)/trim_string.o $(OBJ)/main_interface.o $(OFLAGS) $(BIN)/exec_LSE

$(OBJ)/main_interface.o : $(SRC)/main_interface.c $(INC)/search_util.h
	$(CC)  $(CFLAGS) $(IFLAGS) $(COVFLAGS) $(SRC)/main_interface.c
	mv *.o $(OBJ)

$(OBJ)/trim_string.o: $(SRC)/trim_string.c $(INC)/search_util.h
	$(CC) $(CFLAGS) $(IFLAGS) $(COVFLAGS) $(SRC)/trim_string.c
	mv *.o $(OBJ)

$(OBJ)/crawl_dir.o: $(SRC)/crawl_dir.c $(INC)/search_util.h
	$(CC) $(CFLAGS) $(IFLAGS) $(COVFLAGS) $(SRC)/crawl_dir.c
	mv *.o $(OBJ)

$(OBJ)/match_pattern.o: $(SRC)/match_pattern.c $(INC)/search_util.h
	$(CC) $(CFLAGS) $(IFLAGS) $(COVFLAGS) $(SRC)/match_pattern.c
	mv *.o $(OBJ)

$(OBJ)/get_path_and_display.o: $(SRC)/get_path_and_display.c $(INC)/search_util.h
	$(CC) $(CFLAGS) $(IFLAGS) $(COVFLAGS) $(SRC)/get_path_and_display.c
	mv *.o $(OBJ)

$(OBJ)/open_entered_file.o: $(SRC)/open_entered_file.c $(INC)/search_util.h
	$(CC) $(CFLAGS) $(IFLAGS) $(COVFLAGS) $(SRC)/open_entered_file.c
	mv *.o $(OBJ)

$(OBJ)/logging_report.o: $(SRC)/logging_report.c $(INC)/search_util.h
	$(CC) $(CFLAGS) $(IFLAGS) $(COVFLAGS) $(SRC)/logging_report.c
	mv *.o $(OBJ)

clean:
	rm -f $(BIN)/exec_LSE $(OBJ)/*.o  $(LOG)/*.txt

