# Default target
.DEFAULT_GOAL := r_chess


#Variables
SOURCE_PATH = ./
COMPILE_PATH = ./
OPTIONS = gcc -Wall -std=c11


##################### Generate object files ##################### 
# Target for r_chess.o
r_chess.o: r_chess.c
	$(OPTIONS) -c $(SOURCE_PATH)r_chess.c -o $(COMPILE_PATH)r_chess.o

# Target for UI.o
UI.o: UI.c
	$(OPTIONS) -c $(SOURCE_PATH)UI.c -o $(COMPILE_PATH)UI.o

# Target for ChessPiece.o
ChessPiece.o: ChessPiece.c
	$(OPTIONS) -c $(SOURCE_PATH)ChessPiece.c -o $(COMPILE_PATH)ChessPiece.o

# Target for Game.o
Game.o: Game.c
	$(OPTIONS) -c $(SOURCE_PATH)Game.c -o $(COMPILE_PATH)Game.o

# Target for Rules.o
Rules.o: Rules.c
	$(OPTIONS) -c $(SOURCE_PATH)Rules.c -o $(COMPILE_PATH)Rules.o

# Target for Move.o
Move.o: Move.c
	$(OPTIONS) -c $(SOURCE_PATH)Move.c -o $(COMPILE_PATH)Move.o

# Target for Move.o
AI.o: AI.c
	$(OPTIONS) -c $(SOURCE_PATH)AI.c -o $(COMPILE_PATH)AI.o

# Target for Move.o
MoveList.o: MoveList.c
	$(OPTIONS) -c $(SOURCE_PATH)MoveList.c -o $(COMPILE_PATH)MoveList.o

# Target for Log.o
Log.o: Log.c
	$(OPTIONS) -c $(SOURCE_PATH)Log.c -o $(COMPILE_PATH)Log.o

##################### Generate the executable ###################
# Target for r_chess
r_chess: r_chess.o UI.o ChessPiece.o Game.o Rules.o Move.o AI.o MoveList.o Log.o
	$(OPTIONS) $(COMPILE_PATH)r_chess.o $(COMPILE_PATH)UI.o $(COMPILE_PATH)ChessPiece.o $(COMPILE_PATH)Game.o $(COMPILE_PATH)Rules.o $(COMPILE_PATH)Move.o $(COMPILE_PATH)AI.o $(COMPILE_PATH)MoveList.o $(COMPILE_PATH)Log.o -o r_chess
	
	rm -f $(COMPILE_PATH)r_chess.o
	rm -f $(COMPILE_PATH)UI.o
	rm -f $(COMPILE_PATH)ChessPiece.o
	rm -f $(COMPILE_PATH)Game.o
	rm -f $(COMPILE_PATH)Rules.o
	rm -f $(COMPILE_PATH)Move.o
	rm -f $(COMPILE_PATH)AI.o
	rm -f $(COMPILE_PATH)Log.o
	rm -f $(COMPILE_PATH)MoveList.o
	rm -f log.txt

##################### Otehr functions ###########################
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
	rm -f log.txt
	rm -f $(COMPILE_PATH)r_chess
