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


/** \brief
 *
 * \param pEmpleado empleado*
 * \param length int
 * \param order int
 * \return int
 *
 */
int sortEmpleadoByName(empleado* pEmpleado, int length, int order)
{
    int i,j;
    empleado auxEmpleado;

    if (length < 1) // Invalid length
    {
        return -1;
    }
    for(i=0; i< length-1; i++)
    {
        if(pEmpleado[i].isEmpty)
            continue;
        for(j=i+1; j<length; j++)
        {
            if(pEmpleado[j].isEmpty)
                continue;
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


/** \brief
 *
 * \param pEmpleado empleado*
 * \param length int
 * \param legajo int
 * \return empleado*
 *
 */
empleado* findEmpleadoByLegajo(empleado* pEmpleado, int length, int legajo)
{
    int i;

    if (length < 1) // Invalid length
    {
        return NULL;
    }
    for(i=0; i< length; i++)
    {
        if(pEmpleado[i].legajo==legajo && !pEmpleado[i].isEmpty)
            return pEmpleado+i;
    }
    return NULL;
}


/** \brief
 *
 * \param pEmpleado empleado*
 * \param length int
 * \return int
 *
 */
int printEmpleados(empleado* pEmpleado, int length)
{
    int i;

    for(i=0; i< length; i++)
    {
        if(!pEmpleado[i].isEmpty)
            printf("\nLegajo: %2i - Nombre: %s",pEmpleado[i].legajo, pEmpleado[i].nombre);
    }
    return 0;
}


/** \brief
 *
 * \param pEmpleado empleado*
 * \param length int
 * \return int
 *
 */
int initEmpleados(empleado* pEmpleado, int length)
{
    int i;

    for(i=0; i< length; i++)
    {
        pEmpleado[i].isEmpty=1;
    }
    return 0;
}

/** \brief
 *
 * \param pEmpleado empleado*
 * \param length int
 * \param legajo int
 * \param nombre[] char
 * \param apellido[] char
 * \param salario float
 * \param sector int
 * \param fechaIngreso long int
 * \return int
 *
 */
int addEmpleado(empleado* pEmpleado, int length, int legajo, char nombre[],char apellido[],float salario,int sector, long int fechaIngreso)
{
    int i;

    for(i=0; i< length; i++)
    {
        if(pEmpleado[i].isEmpty)
        {
            pEmpleado[i].legajo=legajo;
            strcpy(pEmpleado[i].nombre,nombre);
            strcpy(pEmpleado[i].apellido,apellido);
            pEmpleado[i].salario = salario;
            pEmpleado[i].sector = sector;
            pEmpleado[i].fechaIngreso = fechaIngreso;
            pEmpleado[i].isEmpty=0;
            return 0;
        }
    }
    return -1;
}

/** \brief
 *
 * \param pEmpleado empleado*
 * \param length int
 * \param legajo int
 * \return int
 *
 */
int removeEmpleado(empleado* pEmpleado, int length, int legajo)
{
    int i;
    empleado *pAuxEmpleado;
    pAuxEmpleado=findEmpleadoByLegajo(pEmpleado, length, legajo);
    if( pAuxEmpleado != NULL)
    {
        pAuxEmpleado->isEmpty=1;
        return 0;
    }
    return -1;
}
