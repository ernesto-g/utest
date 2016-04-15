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
#include "../inc/array.h"
#define ELEMENTS 5
/*
#include "../testing/inc/main_test.h"
#define TEST
*/
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
    empleado arrayEmpleados[ELEMENTS];
    empleado* pEmpleado;
    int i;
    char* names[] = {"Sheldon","Penny","Howard","Raj","Leonard"};

    initEmpleados(arrayEmpleados, ELEMENTS);

    for(i=0; i < ELEMENTS; i++)
    {
        strcpy(arrayEmpleados[i].nombre, names[i]);
        arrayEmpleados[i].legajo = i*i;
        addEmpleado(arrayEmpleados, ELEMENTS,i*i,names[i],names[i],100,1,20161101);
    }

    removeEmpleado(arrayEmpleados, ELEMENTS,9);

    printf("\n\nOriginal List\n--------------");
    printEmpleados(arrayEmpleados, ELEMENTS);


    sortEmpleadoByName(arrayEmpleados, ELEMENTS, 1);

    printf("\n\nSorted list\n--------------");
    printEmpleados(arrayEmpleados, ELEMENTS);

    pEmpleado = findEmpleadoByLegajo(arrayEmpleados, ELEMENTS, 9);
    if(pEmpleado != NULL)
        printf("\n\nEl legajo 9: %s",pEmpleado->nombre);
    return 0;
}

