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
#include "../inc/array.h"

#define ELEMENTS 5
#define TEST

int run(void);

int main(void)
{

    #ifdef TEST
        startTesting();
    #else
        run();
    #endif

    return 0;
}



int run(void)
{
    char* names[] = {"Sheldon","Penny","Howard","Raj","Leonard"};


    printf("\n\nOriginal List\n--------------");
    printNames(names, ELEMENTS);

    sortNames(names, ELEMENTS, 1);

    printf("\n\nSorted list\n--------------");
    printNames(names, ELEMENTS);

    return 0;
}
