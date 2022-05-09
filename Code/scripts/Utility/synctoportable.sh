#! /bin/bash

currentDirName=${PWD##*/}

#rsync -avz -e 'ssh' "../${currentDirName}" /run/media/technician/PUBLIC/TBHS/

rsync -avz -e 'ssh' "../${currentDirName}" /run/media/technician/3TB/TBHS/projects/
