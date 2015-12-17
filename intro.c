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
#include <string.h>
#include "inout.h"

#define ROWS 10
#define GPLROWS 16
#define WSPACE1 7
#define WSPACE2 4
#define NOBEEPS 3
#define BEEPSLEEP 500000
#define GPLSLEEP  3000000

int runintro(void)
{
  char *prnt[MAXROWS], *prntgpl[MAXROWS], optanswer[MAXCOLS];
  int i;

  for(i=0; i<MAXCOLS; i++)
    printf("\n");

  prnt[0] = "               "
            "==================================================";
  prnt[1] = "               "
            " _____        ___        ___     _______";
  prnt[2] = "               "
            "|     \\      /   \\      /   \\   |         |\\     |";
  prnt[3] = "               "
            "|      \\    /     \\    /     \\  |         | \\    |";
  prnt[4] = "               "
            "|       |  |_______|  |         |____     |  \\   |";
  prnt[5] = "               "
            "|       |  |       |  |    ___  |         |   \\  |";
  prnt[6] = "               "
            "|      /   |       |   \\     /  |         |    \\ |";
  prnt[7] = "               "
            "|_____/    |       |    \\___/   |_______  |     \\|";
  prnt[8] = " ";
  prnt[9] = "               "
            "==================================================";

  writechars(prnt, ROWS);

  for(i=0; i<WSPACE1; i++)
    printf("\n");

  for(i=0; i<NOBEEPS; i++){
    printf("\a");
    fflush(stdout);
    usleep(BEEPSLEEP);
  }

  usleep(GPLSLEEP);

  prntgpl[0] = "     "
            "**********************************************************************";
  prntgpl[1] = "     "
            "*Copyright (C) 2015 Marcus Pedersén                                  *";
  prntgpl[2] = "     "
            "*                                                                    *";
  prntgpl[3] = "     "
            "*This program is free software: you can redistribute it and/or modify*";
  prntgpl[4] = "     "
            "*it under the terms of the GNU General Public License as published by*";
  prntgpl[5] = "     "
            "*the Free Software Foundation, either version 3 of the License, or   *";
  prntgpl[6] = "     "
            "*(at your option) any later version.                                 *";
  prntgpl[7] = "     "
            "*                                                                    *";
  prntgpl[8] = "     "
            "*This program is distributed in the hope that it will be useful,     *";
  prntgpl[9] = "     "
            "*but WITHOUT ANY WARRANTY; without even the implied warranty of      *";
  prntgpl[10]= "     "
            "*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the        *";
  prntgpl[11]= "     "
            "*GNU General Public License for more details.                        *";
  prntgpl[12]= "     "
            "*                                                                    *";
  prntgpl[13]= "     "
            "*You should have received a copy of the GNU General Public License   *";
  prntgpl[14]= "     "
            "*along with this program. If not, see <http://www.gnu.org/licenses/>.*";
  prntgpl[15]= "     "
            "**********************************************************************";

  writechars(prntgpl, GPLROWS);

  for(i=0; i<WSPACE2; i++)
    printf("\n");

  usleep(GPLSLEEP);

  for(i=0; i<MAXROWS; i++)
    printf("\n");

  prnt[10]= "               "
            "=           Vad var det som gick fel?            =";
  prnt[11]= "               "
            "==================================================";

  for(i=0; i<ROWS+2; i++){
    printf(prnt[i]);
    printf("\n");
  }

  for(i=0; i<WSPACE1-2; i++)
    printf("\n");

  usleep(GPLSLEEP);

  write_ch_to_opt("intro", NULL, optanswer);

  if(!strcmp("öl", optanswer)){
    write_ch_to_opt("intro", "öl", optanswer);
    return -1;
  }
  else if(!strcmp("värktablett", optanswer)){
    write_ch_to_opt("intro", "värktablett", optanswer);
    return 1;
  }
  else
    return -1;
}
