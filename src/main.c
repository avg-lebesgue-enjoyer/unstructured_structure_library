/**
 * @file main.c
 * @author Gabriel Field
 * @brief Driver for testing the data structures built in the project.
 * @version 0.1
 * @date 2024-06-19
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "main.h"
#include "allTheStructures.h"
#include "allTheStructureTests.h"
#include "algos/allTheAlgos.h"
#include "algos/allTheAlgoTests.h"



/* LAUNCH: current driver code */

/**
 * @brief main
 * @param argc int
 * @param argv char**
If they are declared, the parameters to the main function shall obey the following constraints:
- The value of >>argc<< shall be nonnegative.
- >>argv[argc]<< shall be a null pointer.
- If the value of >>argc<< is greater than zero, the array members >>argv[0]<< through >>argv[argc-1]<< inclusive shall contain pointers to strings, 
   which are given implementation-defined values by the host environment prior to program startup. The intent is to supply to the program 
   information determined prior to program startup from elsewhere in the hosted environment. If the host environment is not capable of 
   supplying strings with letters in both uppercase and lowercase, the implementation shall ensure that the strings are received in lowercase.
- If the value of >>argc<< is greater than zero, the string pointed to by >>argv[0]<< represents the program name; >>argv[0][0]<< shall be the null 
   character if the program name is not available from the host environment. If the value of >>argc<< is greater than one, the strings pointed 
   to by >>argv[1]<< through >>argv[argc-1]<< represent the program parameters.
- The parameters >>argc<< and >>argv<< and the strings pointed to by the >>argv<< array shall be modifiable by the program, and retain their 
   last-stored values between program startup and program termination.

 * @return int
 */
int main(int argc, char *argv[]) {
    for (int arg = 0; arg < argc; arg++) {
        if (! strncmp(argv[arg], TESTARRAY, TESTARRAYLENGTH)) {
            testArrayDotC();
        } else if (! strncmp(argv[arg], TESTLINSEARCH, TESTLINSEARCHLENGTH)) {
            testLinsearchDotC();
        } else if (! strncmp(argv[arg], TESTBINSEARCH, TESTBINSEARCHLENGTH)) {
            testBinsearchDotC();
        }
    }

    return 0;
}
