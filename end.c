/**********************************************************************
 *Copyright (C) 2015 Marcus Pedersén
 *
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/

#include <stdio.h>
#include <unistd.h>
#include "inout.h"

#define ROWS1 3
#define ROWS2 11
#define WSPACE1 10
#define WSPACE2 6
#define SLEEP 5000000

void runend(void)
{
  char *prnt[MAXROWS];
  int i;

  for(i=0; i<MAXROWS; i++)
    printf("\n");

  prnt[0] = "    "
            "=======================================================================";
  prnt[1] = "    "
            "Allt liv i min kropp upphörde och livet så som jag ser det var nu slut!";
  prnt[2] = "    "
            "=======================================================================";

  writechars(prnt, ROWS1);

  for(i=0; i<WSPACE1; i++)
    printf("\n");

  usleep(SLEEP);

  for(i=0; i<MAXROWS; i++)
    printf("\n");
  
  prnt[0] = "                  "
            "============================================";
  prnt[1] = "                  "
            "   ___                           ___________";
  prnt[2] = "                  "
            "  /   \\    |          |       |       |";
  prnt[3] = "                  "
            " /     \\   |          |       |       |";
  prnt[4] = "                  "
            "|          |          |       |       |";
  prnt[5] = "                  "
            " \\_____    |          |       |       |";
  prnt[6] = "                  "
            "       \\   |          |       |       |";
  prnt[7] = "                  "
            "        |  |          |       |       |";
  prnt[8] = "                  "
            "\\      /   |           \\     /        |";
  prnt[9] = "                  "
            " \\____/    |_______     \\___/         |";
  prnt[10] = "                  "
             "============================================";

  writechars(prnt, ROWS2);

  for(i=0; i<WSPACE2; i++)
    printf("\n");
}
