#/bin/bash

#Check whther the src file "api_ultrasonic_get_distance" exists or not.
#If the file does not exist, exit.
if [ ! -e "api_ultrasonic_listen_test" ]; then
    echo "Application file api_ultrasonic_listen_test does not exist."
    
    exit
fi

#Check whther the destination directory, of EV3, "H:\ev3rt\apps".
if [ ! -d /cygdrive/H/ev3rt/apps ]; then
    echo "Ev3 device is not connected."
    
    exit
fi

#Copy application file to ev3 apps folder.
cp ./api_ultrasonic_listen_test /cygdrive/H/ev3rt/apps
