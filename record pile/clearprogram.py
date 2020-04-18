f1 = open("1123.txt", "r")
f2 = open("11231.txt","r")
f3 = open("11232.txt","w")
barcode=f1.read().split()
time=f2.read().split()
record = []
z=0

def prtime(x):
    hou=x[:2]
    minute=x[2:4]
    t=int(x[-1])
    if t==0: f3.write("%s %s Toilet\n" %(hou, minute))
    elif t==1: f3.write("%s %s Water\n" %(hou, minute))
    elif t==2: f3.write("%s %s Sangdam\n" %(hou, minute))

for i in barcode:
    a=i[4:]
    if len(record)!=0:
        for j in record:
            if j==a:
                record.remove(a)
                prtime(time[z])
                z+=1
        else:
            record.append(a)
    else:
        record.append(a)

f1.close()
f2.close()
f3.close()
