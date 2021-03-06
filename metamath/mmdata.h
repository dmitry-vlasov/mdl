#ifndef MMDATA_H_
#define MMDATA_H_

/*****************************************************************************/
/*        Copyright (C) 2008  NORMAN MEGILL  nm at alum.mit.edu              */
/*            License terms:  GNU General Public License                     */
/*****************************************************************************/
/*34567890123456 (79-character line to adjust editor window) 2345678901234567*/

/* mmdata.h - includes for some principal data structures and data-string handling */

#include "mmvstr.h"

/*E*/extern long db,db0,db1,db2,db3,db4,db5,db6,db7,db8,db9;/* debugging flags & variables */
typedef char flag; /* A "flag" is simply a character intended for use as a
                      yes/no logical Boolean; 0 = no and 1 = yes */

extern flag listMode; /* 0 = metamath, 1 = list utility */
extern flag toolsMode; /* In metamath mode:  0 = metamath, 1 = tools */

typedef long nmbrString; /* String of numbers */
typedef void* pntrString; /* String of pointers */



enum mTokenType { var__, con__ };
#define lb_ '{' /* ${ */
#define rb_ '}' /* $} */
#define v__ 'v' /* $v */
#define c__ 'c' /* $c */
#define a__ 'a' /* $a */
#define d__ 'd' /* $d */
#define e__ 'e' /* $e */
#define f__ 'f' /* $f */
#define p__ 'p' /* $p */
#define eq_ '=' /* $= */
#define sc_ '.' /* $. (historically, used to be $; (semicolon) ) */
#define illegal_ '?' /* anything else */
/* Global variables related to current statement */
extern int currentScope;
extern long beginScopeStatementNum;

struct statement_struct { /* Array index is statement number, starting at 1 */
  long lineNum; /* Line number in file; 0 means not yet determined */
  vstring fileName; /* File statement is in; "" means not yet determined */
  vstring labelName; /* Label of statement */
  flag uniqueLabel; /* Flag that label is unique (future implementations may
                      allow duplicate labels on hypotheses) */
  char type;    /* 2nd character of keyword, e.g. 'e' for $e */
  int scope;    /* Block scope level, increased by ${ and decreased by ${ */
  long beginScopeStatementNum;  /* statement of last ${ */
  vstring labelSectionPtr; /* Source code before statement keyword */
  long labelSectionLen;
  vstring mathSectionPtr; /* Source code between keyword and $= or $. */
  long mathSectionLen;
  vstring proofSectionPtr; /* Source code between $= and $. */
  long proofSectionLen;
  nmbrString *mathString; /* Parsed mathSection */
  long mathStringLen;
  nmbrString *proofString; /* Parsed proofSection (used by $p's only */
  nmbrString *reqHypList; /* Required hypotheses (excluding $d's) */
  nmbrString *optHypList; /* Optional hypotheses (excluding $d's) */
  long numReqHyp; /* Number of required hypotheses */
  nmbrString *reqVarList; /* Required variables */
  nmbrString *optVarList; /* Optional variables */
  nmbrString *reqDisjVarsA; /* Required disjoint variables, 1st of pair */
  nmbrString *reqDisjVarsB; /* Required disjoint variables, 2nd of pair */
  nmbrString *reqDisjVarsStmt; /* Req disjoint variables, statem number */
  nmbrString *optDisjVarsA; /* Optional disjoint variables, 1st of pair */
  nmbrString *optDisjVarsB; /* Optional disjoint variables, 2nd of pair */
  nmbrString *optDisjVarsStmt; /* Opt disjoint variables, statem number */
  long pinkNumber; /* 25-Oct-02 The $a/$p sequence number for web pages */
  };

/* Sort keys for statement labels (allocated by parseLabels) */
extern long *labelKey;

struct includeCall_struct {
  /* This structure holds all information related to $[ $] (include) statements
     in the input source files, for error message processing and for
     writing out the source files. */
  long bufOffset; /* Character offset in source buffer that the include
                      applies to */
  vstring current_fn;
  long current_line;
  vstring calledBy_fn;
  long calledBy_line;
  vstring includeSource; /* Source code with the include statement (the include
                         statement is replaced by the included text; this
                         is where the include statement itself is stored). */
  long length; /* length of included file */
  flag pushOrPop; /* 1 = start of include statement, 0 = end of it */
  flag alreadyIncluded; /* 1 = this file has already been included; don't
                           include it again. */
  };

struct mathToken_struct {
  vstring tokenName; /* may be used more than once at different scopes */
  long length; /* to speed up parsing scans */
  char tokenType; /* variable or constant - (char)var__ or (char)con__ */
  flag active;  /* 1 if token is recognized in current scope */
  int scope;    /* scope level token was declared at */
  long tmp;     /* Temporary field use to speed up certain functions */
  long statement; /* Statement declared in */
  long endStatement; /* Statement of end of scope it was declared in */
  };

/* Sort keys for math tokens (allocated by parseMathDecl) */
extern long *mathKey;

extern long MAX_STATEMENTS;
extern long MAX_MATHTOKENS;
extern struct statement_struct *statement;
/*Obs*/ /*extern struct label_struct *label;*/
extern struct mathToken_struct *mathToken;
extern long statements, /*labels, */mathTokens;
extern long maxMathTokenLength;

extern long MAX_INCLUDECALLS;
extern struct includeCall_struct *includeCall;
extern long includeCalls;

extern char *sourcePtr; /* Pointer to buffer in memory with input source */
extern long sourceLen; /* Number of chars. in all inputs files combined (after includes)*/

/* Allocation and deallocation in memory pool */
void *poolFixedMalloc(long size /* bytes */);
void *poolMalloc(long size /* bytes */);
void poolFree(void *ptr);
void addToUsedPool(void *ptr);
/* Purges reset memory pool usage */
void memFreePoolPurge(flag untilOK);
/* Statistics */
void getPoolStats(long *freeAlloc, long *usedAlloc, long *usedActual);

/* Initial memory allocation */
void initBigArrays(void);

/* Find the number of free memory bytes */
long getFreeSpace(long max);

/* Fatal memory allocation error */
void outOfMemory(vstring msg);

/* Bug check error */
void bug(int bugNum);


/* Null nmbrString -- -1 flags the end of a nmbrString */
struct nullNmbrStruct {
    long poolLoc;
    long allocSize;
    long actualSize;
    nmbrString nullElement; };
extern struct nullNmbrStruct nmbrNull;
#define NULL_NMBRSTRING &(nmbrNull.nullElement)

/* Null pntrString -- NULL flags the end of a pntrString */
struct nullPntrStruct {
    long poolLoc;
    long allocSize;
    long actualSize;
    pntrString nullElement; };
extern struct nullPntrStruct pntrNull;
#define NULL_PNTRSTRING &(pntrNull.nullElement)


/* 26-Apr-2008 nm Added */
/* This function returns a 1 if any entry in a comma-separated list
   matches using the matches() function. */
flag matchesList(vstring testString, vstring pattern, char wildCard,
    char oneCharWildCard);

/* This function returns a 1 if the first argument matches the pattern of
   the second argument.  The second argument may have 0-or-more and
   exactly-1 character match wildcards, typically '*' and '?'.*/
/* 30-Jan-06 nm Added single-character-match argument */
flag matches(vstring testString, vstring pattern, char wildCard,
    char oneCharWildCard);



/*******************************************************************/
/*********** Number string functions *******************************/
/*******************************************************************/

/* Make string have temporary allocation to be released by next nmbrLet() */
/* Warning:  after nmbrMakeTempAlloc() is called, the nmbrString may NOT be
   assigned again with nmbrLet() */
void nmbrMakeTempAlloc(nmbrString *s);


/******* Special pupose routines for better
      memory allocation (use with caution) *******/

extern int nmbrTempAllocStackTop;   /* Top of stack for nmbrTempAlloc funct */
extern int nmbrStartTempAllocStack; /* Where to start freeing temporary
    allocation when nmbrLet() is called (normally 0, except for nested
    nmbrString functions) */

/* Make string have temporary allocation to be released by next nmbrLet() */
/* Warning:  after nmbrMakeTempAlloc() is called, the nmbrString may NOT be
   assigned again with nmbrLet() */
void nmbrMakeTempAlloc(nmbrString *s);
                                    /* Make string have temporary allocation to be
                                    released by next nmbrLet() */

/**************************************************/


/* String assignment - MUST be used to assign vstrings */
void nmbrLet(nmbrString **target,nmbrString *source);

/* String concatenation - last argument MUST be NULL */
nmbrString *nmbrCat(nmbrString *string1,...);

/* Emulation of nmbrString functions similar to BASIC string functions */
nmbrString *nmbrSeg(nmbrString *sin, long p1, long p2);
nmbrString *nmbrMid(nmbrString *sin, long p, long l);
nmbrString *nmbrLeft(nmbrString *sin, long n);
nmbrString *nmbrRight(nmbrString *sin, long n);

/* Allocate and return an "empty" string n "characters" long */
nmbrString *nmbrSpace(long n);

long nmbrLen(nmbrString *s);
long nmbrAllocLen(nmbrString *s);
void nmbrZapLen(nmbrString *s, long len);

/* Search for string2 in string 1 starting at start_position */
long nmbrInstr(long start, nmbrString *sin, nmbrString *s);

/* Search for string2 in string 1 in reverse starting at start_position */
/* (Reverse nmbrInstr) */
long nmbrRevInstr(long start_position,nmbrString *string1,
    nmbrString *string2);

/* 1 if strings are equal, 0 otherwise */
int nmbrEq(nmbrString *sout,nmbrString *sin);

/* Converts mString to a vstring with one space between tokens */
vstring nmbrCvtMToVString(nmbrString *s);

/* Converts rString to a vstring with one space between tokens */
vstring nmbrCvtRToVString(nmbrString *s);

/* Get step numbers in an rString - needed by cvtRToVString & elsewhere */
nmbrString *nmbrGetProofStepNumbs(nmbrString *reason);

/* Converts any nmbrString to an ASCII string of numbers corresponding
   to the .tokenNum field -- used for debugging only. */
vstring nmbrCvtAnyToVString(nmbrString *s);

/* Extract variables from a math token string */
nmbrString *nmbrExtractVars(nmbrString *m);

/* Determine if an element is in a nmbrString; return position if it is */
long nmbrElementIn(long start, nmbrString *g, long element);

/* Add a single number to end of a nmbrString - faster than nmbrCat */
nmbrString *nmbrAddElement(nmbrString *g, long element);

/* Get the set union of two math token strings (presumably
   variable lists) */
nmbrString *nmbrUnion(nmbrString *m1,nmbrString *m2);

/* Get the set intersection of two math token strings (presumably
   variable lists) */
nmbrString *nmbrIntersection(nmbrString *m1,nmbrString *m2);

/* Get the set difference m1-m2 of two math token strings (presumably
   variable lists) */
nmbrString *nmbrSetMinus(nmbrString *m1,nmbrString *m2);



/* This is a utility function that returns the length of a subproof that
   ends at step */
long nmbrGetSubProofLen(nmbrString *proof, long step);

/* This function returns a "squished" proof, putting in {} references
   to previous subproofs. */
nmbrString *nmbrSquishProof(nmbrString *proof);

/* This function unsquishes a "squished" proof, replacing {} references
   to previous subproofs by the subproofs themselvs.  The returned nmbrString
   must be deallocated by the caller. */
nmbrString *nmbrUnsquishProof(nmbrString *proof);

/* This function returns the indentation level vs. step number of a proof
   string.  This information is used for formatting proof displays.  The
   function calls itself recursively, but the first call should be with
   startingLevel = 0.  The caller is responsible for deallocating the
   result. */
nmbrString *nmbrGetIndentation(nmbrString *proof,
  long startingLevel);

/* This function returns essential (1) or floating (0) vs. step number of a
   proof string.  This information is used for formatting proof displays.  The
   function calls itself recursively, but the first call should be with
   startingLevel = 0.  The caller is responsible for deallocating the
   result. */
nmbrString *nmbrGetEssential(nmbrString *proof);

/* This function returns the target hypothesis vs. step number of a proof
   string.  This information is used for formatting proof displays.  The
   function calls itself recursively.  The caller is responsible for
   deallocating the result.  statemNum is the statement being proved. */
nmbrString *nmbrGetTargetHyp(nmbrString *proof, long statemNum);

/* Converts a proof string to a compressed-proof-format ASCII string.
   Normally, the proof string would be compacted with squishProof first,
   although it's not a requirement. */
/* The statement number is needed because required hypotheses are
   implicit in the compressed proof. */
vstring compressProof(nmbrString *proof, long statemNum);


/*******************************************************************/
/*********** Pointer string functions ******************************/
/*******************************************************************/

/* Make string have temporary allocation to be released by next pntrLet() */
/* Warning:  after pntrMakeTempAlloc() is called, the pntrString may NOT be
   assigned again with pntrLet() */
void pntrMakeTempAlloc(pntrString *s);


/******* Special pupose routines for better
      memory allocation (use with caution) *******/

extern int pntrTempAllocStackTop;   /* Top of stack for pntrTempAlloc funct */
extern int pntrStartTempAllocStack; /* Where to start freeing temporary
    allocation when pntrLet() is called (normally 0, except for nested
    pntrString functions) */

/* Make string have temporary allocation to be released by next pntrLet() */
/* Warning:  after pntrMakeTempAlloc() is called, the pntrString may NOT be
   assigned again with pntrLet() */
void pntrMakeTempAlloc(pntrString *s);
                                    /* Make string have temporary allocation to be
                                    released by next pntrLet() */

/**************************************************/


/* String assignment - MUST be used to assign vstrings */
void pntrLet(pntrString **target,pntrString *source);

/* String concatenation - last argument MUST be NULL */
pntrString *pntrCat(pntrString *string1,...);

/* Emulation of pntrString functions similar to BASIC string functions */
pntrString *pntrSeg(pntrString *sin, long p1, long p2);
pntrString *pntrMid(pntrString *sin, long p, long l);
pntrString *pntrLeft(pntrString *sin, long n);
pntrString *pntrRight(pntrString *sin, long n);

/* Allocate and return an "empty" string n "characters" long */
pntrString *pntrSpace(long n);

/* Allocate and return an "empty" string n "characters" long
   initialized to nmbrStrings instead of vStrings */
pntrString *pntrNSpace(long n);

/* Allocate and return an "empty" string n "characters" long
   initialized to pntrStrings instead of vStrings */
pntrString *pntrPSpace(long n);

long pntrLen(pntrString *s);
long pntrAllocLen(pntrString *s);
void pntrZapLen(pntrString *s, long len);

/* Search for string2 in string 1 starting at start_position */
long pntrInstr(long start, pntrString *sin, pntrString *s);

/* Search for string2 in string 1 in reverse starting at start_position */
/* (Reverse pntrInstr) */
long pntrRevInstr(long start_position,pntrString *string1,
    pntrString *string2);

/* 1 if strings are equal, 0 otherwise */
int pntrEq(pntrString *sout,pntrString *sin);

/* Add a single null string element to a pntrString - faster than pntrCat */
pntrString *pntrAddElement(pntrString *g);

/* Add a single null pntrString element to a pntrString - faster than pntrCat */
pntrString *pntrAddGElement(pntrString *g);

#endif /*MMDATA_H_*/
