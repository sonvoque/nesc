/* This file is part of the nesC compiler.
   Copyright (C) 2002 Intel Corporation

The attached "nesC" software is provided to you under the terms and
conditions of the GNU General Public License Version 2 as published by the
Free Software Foundation.

nesC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with nesC; see the file COPYING.  If not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
Boston, MA 02110-1301 USA.  */

#ifndef NESC_CG_H
#define NESC_CG_H

/* A connection graph */

struct endp
{
  data_declaration component, interface, function;

  /* args_node is the list of args for the interface if not NULL.
     If no errors have been reported, then
       constant_integral(e->cst) || constant_unknown(e->cst)
     for all expressions e in the list
  */
  expression args_node; 
};

typedef struct endp *endp;

typedef struct cgraph *cgraph;

cgraph new_cgraph(region r);

gnode endpoint_lookup(cgraph ch, endp ep);
gnode fn_lookup(cgraph cg, data_declaration fndecl);

ggraph cgraph_graph(cgraph cg);

#endif
