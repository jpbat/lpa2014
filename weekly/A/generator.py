#!/usr/bin/env python

from random import randint, sample
from math import ceil

def generate(nNodes, stringSize):

	nTerminals = randint(1, nNodes)
	terminals = sample([i for i in range(nNodes)], nTerminals)
	
	print nNodes, stringSize

	for i in xrange(nNodes):
		node1 = randint(1, nNodes)
		node2 = randint(1, nNodes)

		if i in terminals:
			print node1, node2, '*'
		else:
			print node1, node2

def main():

	for i in xrange(999):

		nNodes = randint(1,20)
		stringSize = randint(1,30)

		generate(nNodes, stringSize)
	
	generate(20,30)


if __name__ == '__main__':
	main()
