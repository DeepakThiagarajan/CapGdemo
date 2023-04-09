/************************************************************************************

**
**        DESCRIPTION    :    Sprint(Remote Search Engine)
**
**       last updated    :    07-04-2023
**
**
************************************************************************************/

#include <headers.h>
#include<log.h>

#define MAX 1024

char path[MAX];
/************************************************************************************
**     FUNCTION NAME     :     main
**
**    DESCRIPTION        :     Displaying the user interface /providing options and 
**                             calling operation functions 
**
**     RETURNS           :     Returns an integer(EXIT_SUCCESS) 
**
**
**     Created by        :    Group-3
************************************************************************************/

int searchByWord();
int searchByFilename();
int openWithAbsolutePath();
int main()
{
	log_set_quiet(false);
	log_set_level(LOG_TRACE);
    int flag = 1;
    char * username = getlogin();
    strcpy(path,"/home2/");
    strcat(path, username);
    strcat(path, "/");
    
    while(flag==1){
        //for user interface details/design
        LINE
    
        printf("\t\t\tWelcome to Remote Search Engine(RSE)\t\n\n");
        
        LINE
                printf("1. Search by word/sentence\n");
                printf("2. Search by filename\n");
                printf("3. Open file with absolute path\n");
                printf("4. Quit\n");
                LINE
                printf("Choose an option(1-4):");

                char ch[MAX_LENGTH];
                //for taking the input choice among the options provided
                scanf("%s", ch);
                
                getchar();//for clearing next line from buffer
                printf("\n");
		log_debug("Received Option: %s",ch);

                if(strlen(ch) > 1){
                    ch[0] = '6';
                }

                //handeling user cases 
                switch (ch[0])
                {
                    case '1':
                        //function call to search by word or sentence in our file system
                        searchByWord();
			log_info("\nThank you for using our RSE\n");
                        break;
                    
                    case '2':
                        // function call to search by file name in our file system
                        searchByFilename();
			log_info("\nThank you for using our RSE\n");
                        break;

                    case '3':
                        //function call to open file with given absolute file path
                        openWithAbsolutePath();
			log_info("\nThank you for using our RSE\n");
                        break;
                    case '4':
                        // for exit
			log_info("\nThank you for using our RSE\n");
                    	exit(EXIT_SUCCESS);
		    default:
                        //to handle unwanted choices
                        log_warn("\nInvalid choice please select among(1-4) only..\n\n");
                        break;
                }
                
    }

    return(EXIT_SUCCESS);
}



