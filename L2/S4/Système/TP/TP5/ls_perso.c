#define _DEFAULT_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//install libbsd and add -lbsd argument to compile
#include <bsd/string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>

int displayDir(char *path, const bool allStats);
void error(const size_t type);
char *timeConvert(const time_t time);
char *intToMonth(int month);
char *fullPath(const char *filePath, const char *fileName);

int main(int argc, char **argv){
	bool argL = false;
	if(argc > 2){
		error(0);
		return EXIT_FAILURE;
	}
	if(argc == 2){
		if(strcmp(argv[1],"-l") == 0){
			argL = true;
		}
		else{
			error(5);
			return EXIT_FAILURE;
		}
	}
	if(displayDir(".",argL) != 0){
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int displayDir(char *path, const bool allStats){
	DIR *dir = opendir(path);
	if(dir == NULL){
		error(3);
		return -1;
	}
	struct dirent *file = readdir(dir);
	if(file == NULL){
		error(2);
		return -1;
	}
	char *filePath;
	char mode[12];
	while(file != NULL){
		if(file->d_name[0] != '.'){
			if(allStats){
				filePath = fullPath(path,file->d_name);
				struct stat sb;
				if(stat(filePath,&sb) == -1){
					printf("Path = %s\n",filePath);//file path and name
					error(4);
					return -1;
				}
				strmode(sb.st_mode,mode);//convert octal mode to string
				printf("%s ",mode);//mode
				printf("%2ld ", (long) sb.st_nlink);//number of hard link
				printf("%4ld %4ld ",(long) sb.st_uid, (long) sb.st_gid);//user and group ID -> retireve user and group name ?
				printf("%8lld ",(long long) sb.st_size);//file size in bytes
				printf("%s ", timeConvert(sb.st_mtime));//last time modified -> format ignored, show month only with english locale
				printf("%s",file->d_name);//file name
				printf("\n");
				free(filePath);
			}
			else{
				printf("%s  ",file->d_name);
			}
		}
		file = readdir(dir);
	}
	printf("\n");
	closedir(dir);
	return 0;
}

void error(const size_t type){
	switch(type){
		case 0:{
			fprintf(stderr,"Error : too much arguments.\n");
		}
		break;
		case 1:{
			fprintf(stderr,"Error : multiple -l arguments forbidden.\n");
		}
		break;
		case 2:{
			fprintf(stderr,"Error : Unable to open file.\n");
		}
		break;
		case 3:{
			fprintf(stderr,"Error : Unable to open dir.\n");
		}
		break;
		case 4:{
			fprintf(stderr,"Error : Unable to read file's stats.\n");
		}
		break;
		case 5:{
			fprintf(stderr,"Error : Bad argument.\n");
		}
		break;
		default:;
	}
	fprintf(stderr,"Usage : ./ls_perso [-l]\n");
}

char *fullPath(const char *filePath, const char *fileName){
	size_t l = strlen(filePath);
	char *fullPath = calloc(l + strlen(fileName) + 1, sizeof(char));
	strcpy(fullPath, filePath);
	if(fullPath[l-1] != '/')strcat(fullPath,"/");
	strcat(fullPath,fileName);
	return fullPath;
}

char *timeConvert(const time_t time){
	struct tm *tm = localtime(&time);
	char *buf = calloc(20,sizeof(char));
	char *month = intToMonth(tm->tm_mon);
	sprintf(buf,"%s %2d %2d:%2d",month,tm->tm_mday,tm->tm_hour,tm->tm_min);
	return buf;
}

char *intToMonth(const int month){
	switch(month){
		case 0: return "Janvier";
		case 1: return "Fevrier";
		case 2: return "Mars";
		case 3: return "Avril";
		case 4: return "Mai";
		case 5: return "Juin";
		case 6: return "Juillet";
		case 7: return "Aout";
		case 8: return "Septembre";
		case 9: return "Octobre";
		case 10: return "Novembre";
		case 11: return "Decembre";
		default: return "Unknown";
	}
}