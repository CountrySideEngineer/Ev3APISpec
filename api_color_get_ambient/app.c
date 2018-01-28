/**
 *  @file   app.c
 *  @brief  Check execution time of "ev3_color_sensor_get_ambient".
 *
 *  @detail     Check spec of TOPPERS EV3RT.
 *              In this application, execution time of motor api
 *              "ev3_color_sensor_get_ambient" is checked.
 *              To check call the api while 10 second and write
 *              the count into log file.
 *              The count will changes each running time.
 *              So, the test is run 10 times, and the average is
 *              result of this test.
 */
#include "ev3api.h"
#include "app.h"

/********************************/
/*      External variables.     */ 
/********************************/


/********************************/
/*      External constant.      */
/********************************/


/********************************/
/*      External function.      */
/********************************/

/********************************/
/*      Define variables.       */
/********************************/


/********************************/
/*      Define constant.        */
/********************************/


/************************************/
/*      Define static variables.    */
/************************************/
static int task_count = 0;
static int spec_check_task_running = false;
static uint8_t ambient = 0;
static sensor_port_t sensor_port = EV3_PORT_4;
static sensor_type_t sensor_type = COLOR_SENSOR;

/********************************/
/*      Define function.        */
/********************************/
void spec_check_task(intptr_t unused);
void debug_write_msg(const char *msg);

/********************************/
/*          Implement           */
/********************************/
void main_task(intptr_t unused)
{
    char msg_buf[32] = { 0 };
    char *logging_file_name = "ev3_color_sensor_get_ambient.csv";

    int index = 0;
    int loop_index = 0;
    FILE *logging_file = NULL;

    logging_file = fopen(logging_file_name, "w");

    ev3_sensor_config(sensor_port, sensor_type);

    //Start "while" loop to check spec.
    for (loop_index = 0; loop_index < 10; loop_index++) {
        sprintf((char *)&msg_buf[0], "RUNNING! - %2d", loop_index + 1);
        debug_write_msg(msg_buf);

        task_count = 0;
        spec_check_task_running = true;

        act_tsk(SPEC_CHECK_TASK);
        tslp_tsk(10000);   //10 sec

        spec_check_task_running = false;
        tslp_tsk(100);      //Wait till the task finished.

        fprintf(logging_file, "%d,%d,%d\n", loop_index, task_count, ambient);   //Write log data.

        tslp_tsk(100);      //Wait till the task finished.
    }
    fclose(logging_file);

    for (index = 0; index < 32; index++) {
        msg_buf[index] = ' ';   //If the value '0' is set, the test step number is left in LCD.
    }
    sprintf((char *)&msg_buf[0], "FINISHED!");
    debug_write_msg(msg_buf);
}

void spec_check_task(intptr_t unused)
{
    while (spec_check_task_running) {
        ambient = ev3_color_sensor_get_ambient(sensor_port);
        task_count++;
    }
}

void debug_write_msg(const char *msg) {
    //Basically, NULL will not be set to msg, but check the variable is null or not.
    if (NULL != msg) {
        ev3_lcd_draw_string((char *)msg, 0, 0);
    }
}
