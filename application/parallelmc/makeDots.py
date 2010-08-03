import sys
import os

fp = open(sys.argv[1], 'r')

counts = [0 for i in xrange(int(sys.argv[2]))]

for line in fp:
    (proc, count) = line.split(' ')
    proc = int(proc)
    count = int(count)

    counts[proc - 1] = count

    for i in xrange(len(counts)):
        print "%d: " % (i + 1),
        
        for j in xrange(counts[i]):
            print "%d " % (j + 1),
        
        print ""

    dummy = raw_input("Enter for more ...")
    os.system("clear")
