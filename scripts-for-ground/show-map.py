#!/bin/python3

#Author: Konstantin Winkel

import argparse
import matplotlib.pyplot as plt
import math


list_of_objects = {}
parser = argparse.ArgumentParser(
                    prog="show-map",
                    description="shows a map of all objects found by the floatsat")

parser.add_argument('-m', '--map', help="use last entry of map telemetry instead of individual objects", action='store_true') 

args = parser.parse_args()

def readMapExtTM():
    global list_of_objects
    global args

    if args.map is False:
        return
    
    file = open("../TM/rpi-connectorEXTListOfObjects.tm") # TODO check if correct
    lines = file.readlines()
    elements = lines[-1].strip().split(", ") # only interested in the elements of last line
    
    current_object_data = ["", 0, 0]
    current_index = 0

    for element in elements:
        if current_index == 0:
            current_index += 1
            continue

        current_object_data[(current_index-1) % 3] = element

        if current_index % 3 == 0:
            current_object_data[1] = float(current_object_data[1])
            current_object_data[2] = float(current_object_data[2])

            list_of_objects[current_object_data[1]] = current_object_data[0]
        
        current_index += 1


def readObjectExtTM():
    global list_of_objects
    global args

    if args.map is True:
        return

    file = open("../TM/rpi-connectorEXTrpiData.tm") # TODO check if correct
    lines = file.readlines()

    for line in lines:
        elements = line.strip().split(", ")
        #print(elements[2], elements[3])
        
        if elements[1] != "Done ":
            continue
        list_of_objects[float(elements[3])] = elements[2]

def createMap():
    global list_of_objects

    circle1 = plt.Circle((0, 0), 1, color='black', fill=False)

    fig, ax = plt.subplots(figsize=(10,10)) # note we must use plt.subplots, not plt.subplot
    ax.add_patch(circle1)

    for key in list_of_objects.keys():
        if list_of_objects[key] == "No Object ":
            continue
        angle = key * math.pi/180.0

        plt.plot(math.cos(angle), math.sin(angle), marker='x', color='r',markersize=10.0)
        if (math.fabs(angle) > 3/2 * math.pi) or (math.fabs(angle) < 1/2 * math.pi):
            plt.text(1.1 * math.cos(angle), 1.1 * math.sin(angle), list_of_objects[key])
        else:
            plt.text(1.1 * math.cos(angle), 1.1 * math.sin(angle), list_of_objects[key], horizontalalignment='right')

    plt.axis((-2, 2, -2, 2))
    plt.title("Position of Found Objects")
    plt.show()

readMapExtTM()
readObjectExtTM()
createMap()