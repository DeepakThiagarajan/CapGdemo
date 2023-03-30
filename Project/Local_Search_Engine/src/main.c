#include "function_definition.c"

int main()
{
    int flag = 1;
    char * username = getlogin();
    strcat(path, "/home2/");
    strcat(path, username);
    strcat(path, "/");;
    
    do{
        
        for(int i = 0; i < 100; i++) 
        {
            printf("-");
        }
        printf("\n");
    
        printf("\t\t\tWelcome to Local Search Engine(LSE)\t\n\n");
        
         for(int i = 0; i < 100; i++) 
        {
            printf("-");
        }
        printf("\n");
                printf("1. Search by word/sentence\n");
                printf("2. Search by filename\n");
                //printf("3. Open file with absolute path\n");
                printf("4. Quit\n");
                LINE
                printf("Choose an option(1-4):");

                char ch[MAX_LENGTH];
                
                scanf("%s", ch);
                
                getchar();
                printf("\n");

                if(strlen(ch) > 1){
                    ch[0] = '6';
                }

                
                switch (ch[0])
                {
                    case '1':
                        //function call to search by word or sentence in our file system
                        searchByWord();
                        break;
                    
                    case '2':
                        
                        searchByFilename();
                        break;

                   /* case '3':
                       
                       openWithAbsolutePath();
                        break;
                    */
                    case '4':
                        
                        exit(EXIT_SUCCESS);
                    
                    default:
                        
                        printf("Invalid choice please select among(1-4) only..\n\n");
                        flag=1;
                        break;
                }
                strcpy(path, "/home2/");
                strcat(path, username);
                strcat(path, "/");

    }while(flag==1); 

    return(EXIT_SUCCESS);
}

