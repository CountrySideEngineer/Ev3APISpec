#/bin/bash

#First of all, creata applicatin file named "app".
make app=api_ultrasonic_get_distance

#Check whether the src file "app" is exists or not..
if [ ! -e "app" ]; then
    echo "Application file app does not exist."
    
    exit
fi

#Check whether the dst file "api_get_motor_counts_test" is
#exists or not.
#If the file exists, delete it.
if [ -e "api_ultrasonic_get_distance_test" ]; then
    rm api_ultrasonic_get_distance
fi

#Rename output file.
mv app api_ultrasonic_get_distance_test
