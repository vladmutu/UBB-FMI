# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def cmmdc(a,b):
    if b==0:
        return a
    else:
        return cmmdc(b,a%b)

print(cmmdc(15,6))