#!/bin/bash
cd /home/emitos/esd

 existing=0
 existing=`ps waux | grep SCREEN | grep ESD | sed -e 's/\(.*\)\(LAP_JOBS*\)\(.*\)/\2/' | wc -l`
 if [ $existing -eq "0" ]
then
   echo "starting ESD daemon"
   screen -d -m -S ESD '/home/emitos/esd/daemon.sh'

 else

   echo "ESD-Daemon already running"

 fi
