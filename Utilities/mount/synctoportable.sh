#! /bin/bash

currentDirName=${PWD##*/}

rsync -avz -e 'ssh' "../${currentDirName}" /run/media/$USER/projects/
