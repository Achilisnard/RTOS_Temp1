/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    affichage.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "affichage.h"
#include "../PIC32_RTOS.X/lcd.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the AFFICHAGE_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

AFFICHAGE_DATA affichageData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void AFFICHAGE_Initialize ( void )

  Remarks:
    See prototype in affichage.h.
 */

void AFFICHAGE_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    affichageData.state = AFFICHAGE_STATE_INIT;
    


    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void AFFICHAGE_Tasks ( void )

  Remarks:
    See prototype in affichage.h.
 */

void AFFICHAGE_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( affichageData.state )
    {
        /* Application's initial state. */
        case AFFICHAGE_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                affichageData.state = AFFICHAGE_STATE_SERVICE_TASKS;
            }
            break;
        }

        case AFFICHAGE_STATE_SERVICE_TASKS:
        {
            //writeString("hello");
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
