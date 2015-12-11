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

/*
 * Includes functions for in- and output from/to terminal.
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inout.h"


/* Local help function */
static void get_opt_choice(FILE *optfile, char *optanswer);


int writechars(char *lines[], int norows)
{
  int err = 1, i, j;
  char *pl;

  for(i=0; i < norows; i++, lines++){
    if(i>MAXROWS){
      err = -1;
      break;
    }
    pl = *lines;
    j=0;
    while(*pl){
      if(j>=MAXCOLS){
	err = -1;
        break;
      }
      putchar(*pl);
      fflush(stdout);
      usleep(SLEEP_MS);
      pl++;
      j++;
    }
    putchar('\n');
    fflush(stdout);
  }
  return err;
}

void write_ch_to_opt(const char *chaptername, const char *option, char *optanswer)
{
  FILE *pfile;
  char *preadrows[MAXROWS];
  const char opt[] = "<option>";
  char fopt[MAXCOLS] = "<", eopt[MAXCOLS] = "</";
  int i;

  if(option != NULL){
    strcat(fopt, option);
    strcat(fopt, ">");
    strcat(eopt, option);
    strcat(eopt, ">");
  }

  pfile = fopen(chaptername, "r");
  if(pfile){
    preadrows[0] = (char *) malloc(sizeof(char)*(MAXCOLS+1));

    if(option != NULL){
      while(fgets(preadrows[0], MAXCOLS, pfile) &&
	    strncmp(fopt, preadrows[0], strlen(option)+2))
	;
    }

    i=0;
    while(fgets(preadrows[i], MAXCOLS, pfile) && i<=MAXROWS){
      preadrows[i+1] = (char *) malloc(sizeof(char)*(MAXCOLS+1));
      if(!strncmp(opt, preadrows[i], strlen(opt)))
	break;
      else if(i==MAXROWS){
	writechars(preadrows, i);
	while(getc(stdin) != '\n')
	  ;
	i=-1;
      }
      else if(option != NULL &&
	      !strncmp(eopt, preadrows[i], strlen(option)+3)){
	break;
      }

      preadrows[i][strlen(preadrows[i])-1] = '\0';
      i++;
    }
    writechars(preadrows, i);

    if(!option)
      get_opt_choice(pfile, optanswer);
    else{
      while(getchar() != '\n'){
	printf("Waiting for newl");
      }
    }
    fclose(pfile);
    for(i=i+1 ;i>=0; i--)
      free(preadrows[i]);
  }
  else
    fprintf(stderr, "\n%s%s\n", "Can not open file: ", chaptername);
}


static void get_opt_choice(FILE *optfile, char *optanswer)
{
  char optansw[MAXCOLS], *opt[MAXROWS];
  const char opttoken[] = "</option>";
  int i, j, k, wrong=1;
  
  opt[0] = (char *) malloc(sizeof(int)*(MAXCOLS+1));
  for(i=0;fgets(opt[i], MAXCOLS, optfile) && i<MAXROWS ; i++){
    opt[strlen(opt[i])-1] = '\0';
    opt[i+1] = (char *) malloc(sizeof(int)*(MAXCOLS+1));
    if(!strncmp(opttoken, opt[i], strlen(opttoken))){
      opt[i] = NULL;
      break;
    }
  }

  while(wrong){
    printf("%s", "?");
    scanf("%s", optansw);
    getchar();
    
    for(j=0; j<strlen(optansw); j++)
      optansw[j] = tolower(optansw[j]);

    for(k=0; opt[k]; k++){
      if(!strncmp(optansw, opt[k], strlen(optansw))){
	strcpy(optanswer, optansw);
	for(i=i+1; i>0; i--){
	  free(opt[i]);
	}
	wrong=0;
      }
    }
    if(wrong)
      printf("%s: %s", "Kan inte göra", optansw);
  }
}
