#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "error_handling.h"

#define DATAFILE "/var/chance.data" // File to store user data

struct user {
	int uid;
	int credits;
	int highscore;
	char name[100];
	int (*current_game)();
};

struct user player;

int main(void) {
	srand(time(0));	//Seed the randomizer with the current time.
	puts("Hello Game of Chance :D"); /* prints Hello Game of Chance :D */
	return EXIT_SUCCESS;
}



/*
 * This function reads the player data for the current uid
 * from the file. It returns -1 if it is unable to find player
 * data for the current uid
 * */
int get_player_data()
{
	int fd,uid,read_bytes;
	struct user entry ;

	uid = getuid();

	fd=open(DATAFILE,O_RDONLY);	//open file in read-only mode.
	if (fd == -1) return -1;

	read_bytes = read(fd,&entry,sizeof(struct user));	//read the 1st chunk.
	while (entry.uid != uid && read_bytes > 0)	//loop until we find the right user.
	{
		read_bytes = read(fd,&entry,sizeof(struct user)); //keep looping.
	}

	close(fd);
	if(read_bytes < sizeof(struct user)) // if true = we have reached the EOF.
		return -1;
	else player = entry;	//copy the read entry to the player struct.

	return 1;
}

// This is the new user registration function. 
// It will create a new player account and append it to the file.
void register_new_palyer ()
{
	
}
