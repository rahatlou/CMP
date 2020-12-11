import sys, os

print("Running "+__file__)

print("Running "+os.path.basename(__file__))


print("program called with %d arguments"%len(sys.argv))

for a in sys.argv:
    print(a)
