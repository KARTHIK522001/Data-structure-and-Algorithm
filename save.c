/*Name : K.KarthiK
  Date : 00/00/23
  Description :
  Sample input :
  Sample output :
*/
#include "main.h"

int save_database(flist *head,table *arr,char *newfile)
{
       if(head==NULL)
	   return 0;

       while(head!=NULL)
       {
            if(strcmp(head->s,newfile)==0)
		  return -1;

	    head=head->link;
       }

       FILE *fptr=fopen(newfile,"w");
       if(fptr==NULL)
       {
            printf("File %s unable to open\n",newfile);
	    return 0;
       }

      for(int i=0;i<26;i++)
      {   
           if(arr[i].tlink!=NULL)
           {
    
               fprintf(fptr,"#%d;\n",i);   
               wlist *temp=arr[i].tlink;
               while(temp)
               {    
    
                fprintf(fptr,"%s;%d;",temp->word,temp->file_count);
                sub_t *sub=temp->tlink;
                while(sub)
                {
                     fprintf(fptr,"%s;%d;#",sub->f_name,sub->word_count);
                     sub=sub->link;
                }
                fprintf(fptr,"%s","-> NULL\n");
                temp=temp->link;
    
               }
           }

    
    
    
      }   

       

return 1;

}
