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

int sortNames(char** pName, int length,int order)
{
    char* auxName;
    int i,j;

    if (length < 1) // Invalid length
    {
        return -1;
    }
    for(i=0; i< length-1; i++)
    {
        for(j=i+1; j<length; j++)
        {
            if(order)
            {
                if(strcmp(pName[i],pName[j])<0)
                {
                    auxName = pName[i];
                    pName[i] = pName[j];
                    pName[j] = auxName;

                }
            }
            else
            {
                if(strcmp(pName[i],pName[j])<0)
                {
                    auxName = pName[i];
                    pName[i] = pName[j];
                    pName[j] = auxName;

                }
            }
        }
    }
    return 0;
}

int findName(char** pName, int length, char* nameToFind)
{
    int i;

    if (length < 1) // Invalid length
    {
        return -1;
    }
    for(i=0; i< length; i++)
    {
        if(strcmp(pName[i],nameToFind)==0)
            return i;
    }
    return -1;
}

int printNames(char** pName, int length)
{
    int i;

    for(i=0; i< length; i++)
    {
        printf("\nName: %s",pName[i]);
    }
    return 0;
}

