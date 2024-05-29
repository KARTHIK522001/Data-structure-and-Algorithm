/*Name : K.KarthiK
  Date : 00/00/23
  Description :
  Sample input :
  Sample output :
*/
#include"main.h"


int insert_file(flist **head,char *str)
{
    flist *new=malloc(sizeof(flist));
    new->link=NULL;
    new->s=str;

    if(new==NULL)
	return -1;

    if(*head==NULL)
    {     
        *head=new;
	    return 1;
    }
    flist *temp=*head;
    

    while(temp->link!=NULL)
    {         
	      if(strcmp(temp->s,str)==0)
	      {
	          return 0;
	      }
	    //  printf("%s\n",temp->s);
              temp=temp->link;

    }

    if(strcmp(temp->s,str)==0)
    {
       return 0;
    }
    temp->link=new;

    return 1;


}




int creat_invertedindex(table *arr,int size)
{

      for(int i=0;i<size;i++)
      {
              arr[i].index=i;
	      arr[i].tlink=NULL;
      
      }	  


}


int create_Database(table *arr,flist *head)
{
    if(head==NULL)
    {
          return 0;
    }
    char word[WORD_SIZE];
    int ind;
    while(head)
    {
           FILE *fptr=fopen(head->s,"r");

	   while(fscanf(fptr,"%s",word)!=EOF)
           {
	      
	      if(isupper(word[0]))
	      {
	           ind=word[0]%65;
	      }
	      else
	      {
	          ind=word[0]%97;

	      }
	      if(arr[ind].tlink==NULL)
              {

	      
	               wlist *new=malloc(sizeof(wlist));
		       if(new==NULL)
                                return 0;
		       new->file_count=1;
		       strcpy(new->word,word);
		       new->link=NULL;
		       sub_t *newsub=malloc(sizeof(sub_t));
		       if(newsub==NULL)
			          return 0;
		       newsub->word_count=1;
		       strcpy(newsub->f_name,head->s);
		       newsub->link=NULL;

	               arr[ind].tlink=new;
		       new->tlink=newsub;
	      }
              else
	      {
		  wlist *temp=arr[ind].tlink;
		  wlist *preword;
	          while(temp!=NULL)
	        {
		   if( strcmp(temp->word,word) == 0)
		   {  
		        sub_t *subtemp=temp->tlink, *pretemp;
			while(subtemp!=NULL)
			{  
			    if(strcmp(subtemp->f_name,head->s)==0)
			    {
			       break;
			    }
			    pretemp = subtemp;
			    subtemp=subtemp->link;
			}
			if(subtemp != NULL)
		       	{
                               subtemp->word_count=subtemp->word_count+1;  
			
			    
			}
			else
			{    


		              sub_t *newsub=malloc(sizeof(sub_t));
                              if(newsub==NULL)
                                           return 0;
                               newsub->word_count=1;
                               strcpy(newsub->f_name,head->s);
                               newsub->link=NULL;
  
                                pretemp->link=newsub;
	         		temp->file_count=temp->file_count+1;
			}
			break;
		   }
		   else
                   {     
		           preword=temp;
            		   temp=temp->link;
		   }

	       }


               if(temp==NULL)
               {
	               wlist *new=malloc(sizeof(wlist));
                       if(new==NULL)
                                return 0;
                       new->file_count=1;
		       strcpy(new->word,word);
		       new->link=NULL;
                       sub_t *newsub=malloc(sizeof(sub_t));
                       if(newsub==NULL)
                                  return 0;
                       newsub->word_count=1;
                       strcpy(newsub->f_name,head->s);
                       newsub->link=NULL;
                       new->tlink=newsub;


                       preword->link=new;
	       }
	      
	   
	   }
    
    }

    fclose(fptr);
    
    head=head->link;

    
    if(head==NULL)
	  return 1;

  }

}



void disp_database(table *arr)
{

  
      for(int i=0;i<26;i++)
      {
           if(arr[i].tlink!=NULL)
	   {
	      //printf("%d.  NULL",arr[i].index);
	   
	   
	       printf("(%2.2d.)\n",arr[i].index);
	       wlist *temp=arr[i].tlink;
	       while(temp)
	       {	   
	       
	        printf(" [%s]   %d file(s) :",temp->word,temp->file_count);
		sub_t *sub=temp->tlink;
		while(sub)
		{
		     printf(" file_name: %s  %d",sub->f_name,sub->word_count);
		     sub=sub->link;
		}
                printf(" -> NULL\n");
		temp=temp->link;
		
	       }
	   }

	  
      
      
      }


}

int search(table *arr,char *word)
{

     int ind;

     if(isupper(word[0]))
     { 
        ind=word[0]%65;
     }
     else
     {
       ind=word[0]%97;
     }
     wlist *temp=arr[ind].tlink;
     while(temp!=NULL)
     {
     
          if(strcmp(temp->word,word)==0)
	  {
	      printf("Word : [%s] is found in [%d] files\n",temp->word,temp->file_count);
	      sub_t *subtemp=temp->tlink;
	      while(subtemp!=NULL)
	      {
	           printf("In file [%s] for [%d] times\n",subtemp->f_name,subtemp->word_count);
		   subtemp=subtemp->link;
	      
	      }
	      return 1;
	      
	  }
     
	  temp=temp->link;
     }

     return 0;
    


}
