/*
 Assignment 6: Boggle
 
 Purpose: To search for all possible words in the Boggle Board
 
 Bugs or Concerns: The program doesnt print all of the possible words in the Boggle Board. However, it does print some.
 
 This program was tested with the sample files on Arup Guha's website.
 
Created by Luis Gamarra Jimenez on 11/17/15.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4
#define WORD 16

// constants for directional movement
const int DXSIZE = 8;
const int DX[] = {-1,-1,-1,0,0,1,1,1};
const int DY[] = {-1,0,1,-1,1,-1,0,1};

struct trie {
	
	int isWord;
	struct trie* next[26];
	
};

// function prototypes
struct trie* init();
void insert(struct trie* tree, char word[], int k);
int search(struct trie* tree, char word[], int k) ;
void freeDictionary(struct trie* tree);
char** createBoogleBoard ();
char** fillBoggleBoard(char** board);
void wordSearch(char** wordBoard, struct trie* dictionary);
void findWord(struct trie* dictionary, char** wordBoard, char* word, int** visitedArray, int xLocation, int yLocation);


int main(int argc, const char * argv[]) {
	
	int numWords, numGames, i, j;
	
	struct trie* myDictionary = init();
	
	// opens dictionary and scans for words
	FILE* ifp = fopen("dictionary.txt", "r");
	fscanf(ifp, "%d", &numWords);
	
	// Read in each word and insert it.
	for (i=0; i<numWords; i++) {
		char word[20];
		fscanf(ifp, "%s", word);
		insert(myDictionary, word, 0);
	}
	
	
	// scans for the number of games
	scanf("%d", &numGames);
	
	for (j = 0; j < numGames; j++) {
		// creates array for boogle board
		char** emptyBoggleBoard = createBoogleBoard();
		
		// fills the boggleBoard
		char** fillBoogleBoard = fillBoggleBoard(emptyBoggleBoard);
		
		// search for possible words in boggle board
		printf("Words for Game #%d:\n", j+1);
		wordSearch(fillBoogleBoard, myDictionary);
		
		printf("\n");
	}
	
	// closes dictionary file
	fclose(ifp);
	//frees memory used for dictionary trie
	freeDictionary(myDictionary);
	return 0;
	
}

// creates array to be used for Boggle board
char** createBoogleBoard (){
	
	int i, j;
	//allocates memory for grid array
	char** board = malloc(sizeof(char*) * SIZE);
	
	for (i=0; i < SIZE; i++) {
		// allocates memory for each column in grid array
		board[i] = malloc(sizeof(char) * SIZE);
		for (j=0; j<SIZE; j++){
			
		}
	}
	
	return board;
}

// fills the boggle board with the inputed character board
char** fillBoggleBoard(char** board){
	
	int i;
    // adds additional spot for null character
	char lineSet[SIZE+1];
	
    // loops through the board and saves input
	for (i = 0; i < SIZE; i++) {
		
		scanf("%s", lineSet);
		strcpy(board[i], lineSet);
		
	}
	
	return board;
	
}

// function used to find prefixes
void wordSearch(char** wordBoard, struct trie* dictionary){
	
	int a, b, i, j, x, y, d, bufferCounter = 0;
	
	int dxSize =  8;
	
	int** visited = malloc(sizeof(int*) * SIZE);
	for (a = 0; a < SIZE; a++) {
		visited[a] = malloc(sizeof(int) * SIZE);
		
	}
	
	// allocates memory for buffer array that will hold words found in adjacent locations
	char* buffer = malloc(sizeof(char) * (SIZE));
	
	for (i= 0;  i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			
			// chooses direction
			for (d = 0; d < dxSize; d++) {
				bufferCounter = 0;
				
				x = i;
				y = j;
				
				for (a = 0; a < SIZE; a++) {
					for (b = 0; b < SIZE; b++) {
						visited[a][b] = 0;
					}
				}
				
				// checks if current bounds are correct bounds
				while ((x >= 0 && x < SIZE) && (y >= 0 && y < SIZE)) {
					
					visited[x][y] = 1;
					// adds a null character to buffercounter + 1;
					buffer[bufferCounter +1] = '\0';
					//adds letter to buffer array
					buffer[bufferCounter] = wordBoard[x][y];
					// if the string length is 3, then it will call the findWord function
					if (strlen(buffer) == 3) {
						
						findWord(dictionary, wordBoard ,buffer, visited, x, y);
					}
					
					x += DX[d];
					y += DY[d];
					
					bufferCounter++;
					
					
				} // END OF WHILE LOOP
				
			} // END OF D FOR LOOP
		} // END OF J FOR LOOP
		
		
	} // END OF I FOR LOOP
	
	
} // END OF FUNCTION

// function used to find words in boggle board
void findWord(struct trie* dictionary, char** wordBoard, char* word, int** visitedArray, int xLocation, int yLocation){
	
	int check, i;
	
	int x, y;
	
	// newWord can be up to 16 characters long. The extra space is for the NULL character
	char* newWord = malloc(sizeof(char) * (WORD + 1));
	strcpy(newWord, word);
	
	long wordCounter;
	wordCounter = strlen(newWord);
	
	check = search(dictionary, word, 0);
	// if test contains 1, the string is printed
	if (check) {
		printf("%s\n", word);
	}
	
	for (i= 0;  i < DXSIZE; i++) {
		
		xLocation = x;
		yLocation = y;
		
		xLocation += DX[i];
		yLocation += DY[i];
		
		if ((xLocation >= 0 && xLocation < SIZE) && (yLocation >= 0 && yLocation < SIZE) && visitedArray[xLocation][yLocation] == 0) {
			newWord[wordCounter + 1] = '\0';
			//adds letter to buffer array
			newWord[wordCounter] = wordBoard[xLocation][yLocation];
			visitedArray[xLocation][yLocation] = 1;
			findWord(dictionary, wordBoard, newWord, visitedArray, xLocation, yLocation);
			
		}
		
		
	} // end of i for loop
	
	
} // end of function



struct trie* init() {
	
	// Create the struct, not a word.
	struct trie* myTree = malloc(sizeof(struct trie));
	myTree->isWord = 0;
	
	// Set each pointer to NULLL.
	int i;
	for (i=0; i<26; i++)
		myTree->next[i] = NULL;
	
	// Return a pointer to the new root.
	return myTree;
}

void insert(struct trie* tree, char word[], int k) {
	
	// Down to the end, insert the word.
	if (k == strlen(word)) {
		tree->isWord = 1;
		return;
	}
	
	// See if the next place to go exists, if not, create it.
	int nextIndex = word[k] - 'a';
	if (tree->next[nextIndex] == NULL)
		tree->next[nextIndex] = init();
	
	insert(tree->next[nextIndex], word, k+1);
}

int search(struct trie* tree, char word[], int k) {
	
	// Down to the end, insert the word.
	if (k == strlen(word))
		return tree->isWord;
	
	// If the next place doesn't exist, word is not a word.
	int nextIndex = word[k] - 'a';
	if (tree->next[nextIndex] == NULL)
		return 0;
	
	return search(tree->next[nextIndex], word, k+1);
}

// Just frees all the memory pointed to by tree (directly and indirectly)
void freeDictionary(struct trie* tree) {
	
	int i;
	for (i=0; i<26; i++)
		if (tree->next[i] != NULL)
			freeDictionary(tree->next[i]);
	
	free(tree);
}