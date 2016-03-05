/* Author : Avinash Awate, Contest Co-ordinator */
/*****************************************************************************
 *                 Programming Contest IITBombayX Palindrome                  *
 *                 ----------------------------------------                  *
 * To allow contest participants to test a function which accepts a string   *
 * and print all the possible palindromes that can be generated using the    *
 * letters of the string                                                     *
 * For the purpose of this contest single characters are a palindrome        *
 * Input  : I.1) A string of  characters                                     *
 * Outputs: O.1) Total number of palindromes found                           *
 *          O.2) Palindromes output on standard output                       *
 *                                                                           *
 *****************************************************************************/

/*****************************************************************************
 *                       Source Code Organisation                            *
 *                       ------------------------                            *
 * testPalindrome.c                                                          *
 * This file allows the participant to test his function for correctness     *
 * This file contains C++ code which opens the input stream, reads the file  *
 * into an array, calls the contestants encoding function and writes the     *
 * data in the output file                                                   *
 * A correct entry will produce an exactly equivalent file                   *
 *                                                                           *
 *****************************************************************************/

/* System Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

/* Local function prototypes */
int Palindrome(char *inStr);

/* Local #defines */
#define MAXLENGTH        (100)
#define SUCCESS                (0)
#define FAILURE                (-1)
#define TRUE                (1)
#define FALSE                (0)

/* Globals */
static char  inputStr[1000];  /* The input array */

/* Local Static Globals */
static FILE *inputfp=NULL;    /* Input file pointer */
static FILE *outputfp=NULL;   /* Output file pointer */

int main (int argc, char *argv[])
{
int  retval;                  /* Return value of function */
char *inputfile=NULL;         /* Input file name */
char *outputfile=NULL;        /* Output file name */
int  index;                   /* To traverse arrays */
char optionchar;              /* Option chracter returned by getopt */

    /* Set return value to SUCCESS */
    retval = SUCCESS;

    /* Process command line options */
    while ((optionchar = getopt (argc, argv, "i:o:")) != -1)
    {
        switch (optionchar)
        {
            case 'i':
                inputfile = optarg;
                break;
            case 'o':
                outputfile = optarg;
                break;
            case '?':
                if ( (optopt == 'i') || (optopt == 'o') )
                {
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                }
                else
                {
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                }
                retval = FAILURE;
            default:
                fprintf (stderr, "Usage : Palindrome [-i inputfile] [-o outputfile]\n");
                retval = FAILURE;
                break;
        }
    }

    /* Ignore all non option arguments */
    if (retval == SUCCESS)
    {
        for (index = optind; index < argc; index++)
        {
            fprintf(stderr, "Non-option argument %s\n", argv[index]);
        }
    }

    /* If everything OK so far, open input and output files */
    if (retval == SUCCESS)
    {   /* Correct Options specified */
        /* Open input file */
        inputfp = stdin;      /* Default is standard input */
        if (inputfile != NULL)
        {
            inputfp = fopen(inputfile,"r");
            if (inputfp == NULL)
            {
                fprintf (stderr, "Unable to open input file %s.\n", inputfile);
                retval = FAILURE;
            }
        }
        /* Open output file */
        if (outputfile != NULL)
        {
            outputfp = fopen(outputfile,"w");
            if (outputfp == NULL)
            {
                fprintf (stderr, "Unable to open output file %s.\n", outputfile);
                retval = FAILURE;
            }
            else { stdout = outputfp; }
        }
    }

    /* If everything OK so far, read input file into input array */
    if (retval == SUCCESS)
    {
        if (fscanf(inputfp, "%s", inputStr) == 1)
        {
            (void) Palindrome(inputStr);
        }
    }

    /* Clean up */
    if (inputfp != NULL) { fclose(inputfp); }
    if (outputfp != NULL) { fclose(outputfp); }

    /* Return from main */
    return(retval);
}
/*****************************************
 *********** End of Test Code ************
 *****************************************/

/************************************************
 *********** Beginning of submission ************
 ************************************************/

/* Define local variables (if any) here */

/* Define your support function ptototypes here */

/********************************************
 *********** Submission function ************
 *******************************************/
/*
 * The function Palindrome accepts one parameter
 * Inputs
 *     The parameter inStr contains the input string
 * Outputs
 *     The function returns the number of unique palindromes generated
 *     The function also prints each unique palindrome on a separate standard output line
 *
 * Algorithm
 *
 */
int Palindrome(char *inStr)
{
    /* Return number of sequences */
}
