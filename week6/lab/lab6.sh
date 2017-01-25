#!/bin/bash

~cs1927/bin/assn2Model citiesLarge.data agentsA.data 100 0 > outA.txt
#results in the thief getting to the getaway destination in Hour 7.
~cs1927/bin/assn2Model citiesLarge.data agentsB.data 100 0 > outB.txt
#results detective 3 catching the thief in destination 6 in Hour 17.
