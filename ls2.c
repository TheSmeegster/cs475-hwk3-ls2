#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ls2.h"



// TODO: function definitions here for ls2
void readDIR(char* path){

    //Directory location pointer
    DIR *loc;
	struct dirent *dir;

    //Opens corresponding directory and runs if it is an actual location
	loc = opendir(path);
	if(loc){
        
        //Runs while there are still files to be read
		while((dir = readdir(loc)) != NULL){

            //Prints out the size if path leads to a file and not a direcotry (WIP)
            if(dir->d_type != DT_DIR){

                //This is supposed to get the size of the file, doesn't work though
                struct stat st;
                stat(dir, &st);
                off_t size = st.st_size;

                printf("size : %li, file : ", size);//Replace with size

            } else {
                //If path points to a directory, runs through again on that path
                if(dir->d_type == DT_DIR && strcmp(dir->d_name, ".") || strcmp(dir->d_name, "..")){
                    printf("directory : ");
                    char newPath[257];

                    //Runs through again using new directory path
                    sprintf(newPath, "%s %s", path, dir->d_name);
                    readDIR(newPath);
                }
            }
            //Prints out the name of the accessed file
            printf("%s\n", dir->d_name);
		}
        //Closes directory when done
        closedir(loc);
	}
};
