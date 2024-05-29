/*Name : K.KarthiK
  Date : 00/00/23
  Description :
  Sample input :
  Sample output :
*/

#include "main.h"

int update_database(flist **head,char *fstr)
{
    int size,k;
 FILE *fptr = fopen(fstr,"r");

      if( fptr == NULL )
      {   
        
          printf("Error: The file %s is not present\n",fstr);
          printf("so we are not adding into list\n");
      }   
      else
      {    
            fseek(fptr, 0, SEEK_END);
            size = ftell(fptr);

            // Check if the file is empty
           if (size == 0)
           {
              printf("Error:The file %s is empty.\n", fstr);
           }
           else
           {
    
               if(k=insert_file(head,fstr)==1)
               {
                   printf("successful: %s file Added to list\n",fstr);
               }
               else if(k==-1)
               {
                  printf("Error:file  %s failed to  add\n",fstr);
    
               }
               else
               {
                   printf("Error:file %s file is repeated\n",fstr);

               }
    
           }
            fclose(fptr);
      }



      

}
