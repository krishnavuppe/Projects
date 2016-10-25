import time, sys, textwrap

f1 = open('1.txt','r')
f2 = open('2.txt','r')

c1=[]
c2=[]
c3=[]
message=[]
i=0


for r1 in f1:
    if len(r1) <45:
        c1.append(r1[13:15] + '.' + r1[16:18])
        message.append(r1[19: -2])
for r2 in f2:
    c2.append(r2[13:15] + '.' + r2[16:18])
    
    if(float(c2[i])>= float(c1[0]) and float(c2[i])<float(c1[1])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[1])
    elif(float(c2[i])>= float(c1[1]) and float(c2[i])<float(c1[2])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[2])
    elif(float(c2[i])>= float(c1[2]) and float(c2[i])<float(c1[3])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[3])
    elif(float(c2[i])>= float(c1[3]) and float(c2[i])<float(c1[4])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[4])
    elif(float(c2[i])>= float(c1[4]) and float(c2[i])<float(c1[5])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[5])
    elif(float(c2[i])>= float(c1[5]) and float(c2[i])<float(c1[6])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[6])
    elif(float(c2[i])>= float(c1[6]) and float(c2[i])<float(c1[7])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[7])
    elif(float(c2[i])>= float(c1[7]) and float(c2[i])<float(c1[8])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[8])
    elif(float(c2[i])>= float(c1[8]) and float(c2[i])<float(c1[9])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[9])
    elif(float(c2[i])>= float(c1[9]) and float(c2[i])<float(c1[10])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[10])
    elif(float(c2[i])>= float(c1[10]) and float(c2[i])<float(c1[11])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[11])
    elif(float(c2[i])>= float(c1[11]) and float(c2[i])<float(c1[12])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[12])
    elif(float(c2[i])>= float(c1[12]) and float(c2[i])<float(c1[13])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[13])
    elif(float(c2[i])>= float(c1[13]) and float(c2[i])<float(c1[14])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[4])
    elif(float(c2[i])>= float(c1[14]) and float(c2[i])<float(c1[15])):
        c3.append(r2[0:18] + ';' +r2[19:-1] + ',' + message[15])
    i += 1
    
with open('filteredoutput.txt','w') as g:
    x=[]
    for v in c3:
        x=v
        x=(textwrap.fill(x,200))
        g.write(x+'\n')
f1.close
g.close
