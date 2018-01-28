#/bin/bash

#First of all, creata applicatin file named "app".
make app=api_color_get_color

#Check whether the src file "app" is exists or not..
if [ ! -e "app" ]; then
    echo "Application file app does not exist."
    
    exit
fi

#Check whether the dst file "api_color_get_ambient_test" is
#exists or not.
#If the file exists, delete it.
if [ -e "api_color_get_color_test" ]; then
    rm api_color_get_color_test
fi

#Rename output file.
mv app api_color_get_color_test
