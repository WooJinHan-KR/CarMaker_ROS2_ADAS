#! /bin/bash

if [ $1 -eq 0 ]
then
CONFIG_HELPER=""
else
CONFIG_HELPER="-VDSconfig $1"
fi

#$IPGHOME/carmaker/linux64/GUI/Movie.exe $CONFIG_HELPER -datapool $2 -apphost $3
$IPGHOME/carmaker/linux64-13.0.1/GUI/Movie.exe $CONFIG_HELPER -datapool $2 -apphost $3
