/*Name : K.KarthiK
  Date : 00/00/23
  Description :
  Sample input :
  Sample output :
*/

#include"main1.c"


int main(int argc,char *argv[])
{
 
  flist *head=NULL;
  int ecount=0,size,flag=0,k,choice;
  char fstr[FNAME_SIZE],newstr[FNAME_SIZE];


 if(argc<1)
 {
 
    printf("Error : Invalid no of arguments\n");
    printf("Usage :./Inverted.exe <file1> <file2> ...\n");
    
     return 0;
 }
 
 for(int i=1;i<argc;i++)
 {
      FILE *fptr = fopen(argv[i],"r");

      if( fptr == NULL )
      {
	  ecount++;
          printf("Error: The file %s is not present\n",argv[i]);
          printf("so we are not adding into list\n");
      }
      else
      {	   
	    fseek(fptr, 0, SEEK_END);
            size = ftell(fptr);

            // Check if the file is empty
           if (size == 0)
	   {
              printf("Error:The file %s is empty.\n", argv[i]);
           } 
	   else
	   {
	       
	       if(k=insert_file(&head,argv[i])==1)
	       {
		   printf("successful: %s file Added to list\n",argv[i]);
	       }
	       else if(k==-1)
	       {
	          printf("Error:file  %s failed to  add\n",argv[i]);
		 
	       }
	       else
	       {
	           printf("Error:file %s file is repeated\n",argv[i]);

	       }
               
           }
            fclose(fptr);
      }
 }

 if( ecount == argc-1 )
 {
 
    printf("There is no valid file\n");
    printf("please enter valid file.. \n");
    return 0;
 
 }

 table arr[26];
 creat_invertedindex(arr,26);


while(1)
{
       printf("Enter your choice:\n 1. Create_Database\n 2. Display_Database\n 3. Search_Database\n 4. Update_Database\n 5. Save_Database\n 6. Exit\n");
      
       scanf("%d",&choice);
       switch(choice)
       {
       
	   case 1:   if(create_Database(arr,head))
		    {
		        printf("Info : Database created Successfully\n");
		    }
		    else
			printf("Error: failed to create Database\n");

		    break;

         case 2:
		    disp_database(arr);
		    break;
	
         case 3:
		    char gword[WORD_SIZE];
		    printf("Enter the string:");
		    scanf("%s",gword);
		    if(!search(arr,gword))
		    {
                                           
		       printf("%s word not found\n",gword);
		    }
                    break;

        case 4:
		    printf("Enter the filename : \n");
		    scanf("%s",fstr);
		    update_database(&head,fstr);
                    create_Database(arr,head);

		    break;
	            
       case 5:
		    printf("Enter the backup file name:\n");
		    scanf("%s",newstr);
		    if(k=save_database(head,arr,newstr)==1)
			printf("Successful : Database saved in %s file\n",newstr);
		    else if(k==-1)
			printf("Failure : %s file already exist in Database\n",newstr);
		    else
			printf("Failure : Database not created\n");
		    break;

       
	case 6:
	          return 0;


         default:
		   printf("Info: Entered Wrong value\n");
		   break;
       
       
       }

}










return 0;
}
