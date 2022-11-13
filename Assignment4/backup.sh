#!/bin/bash

#initial shell script structure referenced from https://ubuntu.com/server/docs/backups-shell-scripts

# What to backup. 
echo "Please enter the file location to backup"
read -p 'file location: ' backup_files


# Where to backup to.
echo "Please enter the backup file path location"
read -p 'file path: ' dest


# Print start status message.
echo "Backing up $backup_files to $dest"
date
echo

# Backup the files and rsync allows exisiting files to be recopied if there are changes to the the original file
for i in $backup_files
do
rsync --progress -r -u -t $i $dest
done

# Print end status message.
echo
echo "Backup finished"
date

