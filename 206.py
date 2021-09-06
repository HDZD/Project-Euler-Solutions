def sq(x):
    return x*x

def check(x):
    s = str(x)
    ref = '1_2_3_4_5_6_7_8_9_0'
    if (len(s) > len(ref)):
        print ("too far")
        quit()
    i = 0
    while i < 19:
        if (s[i] != ref[i]): return False
        i+=2
    return True

try:
    i = 1274665290
    while (not check(sq(i))):
        i+=2
except KeyboardInterrupt:
    print ("\n")
    print(i)
    raise

print (i)
print (sq(i))