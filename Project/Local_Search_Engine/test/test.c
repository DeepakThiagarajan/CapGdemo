/******************************************************************************
* File Name:minmax_test.c
* Purpose: Main function to call the CUNIT Framework
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>


#include <Basic.h>
#include <CUnit.h>

//#include "../include/function.h"
#include "testfunction.h"

//void Mytestfunction1(void);

/******************************************************************************
 Function     : init_minmax
 Description  : Initializes the suite
 Input        : Nothing
 Output       : int
***************************************************************************/
int init_minmax(void)
{
    return 0;
}

/******************************************************************************
 Function     : clean_minmax
 Description  : clean the suite after successful run
 Input        : Nothing
 Output       : int
***************************************************************************/
int clean_minmax(void)
{
    return 0;
}

/*************************************************************************************
 Function     : main
 Description  :This is the main function to test backend getMin(), getMax()
 Input        : None
 Output       : Int
************************************************************************************/
int main(int argc, char *argv[])
{
    CU_pSuite pSuite = NULL;

    /* Register  */
    if (CUE_SUCCESS != CU_initialize_registry())
       return CU_get_error();

    /* Add init and cleanup handlers */
    pSuite = CU_add_suite("function_definition.c test cases",init_minmax,clean_minmax);

    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_1", Mytestfunction1))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_2", Mytestfunction2))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }

//     /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_3", Mytestfunction3))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
//     /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_4", Mytestfunction4))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
//       /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_5", Mytestfunction5))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
//      /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_6", Mytestfunction6))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
//     /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_7", Mytestfunction7))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
//      /* Add test case*/ 
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_8", Mytestfunction8))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
//       /* Add test case */
   if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_9", Mytestfunction9))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
     /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_10", Mytestfunction10))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
       /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_11", Mytestfunction11))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
      /* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_ID_12", Mytestfunction12))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
    /* Set the mode and  invoke test(s) */ 
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    /* unregister and do cleanup */
    CU_cleanup_registry(); 
    
    return CU_get_error();
}



