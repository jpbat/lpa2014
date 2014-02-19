#!/usr/bin/env python

import random

def generate():

	n = random.randint(1, 60)
	
	print n

	times = [(random.random() * 1000) for i in range(n)]

	times.sort()
	for t in times:
		print t

def main():
	for i in xrange(1000):
		generate()


if __name__ == '__main__':
	main()
