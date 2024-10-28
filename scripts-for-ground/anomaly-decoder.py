#!/bin/python3

#Author: Konstantin Winkel

import os
import sys
import re

anomaly_dictionary = {}
list_of_anomalies = []
generated_path = os.path.join("..", "generated")
all_set = False

#https://stackoverflow.com/questions/8924173/how-can-i-print-bold-text-in-python
class color:
   PURPLE = '\033[95m'
   CYAN = '\033[96m'
   DARKCYAN = '\033[36m'
   BLUE = '\033[94m'
   GREEN = '\033[92m'
   YELLOW = '\033[93m'
   RED = '\033[91m'
   BOLD = '\033[1m'
   UNDERLINE = '\033[4m'
   END = '\033[0m'

#this function displays the help text
def help_function():
    print(color.BOLD + "How to use" + color.END)
    print("Use this script to decode the anomaly hashes from TM into something that can be understood.")
    print()
    print(color.BOLD + "Usage" + color.END)
    print(color.BLUE + "./anomaly-decoder.py <number> ..." + color.END)
    print("This will print the app and name from the anomaly hash. You can use as many anomalies as you want.")
    print("")
    print(color.BOLD + "Parameters" + color.END)
    print(color.BLUE + "./anomaly-decoder.py -a/--all" + color.END)
    print("This will print all anomalies defined in you project with their hash.")
    print("")
    print(color.BLUE + "./anomaly-decoder -p/--path=<path> ..." + color.END)
    print("This will use a custom path to the generated-folder rather than the default path")
    exit()

#loops through all anomaly.h files in apps and fills the anomaly dictionary
def get_all_anomalies():

    #regex string to find "constexpr std::uint16_t <anomaly> = <hash>;"
    regex = r"constexpr std::uint16_t ([-a-zA-Z0-9_]*) = ([0-9]*);"

    #change dir to generated apps folder
    path = os.path.join(os.path.dirname(os.path.realpath(__file__)), generated_path, "apps")
    os.chdir(path)

    #for all app names, loop through their folders
    for app_name in os.listdir(path):
        
        #determine the path to anomaly.h and read its contents
        anomaly_path = os.path.join(path, app_name, "include", app_name + "-generated")
        anomaly_header_content = open(os.path.join(anomaly_path, "anomaly.h"), 'r').read()

        #find matches to the regex in the contents
        matches = re.finditer(regex, anomaly_header_content, re.MULTILINE)
        
        #for all matches, add their name and hash to the anomaly dictionary
        for matchnum, match in enumerate(matches, start=1):
            dictionary_string = app_name + ": " + match.group(1)
            anomaly_dictionary[match.group(2)] = dictionary_string

#displays all anomalies in the anomaly dictionary, then exits
def display_all_anomalies():
    for key in anomaly_dictionary.keys():
        print(key, "\t-->", anomaly_dictionary[key])
    exit()

#handles user input: all given hashes and parameters            
def handle_user_input():
    global generated_path
    global all_set

    #if no parameters are given, display help function
    if len(sys.argv) == 1:
        help_function()

    for arg in range(1, len(sys.argv)):

        #handle path parameter
        if sys.argv[arg].startswith("-p="):
            generated_path = sys.argv[arg][3:]
            continue
        if sys.argv[arg].startswith("--path="):
            generated_path = sys.argv[arg][7:]
            continue
        
        #handle all parameter
        if sys.argv[arg] == "-a" or sys.argv[arg] == "--all":
            all_set = True
            continue
        
        #if its not a parameter -> append to list_of_anomalies
        list_of_anomalies.append(sys.argv[arg])

#compare key in anomaly dictionary with given hash and display app and name
def decode_anomaly():
    for anomaly in list_of_anomalies:
        if anomaly in anomaly_dictionary.keys():
            print(anomaly, "\t-->", anomaly_dictionary[anomaly])
        else:
            print(anomaly, "not defined")

def execute_special_parameters():
    if all_set: 
        display_all_anomalies()

handle_user_input()
get_all_anomalies()
execute_special_parameters()
decode_anomaly()