#/bin/bash

#Check whther the src file "api_get_motor_counts_test" exists or not.
#If the file does not exist, exit.
if [ ! -e "api_get_motor_counts_test" ]; then
    echo "Application file api_get_motor_counts_test does not exist."
    
    exit
fi

#Check whther the destination directory, of EV3, "H:\ev3rt\apps".
if [ ! -d /cygdrive/H/ev3rt/apps ]; then
    echo "Ev3 device is not connected."
    
    exit
fi

#Copy application file to ev3 apps folder.
cp ./api_get_motor_counts_test /cygdrive/H/ev3rt/apps
