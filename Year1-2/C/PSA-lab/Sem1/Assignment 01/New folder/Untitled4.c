#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int x=2,i;
   char name[20];
   char *address[x];

   strcpy(name, "Harry Lee");
   for(i=0;i<2;i++)
   {
   	address[i] = (char*)malloc( 50 * sizeof(char) );  /* allocating memory dynamically  */
   }
   
   
   strcpy( *address1, "Lee Fort, 11-B Sans Street");

   printf("Name = %s\n", name );
  // printf("Address: %s\n", address );
   return 0;
}
