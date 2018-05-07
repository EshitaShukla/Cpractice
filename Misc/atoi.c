// // A C++ program to remove "b" and 'ac' from input string
#include<stdio.h>
#include<stdlib.h>

#include<stdint.h>

int32_t my_atoi(char* str)
{
   int8_t sign = 0;
   int32_t result=0;

   if(*str == '\0')
   {
    	return '\0';
   }
   if(*str == '-')
   {
    	sign = 1;
   		str++;
   }

   /*Check if data is an integer or higher hex bits*/
   if(((*str>='0')&&(*str<='9'))||*str==' '||((*str>='A')&&(*str<='F')))
   {
    	while(*str!='\0')
    	{
        	if(*str==' ')
        	{
            	str++;
            	continue;
        	}
        	else if((*str>='0')&&(*str<='9'))
        	{
            	result = result*10 + (int)(*str - '0');
            	str++;
            	continue;
        	}
        	else if((*str>='A')&&(*str<='F'))
        	{
            	result = result*10 + (int)(*str - 'A');
            	str++;
            	continue;
        	}
        	break;
    	}
   	}

   if(sign)
   {
   		result = -result;
   }

   if(result)
    return result;
   else return 0;
}

// Driver program to test above function
int main()
{
	char str1[] = "B";
	int a = my_atoi(str1);
	printf("%d", a);
	return 0;
}
