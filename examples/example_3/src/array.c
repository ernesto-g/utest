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


int sortEmpleadoByName(empleado* pEmpleado, int length, int order)
{
    empleado auxEmpleado;
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
                if(strcmp(pEmpleado[i].nombre,pEmpleado[j].nombre)>0)
                {
                    auxEmpleado = pEmpleado[i];
                    pEmpleado[i] = pEmpleado[j];
                    pEmpleado[j] = auxEmpleado;

                }
            }
            else
            {
                if(strcmp(pEmpleado[i].nombre,pEmpleado[j].nombre)<0)
                {
                    auxEmpleado = pEmpleado[i];
                    pEmpleado[i] = pEmpleado[j];
                    pEmpleado[j] = auxEmpleado;

                }
            }
        }
    }
    return 0;
}

empleado* findEmpleadoByLegajo(empleado* pEmpleado, int length, int legajo)
{
    int i;

    if (length < 1) // Invalid length
    {
        return NULL;
    }
    for(i=0; i< length; i++)
    {
        if(pEmpleado[i].legajo==legajo)
            return pEmpleado+i;
    }
    return NULL;
}

int printNames(empleado* pEmpleado, int length)
{
    int i;

    for(i=0; i< length; i++)
    {
        printf("\nLegajo: %2i - Nombre: %s",pEmpleado[i].legajo, pEmpleado[i].nombre);
    }
    return 0;
}


