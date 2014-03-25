#!/usr/bin/env bash

##########################################
#
#	EPIL's DEMO COMPILING SCRIPT
#
#	Author: Lyoma GUILLOU
#
##########################################

echo "Creating backup for main.cpp"
mkdir -p backup
cp src/main/main.cpp backup/

echo "Compiling Lyoma's demo project for EPIL-ATION"
g++ -std=c++0x -o lyoma_app apps/lyoma_app/main.cpp lib/epil.a

echo "Compiling Lucas' demo project for EPIL-ATION"
#
# FIXME FIXME FIXME FIXME FIXME
#
#g++ -std=c++0x -o lucas_app apps/lucas_app/ [FILES NAME HERE] lib/epil.a