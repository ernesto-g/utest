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
 * \param pEmployee employee*
 * \param length int
 * \param order int
 * \return int
 *
 */
int sortEmployeeByName(employee* pEmployee, int length, int order)
{
    int i,j;
    employee auxEmployee;

    if (length < 1) // Invalid length
    {
        return -1;
    }
    for(i=0; i< length-1; i++)
    {
        if(pEmployee[i].isEmpty)
            continue;
        for(j=i+1; j<length; j++)
        {
            if(pEmployee[j].isEmpty)
                continue;
            if(order)
            {
                if(strcmp(pEmployee[i].name,pEmployee[j].name)>0)
                {
                    auxEmployee = pEmployee[i];
                    pEmployee[i] = pEmployee[j];
                    pEmployee[j] = auxEmployee;

                }
            }
            else
            {
                if(strcmp(pEmployee[i].name,pEmployee[j].name)<0)
                {
                    auxEmployee = pEmployee[i];
                    pEmployee[i] = pEmployee[j];
                    pEmployee[j] = auxEmployee;

                }
            }
        }
    }
    return 0;
}


/** \brief
 *
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \return employee*
 *
 */
employee* findEmployeeById(employee* pEmployee, int length,int id)
{
    int i;

    if (length < 1) // Invalid length
    {
        return NULL;
    }
    for(i=0; i< length; i++)
    {
        if(pEmployee[i].id==id && !pEmployee[i].isEmpty)
        {
            return &(pEmployee[i]);
        }

    }
    return NULL;

}


/** \brief
 *
 * \param pEmployee employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(employee* pEmployee, int length)
{
    int i;
    printf("\n  Id   -       Name       -     Last Name    - Salary  - Sector");
    for(i=0; i< length; i++)
    {
        if(!pEmployee[i].isEmpty)
            printf("\n%6i - %-16s - %-16s - %4.2f - %6d",pEmployee[i].id, pEmployee[i].name, pEmployee[i].lastName, pEmployee[i].salary, pEmployee[i].sector );
    }
    return 0;
}


/** \brief
 *
 * \param pEmployee employee*
 * \param length int
 * \return int
 *
 */
int initEmployees(employee* pEmployee, int length)
{
    int i;

    for(i=0; i< length; i++)
    {
        pEmployee[i].isEmpty=1;
    }
    return 0;
}

/** \brief
 *
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \param startDate long int
 * \return int
 *
 */
int addEmployee(employee* pEmployee, int length, int id, char name[],char lastName[],float salary,int sector)
{
    int i;

    for(i=0; i< length; i++)
    {
        if(pEmployee[i].isEmpty)
        {
            pEmployee[i].id=id;
            strcpy(pEmployee[i].name,name);
            strcpy(pEmployee[i].lastName,lastName);
            pEmployee[i].salary = salary;
            pEmployee[i].sector = sector;
            pEmployee[i].isEmpty=0;
            return 0;
        }
    }
    return -1;
}

/** \brief
 *
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \return int
 *
 */
int removeEmployee(employee* pEmployee, int length, int id)
{

    employee *pAuxEmployee = NULL;

    pAuxEmployee = findEmployeeById(pEmployee, length,id);
    if( pAuxEmployee != NULL)
    {
        pAuxEmployee->isEmpty=1;
        return 0;
    }
    return -1;
}
