/************************************************************************************

**
**        DESCRIPTION    :    Sprint-1(Local Search Engine)
**
**       last updated    :    11-03-2022
**
**
************************************************************************************/

#include "function_definition.c"//including file function_definition.c

/************************************************************************************
**     FUNCTION NAME     :     main
**
**    DESCRIPTION        :     Displaying the user interface /providing options and 
**                             calling operation functions 
**
**     RETURNS           :     Returns an integer(EXIT_SUCCESS) 
**
**
**     Created by        :     Team
************************************************************************************/

int main(void)
{
    int flag = 1;
    char * username = getlogin();
    strcat(path, "/home2/");
    strcat(path, username);
    strcat(path, "/");
    
    do{
        //for user interface details/design
        LINE
    
        printf("\t\t\tWelcome to Local Search Engine(LSE)\t\n\n");
        
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

                if(strlen(ch) > 1){
                    ch[0] = '6';
                }

                //handeling user cases 
                switch (ch[0])
                {
                    case '1':
                        //function call to search by word or sentence in our file system
                        searchByWord();
                        break;
                    
                    case '2':
                        // function call to search by file name in our file system
                        searchByFilename();
                        break;

                    case '3':
                        //function call to open file with given absolute file path
                        openWithAbsolutePath();
                        break;
                    case '4':
                        // for exit
                        exit(EXIT_SUCCESS);
                    
                    default:
                        //to handle unwanted choices
                        printf("Invalid choice please select among(1-4) only..\n\n");
                        flag=1;
                        break;
                }
               strcpy(path, "/home2/");
               strcat(path, username);
               strcat(path, "/");

    }while(flag==1);//to recur among the choices 

    return(EXIT_SUCCESS);
}




