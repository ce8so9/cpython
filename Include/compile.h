#ifndef Py_COMPILE_H
#define Py_COMPILE_H
#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************
Copyright 1991-1995 by Stichting Mathematisch Centrum, Amsterdam,
The Netherlands.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the names of Stichting Mathematisch
Centrum or CWI not be used in advertising or publicity pertaining to
distribution of the software without specific, written prior permission.

STICHTING MATHEMATISCH CENTRUM DISCLAIMS ALL WARRANTIES WITH REGARD TO
THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS, IN NO EVENT SHALL STICHTING MATHEMATISCH CENTRUM BE LIABLE
FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

******************************************************************/

/* Definitions for bytecode */

/* Bytecode object */
typedef struct {
	PyObject_HEAD
	int co_argcount;	/* #arguments, except *args */
	int co_nlocals;		/* #local variables */
	int co_flags;		/* CO_..., see below */
	PyStringObject *co_code; /* instruction opcodes */
	PyObject *co_consts;	/* list (constants used) */
	PyObject *co_names;	/* list of strings (names used) */
	PyObject *co_varnames;	/* tuple of strings (local variable names) */
	/* The rest doesn't count for hash/cmp */
	PyObject *co_filename;	/* string (where it was loaded from) */
	PyObject *co_name;	/* string (name, for reference) */
} PyCodeObject;

/* Masks for co_flags above */
#define CO_OPTIMIZED	0x0001
#define CO_NEWLOCALS	0x0002
#define CO_VARARGS	0x0004
#define CO_VARKEYWORDS	0x0008

extern DL_IMPORT(PyTypeObject) PyCode_Type;

#define PyCode_Check(op) ((op)->ob_type == &PyCode_Type)


/* Public interface */
struct _node; /* Declare the existence of this type */
PyCodeObject *PyNode_Compile Py_PROTO((struct _node *, char *));
PyCodeObject *PyCode_New Py_PROTO((
	int, int, int, PyObject *, PyObject *, PyObject *, PyObject *,
	PyObject *, PyObject *)); /* same as struct above */

#ifdef __cplusplus
}
#endif
#endif /* !Py_COMPILE_H */
