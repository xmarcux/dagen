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

#ifndef INOUT_H
#define INOUT_H

#define MAXROWS 23
#define MAXCOLS 80
#define SLEEP_MS 10000

/*
 * Function prints all lines with a litle
 * delay between every char to get the feeling 
 * of writing.
 * Number of rows and colums is limited to
 * MAXROWS and MAXCOLS.
 * Returns -1 on error, too many rows or 
 * columns else 1.
 */
int writechars(char *lines[], int norows);

/*
 * Function reads chapter from file
 * and writes to terminal until
 * an option occurs.
 * If option is NULL then file is written
 * from start else option part is written.
 * Choosen option is written in optanswer,
 * if no option NULL is written to optanswer.
 */
void write_ch_to_opt(const char *chaptername, const char *option, char *optanswer);

#endif
