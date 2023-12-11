/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */

#include "lcd.h"
#include "stdio.h"
#include "../src/config/default/peripheral/tmr/plib_tmr2.h"
#include "../src/config/default/peripheral/pmp/plib_pmp.h"
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */



/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */



/* *****************************************************************************
 End of File
 */

/*******************************************************************************

  Function:
    void Delay_ms (unsigned int x)

  Summary:
    Delay needed for the LCD to process data (in ms)
*/
void Delay_ms(unsigned int x)
{
    TMR2 = 0;
    while (TMR2_CounterGet() < (389 * x)); /* 40 Timer 1 ticks = ~1ms */
}


/*******************************************************************************

  Function:
    void initializeLCD (void)

  Summary:
    LCD initialization sequence
*/
void initializeLCD(void)
{
    /* Configure general PMP options - enable read/write strobes, long waits, etc */
    //PMP_AddressSet(0x1);
    //PMP_AddressPortEnable(0x1);

    //Delay_ms(60); /* LCD needs 60ms to power on and perform startup functions */

    PMP_AddressSet(CMDREG); /* Access the LCD command register */

    PMP_MasterSend( 0x38); /* LCD Function Set - 8-bit interface, 2 lines, 5*7 Pixels */
    Delay_ms(1); /* Needs a 40us delay to complete */

    PMP_MasterSend( 0x0C); /* Turn on display (with cursor hidden) */
    Delay_ms(1); /* Needs a 40us delay to complete */

    PMP_MasterSend( 0x01); /* Clear the display */
    Delay_ms(2); /* Needs a 1.64ms delay to complete */

    PMP_MasterSend( 0x06); /* Set text entry mode - auto increment, no shift */
    Delay_ms(1); /* Needs a 40us delay to complete */
}


/*******************************************************************************

  Function:
    void writeToLCD(int reg, char c)

  Summary:
    Writes a byte of data to either of the two LCD registers (DATAREG, CMDREG)
*/
void writeToLCD(int reg, char c)
{
    PMP_AddressSet(reg); /* Either 'DATAREG' or 'CMDREG' */

    PMP_MasterSend(c);
    while(PMP_PortIsBusy() == true);
    Delay_ms(1); /* 40us needed in between each write */
}


/*******************************************************************************

  Function:
    void writeString (unsigned char *string)

  Summary:
    Used to write text strings to the LCD
*/

void writeString(char *string)
{
    while (*string)
    {
        writeToLCD(DATAREG, *string++); /* Send characters one by one */
    }
}


/*******************************************************************************

  Function:
    void newLine(void)

  Summary:
    Sets the LCD cursor position to line two
*/
void newLine(void)
{
    writeToLCD(CMDREG, 0xC0); /* Cursor address 0x80 + 0x40 = 0xC0 */
}
