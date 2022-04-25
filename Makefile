#Variables
SOURCE_PATH = ./src/
COMPILE_PATH = ./bin/
OPTIONS = gcc -Wall -std=c11
CFLAGS = -g

# Default target
.DEFAULT_GOAL := $(COMPILE_PATH)r_chess


##################### Generate object files ##################### 
# Target for r_chess.o
$(COMPILE_PATH)r_chess.o: $(SOURCE_PATH)r_chess.c
	$(OPTIONS) $(CFLAGS) -c $(SOURCE_PATH)r_chess.c -o $(COMPILE_PATH)r_chess.o

# Target for UI.o
$(COMPILE_PATH)UI.o: $(SOURCE_PATH)UI.c
	$(OPTIONS) $(CFLAGS) -c $(SOURCE_PATH)UI.c -o $(COMPILE_PATH)UI.o

# Target for ChessPiece.o
$(COMPILE_PATH)ChessPiece.o: $(SOURCE_PATH)ChessPiece.c
	$(OPTIONS) $(CFLAGS) -c $(SOURCE_PATH)ChessPiece.c -o $(COMPILE_PATH)ChessPiece.o

# Target for Game.o
$(COMPILE_PATH)Game.o: $(SOURCE_PATH)Game.c
	$(OPTIONS) $(CFLAGS) -c $(SOURCE_PATH)Game.c -o $(COMPILE_PATH)Game.o

# Target for Rules.o
$(COMPILE_PATH)Rules.o: $(SOURCE_PATH)Rules.c
	$(OPTIONS) $(CFLAGS) -c $(SOURCE_PATH)Rules.c -o $(COMPILE_PATH)Rules.o

# Target for Move.o
$(COMPILE_PATH)Move.o: $(SOURCE_PATH)Move.c
	$(OPTIONS) $(CFLAGS) -c $(SOURCE_PATH)Move.c -o $(COMPILE_PATH)Move.o

# Target for Move.o
$(COMPILE_PATH)AI.o: $(SOURCE_PATH)AI.c
	$(OPTIONS) $(CFLAGS) -c $(SOURCE_PATH)AI.c -o $(COMPILE_PATH)AI.o

# Target for Move.o
$(COMPILE_PATH)MoveList.o: $(SOURCE_PATH)MoveList.c
	$(OPTIONS) $(CFLAGS) -c $(SOURCE_PATH)MoveList.c -o $(COMPILE_PATH)MoveList.o

# Target for Log.o
$(COMPILE_PATH)Log.o: $(SOURCE_PATH)Log.c
	$(OPTIONS) $(CFLAGS) -c $(SOURCE_PATH)Log.c -o $(COMPILE_PATH)Log.o

##################### Generate the executable ###################
#Target for test
$(COMPILE_PATH)test: $(COMPILE_PATH)r_chess.o $(COMPILE_PATH)UI.o $(COMPILE_PATH)ChessPiece.o $(COMPILE_PATH)Game.o $(COMPILE_PATH)Rules.o $(COMPILE_PATH)Move.o $(COMPILE_PATH)AI.o $(COMPILE_PATH)MoveList.o $(COMPILE_PATH)Log.o
	$(OPTIONS) $(CFLAGS) $(COMPILE_PATH)r_chess.o $(COMPILE_PATH)UI.o $(COMPILE_PATH)ChessPiece.o $(COMPILE_PATH)Game.o $(COMPILE_PATH)Rules.o $(COMPILE_PATH)Move.o $(COMPILE_PATH)AI.o $(COMPILE_PATH)MoveList.o $(COMPILE_PATH)Log.o -o $(COMPILE_PATH)r_chess

# Target for r_chess
$(COMPILE_PATH)r_chess: $(COMPILE_PATH)r_chess.o $(COMPILE_PATH)UI.o $(COMPILE_PATH)ChessPiece.o $(COMPILE_PATH)Game.o $(COMPILE_PATH)Rules.o $(COMPILE_PATH)Move.o $(COMPILE_PATH)AI.o $(COMPILE_PATH)MoveList.o $(COMPILE_PATH)Log.o
	$(OPTIONS) $(CFLAGS) $(COMPILE_PATH)r_chess.o $(COMPILE_PATH)UI.o $(COMPILE_PATH)ChessPiece.o $(COMPILE_PATH)Game.o $(COMPILE_PATH)Rules.o $(COMPILE_PATH)Move.o $(COMPILE_PATH)AI.o $(COMPILE_PATH)MoveList.o $(COMPILE_PATH)Log.o -o $(COMPILE_PATH)r_chess
	
	rm -f $(COMPILE_PATH)r_chess.o
	rm -f $(COMPILE_PATH)UI.o
	rm -f $(COMPILE_PATH)ChessPiece.o
	rm -f $(COMPILE_PATH)Game.o
	rm -f $(COMPILE_PATH)Rules.o
	rm -f $(COMPILE_PATH)Move.o
	rm -f $(COMPILE_PATH)AI.o
	rm -f $(COMPILE_PATH)Log.o
	rm -f $(COMPILE_PATH)MoveList.o
	rm -f $(COMPILE_PATH)log.txt


##################### Other functions ###########################
# Target for clean-up
clean:
	rm -f $(COMPILE_PATH)r_chess.o
	rm -f $(COMPILE_PATH)UI.o
	rm -f $(COMPILE_PATH)ChessPiece.o
	rm -f $(COMPILE_PATH)Game.o
	rm -f $(COMPILE_PATH)Rules.o
	rm -f $(COMPILE_PATH)Move.o
	rm -f $(COMPILE_PATH)AI.o
	rm -f $(COMPILE_PATH)MoveList.o
	rm -f $(COMPILE_PATH)Log.o
	rm -f $(COMPILE_PATH)log.txt
	rm -f $(COMPILE_PATH)r_chess


#Target for tar
tar:
	tar -czvf ../Chess_V1.0_src.tar.gz .	
