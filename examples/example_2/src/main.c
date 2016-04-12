/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"

#define ELEMENTS 5
//#define TEST

int run();

int main(void)
{
    #ifdef TEST
        startTesting();

    #else
        run();

    #endif


	return 0;
}

int sortName(char** pName, int length)
{
    char auxName[50];
    int i,j;

    for(i=0;i< length-1;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(strcmp(pName[i],pName[j])>1)
			{
				strcpy(auxName,pName[i]);
				strcpy(pName[i],pName[j]);
                strcpy(pName[j], auxName);

			}
		}
	}
    return 0;
}


int run()
{
    int i;
    char* names[] = {"Sheldon","Penny","Howard","Raj","Leonard"};


    printf("\n\nOriginal List\n--------------");
    for(i=0;i<ELEMENTS;i++)
    {
        printf("\nName: %s",names[i]);
    }

    sortName(names, ELEMENTS);

	printf("\n\nSorted list\n--------------");
    for(i=0;i<ELEMENTS;i++)
    {
        printf("\nName: %s",names[i]);
    }

    return 0;
}
