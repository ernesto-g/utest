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

struct
{
    int legajo;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    long int fechaIngreso;
    int isEmpty;
}typedef empleado;

int sortEmpleadoByName(empleado* pEmpleado, int length, int order);
empleado* findEmpleadoByLegajo(empleado* pEmpleado, int length, int legajo);
int printEmpleados(empleado* pEmpleado, int length);
int addEmpleado(empleado* pEmpleado, int length, int legajo, char nombre[],char apellido[],float salario,int sector, long int fechaIngreso);
int removeEmpleado(empleado* pEmpleado, int length, int legajo);
int initEmpleados(empleado* pEmpleado, int length);
