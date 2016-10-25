##############################################################
###### A program that parse the verilog code          ########
###### given as input and change the digital gates    ########
###### used in the code into their equivalent netlist ########
###### with NAND and NOR gates realizations. As NAND  ########
###### and NOR are universal gates and can replace    ########
###### any digital gates and produce the required o/p ########
###### This would also increase the speed on FPGA     ########
######          Developed by krishna Vuppe            ########
##############################################################

import time, sys, textwrap
startTime = time.clock()
num_lines = sum(1 for item in open('block32 (1).v'))

clean_lines = []
with open("block32 (1).v", "r") as f:
    lines = f.readlines()
    clean_lines = [l.strip() for l in lines if l.strip()]

with open("ingenerated.v", "w") as f:
    f.writelines('\n'.join(clean_lines))

##########################################################
###### Block for joining lines in the input file  ########
##########################################################
f=open('ingenerated.v','r')
g=[]
r=0

for s in f:

    if s.find(';')<0 and s.find('wire')<0 and s.startswith('n')== False and s.find('endmodule')<0:
        l=[]
        l.append(s)
        r+=1

    elif r>0 and l[r-1].find(';')<0 and s.find(';')>0:
        l.append(s)
        g.append(l[r-1].rstrip() + ' ' + l[r].strip())
        r=0

    else:
        g.append(s)
        
with open('ingenerated.v','w') as m:
 for v in g:
     x=v
     m.write(x+'\n')

clean_lines = []
with open("ingenerated.v", "r") as f:
    lines = f.readlines()
    clean_lines = [l.strip() for l in lines if l.strip()]

with open("ingenerated.v", "w") as f:
    f.writelines('\n'.join(clean_lines))

f.close
m.close
#################################################################
##############          End of the block   ######################
#################################################################


#################################################################
#####  Block for finding the start and end of wires used  #######
#################################################################
f = open('ingenerated.v','r')
y=0
m=[]
y=[]
x=[]
for s in f:
   if (s.startswith('wire') or s.startswith('n')):
       m.append(s)
       m = [w.replace('n','') for w in m]
       m = [w.replace('wire','') for w in m]
       m = [w.replace(',','') for w in m]
       m = [w.replace(';','') for w in m]
       y = map(lambda s: s.strip(), m)
       for i in y:
         x.extend(i.split())
         zmin=min(x)
         zmax=max(x)
f.close

##################################################################
###################    End of the Block      #####################
##################################################################

##################################################################
################   Block for main functionality   ################
##################################################################
##
#For opening the input file
##
f=open('ingenerated.v','r')
##
#For finding the wire value to create new wires
##
##
#Variables used
##
r=1
r+=int(zmax)
r0=r1=r2=r3=r4=r5=r6=r7=r8=0
m=[]
##
#
##
##Defining a function for NAND3XL to NAND2X1 realization  #######

def NAND3XL():
    
    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A'))
    l.append(s[r0:r1-1])
    r2=(s.find('.B'))
    l.append(s[r1+2:r2])
    r3=(s.find('.C'))
    l.append(s[r2+2:r3])
    r4=(s.find('.Y'))
    l.append(s[r3+2:r4])
    r5=(s.find(';'))
    l.append(s[r4+2:r5-1])
    m.append('NAND2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'01'+' ( .A('+"".join([str('n')+str(r)])+')'+', .B('+"".join([str('n')+str(r)])+')'+', .Y('+"".join([str('n')+str(int(r)+1)])+')'+' );')
    m.append('NAND2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B'+l[4].rstrip()+' .Y'+l[5].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=0
    return;
##
#
##
# Defining a function for NAND2X1 to NAND2X1 realization
##
def NAND2X1():
    
    m.append(s)
    return;
##
#
##
# Defining a function for CLKINVX1 to NAND2X1 realization
##
def CLKINVX1():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A'))
    l.append(s[r0:r1-1])
    r2=(s.find('.Y'))
    l.append(s[r1+2:r2])
    r3=(s.find(';'))
    l.append(s[r2+2:r3-1])
    m.append('NAND2X1 '+l[1].rstrip()+' ( .A'+l[2].rstrip()+' .B'+l[2].rstrip()+' .Y'+l[3].rstrip()+' );')
    r0=r1=r2=r3=0
    return;
##
#
##
# Defining a function for OAI22XL to NAND2X1 realization
##
def OAI22XL():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2])
    r3=(s.find('.B0'))
    l.append(s[r2+3:r3])
    r4=(s.find('.B1'))
    l.append(s[r3+3:r4])
    r5=(s.find('.Y'))
    l.append(s[r4+3:r5])
    r6=(s.find(';'))
    l.append(s[r5+2:r6-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A'+l[4].rstrip()+' .B'+l[5].rstrip()+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(r)])+'), .B('+"".join([str('n')+str(r)])+'),'+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B('+"".join([str('n')+str(int(r)+1)])+'),'+' .Y('+"".join([str('n')+str(int(r)+3)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+2)])+'), .B('+"".join([str('n')+str(int(r)+3)])+'),'+' .Y'+l[6].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=r6=0
    return;
##
#
##
# Defining a function for OAI221X1 to NAND2X1 realization
##
def OAI221X1():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2])
    r3=(s.find('.B0'))
    l.append(s[r2+3:r3])
    r4=(s.find('.B1'))
    l.append(s[r3+3:r4])
    r5=(s.find('.C0'))
    l.append(s[r4+3:r5])
    r6=(s.find('.Y'))
    l.append(s[r5+3:r6])
    r7=(s.find(';'))
    l.append(s[r6+2:r7-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A'+l[4].rstrip()+' .B'+l[5].rstrip()+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(r)])+'), .B('+"".join([str('n')+str(r)])+'),'+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B('+"".join([str('n')+str(int(r)+1)])+'),'+' .Y('+"".join([str('n')+str(int(r)+3)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+2)])+'), .B('+"".join([str('n')+str(int(r)+3)])+'),'+' .Y('+"".join([str('n')+str(int(r)+4)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'05'+' ( .A('+"".join([str('n')+str(int(r)+4)])+'), .B('+"".join([str('n')+str(int(r)+4)])+'),'+' .Y('+"".join([str('n')+str(int(r)+5)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'06'+' ( .A('+"".join([str('n')+str(int(r)+5)])+'), .B'+l[6].rstrip()+' .Y'+l[7].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=r6=r7=0
    return;
##
#
##
# Defining a function for OAI21XL to NAND2X1 realization
##
def OAI21XL():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2])
    r3=(s.find('.B0'))
    l.append(s[r2+3:r3])
    r4=(s.find('.Y'))
    l.append(s[r3+4:r4])
    r5=(s.find(';'))
    l.append(s[r4+2:r5-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A('+"".join([str('n')+str(r)])+'), .B('+"".join([str('n')+str(r)])+'),'+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B('+l[4].rstrip()+' .Y'+l[5].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=0
    return;
##
#
##
# Defining a function for OAI2BB1X1 to NAND2X1 realization
##
def OAI2BB1X1():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0N'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1N'))
    l.append(s[r1+4:r2])
    r3=(s.find('.B0'))
    l.append(s[r2+4:r3])
    r4=(s.find('.Y'))
    l.append(s[r3+4:r4])
    r5=(s.find(';'))
    l.append(s[r4+2:r5-1])
    m.append('NAND2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[2].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'01'+' ( .A'+l[3].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(r)])+'), .B('+"".join([str('n')+str(int(r)+1)])+'),'+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+2)])+'), .B('+"".join([str('n')+str(int(r)+2)])+'),'+' .Y('+"".join([str('n')+str(int(r)+3)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+3)])+'), .B('+l[4].rstrip()+' .Y'+l[5].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=0
    return;
##
#
##
# Defining a function for OAI211XL to NAND2X1 realization
##
def OAI211XL():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2])
    r3=(s.find('.B0'))
    l.append(s[r2+3:r3])
    r4=(s.find('.C0'))
    l.append(s[r3+3:r4])
    r5=(s.find('.Y'))
    l.append(s[r4+3:r5])
    r6=(s.find(';'))
    l.append(s[r5+2:r6-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A('+"".join([str('n')+str(r)])+'), .B('+"".join([str('n')+str(r)])+'),'+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B'+l[4].rstrip()+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+2)])+'), .B('+"".join([str('n')+str(int(r)+2)])+'),'+' .Y('+"".join([str('n')+str(int(r)+3)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+3)])+'), .B'+l[5].rstrip()+' .Y'+l[6].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=r6=0
    return;
##
#
##
# Defining a function for NOR2XL to NOR2X1 realization
##
def NOR2XL():
    
    m.append(s)
    return;
##
#
##
# Defining a function for OAI33X1 to NAND2X1 realization
##
def OAI33X1():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2])
    r3=(s.find('.A2'))
    l.append(s[r2+3:r3])
    r4=(s.find('.B0'))
    l.append(s[r3+3:r4])
    r5=(s.find('.B1'))
    l.append(s[r4+3:r5])
    r6=(s.find('.B2'))
    l.append(s[r5+3:r6])
    r7=(s.find('.Y'))
    l.append(s[r6+3:r7])
    r8=(s.find(';'))
    l.append(s[r7+2:r8-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A'+l[5].rstrip()+' .B'+l[6].rstrip()+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(r)])+'), .B('+"".join([str('n')+str(r)])+'),'+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B('+"".join([str('n')+str(int(r)+1)])+'),'+' .Y('+"".join([str('n')+str(int(r)+3)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+2)])+'), .B'+l[4].rstrip()+' .Y('+"".join([str('n')+str(int(r)+4)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'05'+' ( .A('+"".join([str('n')+str(int(r)+3)])+'), .B'+l[7].rstrip()+' .Y('+"".join([str('n')+str(int(r)+5)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'06'+' ( .A('+"".join([str('n')+str(int(r)+4)])+'), .B('+"".join([str('n')+str(int(r)+4)])+'),'+' .Y('+"".join([str('n')+str(int(r)+6)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'07'+' ( .A('+"".join([str('n')+str(int(r)+5)])+'), .B('+"".join([str('n')+str(int(r)+5)])+'),'+' .Y('+"".join([str('n')+str(int(r)+7)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'08'+' ( .A('+"".join([str('n')+str(int(r)+6)])+'), .B('+"".join([str('n')+str(int(r)+7)])+'),'+' .Y'+l[8].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=r6=r7=r8=0
    return;
##
#
##
# Defining a function for XNOR2XL to NOR2X1 realization
##
def XNOR2XL():
    
    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A'))
    l.append(s[r0:r1-1])
    r2=(s.find('.B'))
    l.append(s[r1+2:r2])
    r3=(s.find('.Y'))
    l.append(s[r2+2:r3])
    r4=(s.find(';'))
    l.append(s[r3+2:r4-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A'+l[2].rstrip()+' .B('+"".join([str('n')+str(r)])+'),'+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(r)])+')'+', .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B('+"".join([str('n')+str(int(r)+2)])+'),'+' .Y'+l[4].rstrip()+' );')
    r0=r1=r2=r3=r4=0
    return;
##
#
##
# Defining a function for AOI32X1 to NAND2X1 realization
##
def AOI32X1():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2])
    r3=(s.find('.A2'))
    l.append(s[r2+3:r3])
    r4=(s.find('.B0'))
    l.append(s[r3+3:r4])
    r5=(s.find('.B1'))
    l.append(s[r4+3:r5])
    r6=(s.find('.Y'))
    l.append(s[r5+3:r6])
    r7=(s.find(';'))
    l.append(s[r6+2:r7-1])
    m.append('NAND2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'01'+' ( .A'+l[5].rstrip()+' .B'+l[6].rstrip()+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(r)])+'), .B('+"".join([str('n')+str(r)])+'),'+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B('+"".join([str('n')+str(int(r)+1)])+'),'+' .Y('+"".join([str('n')+str(int(r)+3)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+2)])+'), .B'+l[4].rstrip()+' .Y('+"".join([str('n')+str(int(r)+4)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'05'+' ( .A('+"".join([str('n')+str(int(r)+4)])+'), .B('+"".join([str('n')+str(int(r)+4)])+'),'+' .Y('+"".join([str('n')+str(int(r)+5)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'06'+' ( .A('+"".join([str('n')+str(int(r)+5)])+'), .B('+"".join([str('n')+str(int(r)+3)])+'),'+' .Y'+l[7].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=r6=r7=0
    return;
##
#
##
# Defining a function for OAI32X1 to NAND2X1 realization
##
def OAI32X1():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2])
    r3=(s.find('.A2'))
    l.append(s[r2+3:r3])
    r4=(s.find('.B0'))
    l.append(s[r3+3:r4])
    r5=(s.find('.B1'))
    l.append(s[r4+3:r5])
    r6=(s.find('.Y'))
    l.append(s[r5+3:r6])
    r7=(s.find(';'))
    l.append(s[r6+2:r7-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A'+l[5].rstrip()+' .B'+l[6].rstrip()+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(r)])+'), .B('+"".join([str('n')+str(r)])+'),'+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B('+"".join([str('n')+str(int(r)+1)])+'),'+' .Y('+"".join([str('n')+str(int(r)+3)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+2)])+'), .B'+l[4].rstrip()+' .Y('+"".join([str('n')+str(int(r)+4)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'05'+' ( .A('+"".join([str('n')+str(int(r)+4)])+'), .B('+"".join([str('n')+str(int(r)+4)])+'),'+' .Y('+"".join([str('n')+str(int(r)+5)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'06'+' ( .A('+"".join([str('n')+str(int(r)+5)])+'), .B('+"".join([str('n')+str(int(r)+3)])+'),'+' .Y'+l[7].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=r6=r7=0
    return;
##
#
##
# Defining a function for CLKINVX1 to NAND2X1 realization
##
def INVX2():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A'))
    l.append(s[r0:r1-1])
    r2=(s.find('.Y'))
    l.append(s[r1+2:r2])
    r3=(s.find(';'))
    l.append(s[r2+2:r3-1])
    m.append('NAND2X1 '+l[1].rstrip()+' ( .A'+l[2].rstrip()+' .B'+l[2].rstrip()+' .Y'+l[3].rstrip()+' );')
    r0=r1=r2=r3=0
    return;
##
#
##
# Defining a function for OAI31X1 to NAND2X1 realization
##
def OAI31X1():

    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2])
    r3=(s.find('.A2'))
    l.append(s[r2+3:r3])
    r4=(s.find('.B0'))
    l.append(s[r3+3:r4])
    r5=(s.find('.Y'))
    l.append(s[r4+3:r5])
    r6=(s.find(';'))
    l.append(s[r5+2:r6-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A('+"".join([str('n')+str(r)])+'), .B('+"".join([str('n')+str(r)])+'),'+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'),'+' .B'+l[4].rstrip()+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')

    m.append('NOR2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+2)])+'), .B('+"".join([str('n')+str(int(r)+2)])+'),'+' .Y('+"".join([str('n')+str(int(r)+3)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+3)])+'), .B'+l[5].rstrip()+' .Y'+l[6].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=r6=0
    return;
##
#
def OAI2BB2X1():
    
    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.B0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.B1'))
    l.append(s[r1+3:r2-1])
    r3=(s.find('.A0N'))
    l.append(s[r2+3:r3-1])
    r4=(s.find('.A1N'))
    l.append(s[r3+4:r4-1])
    r5=(s.find('.Y'))
    l.append(s[r4+4:r5-1])
    r6=(s.find(';'))
    l.append(s[r5+2:r6-1])
    
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+', .B'+l[2].rstrip()+', .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A'+l[3].rstrip()+', .B'+l[3].rstrip()+', .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(r)])+')'+', .B('+"".join([str('n')+str(int(r)+1)])+')'+', .Y('+"".join([str('n')+str(int(r)+2)])+')'+' );')
    m.append('NOR2X1 '+l[1].rstrip()+'03'+' ( .A'+l[4].rstrip()+', .B'+l[5].rstrip()+', .Y('+"".join([str('n')+str(int(r)+3)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+2)])+')'+', .B('+"".join([str('n')+str(int(r)+2)])+')'+', .Y('+"".join([str('n')+str(int(r)+4)])+')'+' );')
    m.append('NOR2X1 '+l[1].rstrip()+'05'+' ( .A('+"".join([str('n')+str(int(r)+3)])+')'+', .B('+"".join([str('n')+str(int(r)+3)])+')'+', .Y('+"".join([str('n')+str(int(r)+5)])+')'+' );')
    m.append('NAND2X1 '+l[1].rstrip()+'06'+' ( .A('+"".join([str('n')+str(int(r)+4)])+')'+', .B('+"".join([str('n')+str(int(r)+5)])+')'+', .Y'+l[6].rstrip()+' );')

    r0=r1=r2=r3=r4=r5=r6=0
    return;
##
#
def AOI21X1():
    
    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2-1])
    r3=(s.find('.B0'))
    l.append(s[r2+3:r3-1])
    r4=(s.find('.Y'))
    l.append(s[r3+3:r4-1])
    r5=(s.find(';'))
    l.append(s[r4+2:r5-1])
    
    m.append('NAND2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+', .B'+l[3].rstrip()+', .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'01'+' ( .A('+"".join([str('n')+str(r)])+')'+', .B('+"".join([str('n')+str(r)])+')'+', .Y('+"".join([str('n')+str(int(r)+1)])+')'+' );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B'+l[4].rstrip()+', .Y'+l[5].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=0
    return;
##
#
def AOI31X1():
    
    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+3:r2])
    r3=(s.find('.A2'))
    l.append(s[r2+3:r3])
    r4=(s.find('.B0'))
    l.append(s[r3+3:r4])
    r5=(s.find('Y'))
    l.append(s[r4+3:r5-1])
    r6=(s.find(';'))
    l.append(s[r5+1:r6-1])
    
    m.append('NAND2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'01'+' ( .A('+"".join([str('n')+str(r)])+')'+', .B('+"".join([str('n')+str(r)])+')'+', .Y('+"".join([str('n')+str(int(r)+1)])+')'+' );')
    m.append('NAND2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B'+l[4].rstrip()+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+2)])+')'+', .B('+"".join([str('n')+str(int(r)+2)])+')'+', .Y('+"".join([str('n')+str(int(r)+3)])+')'+' );')
    m.append('NOR2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+3)])+'), .B'+l[5].rstrip()+' .Y'+l[6].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=r6=0
    return;
##
#
def NOR3XL():
    
    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A'))
    l.append(s[r0:r1-1])
    r2=(s.find('.B'))
    l.append(s[r1+2:r2])
    r3=(s.find('.C'))
    l.append(s[r2+2:r3])
    r4=(s.find('.Y'))
    l.append(s[r3+2:r4])
    r5=(s.find(';'))
    l.append(s[r4+2:r5-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A('+"".join([str('n')+str(r)])+')'+', .B('+"".join([str('n')+str(r)])+')'+', .Y('+"".join([str('n')+str(int(r)+1)])+')'+' );')
    m.append('NOR2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B'+l[4].rstrip()+' .Y'+l[5].rstrip()+' );')
    r0=r1=r2=r3=r4=r5=0
    return;
##
#
def AOI2BB1X1():
    
    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A0'))
    l.append(s[r0:r1-1])
    r2=(s.find('.A1'))
    l.append(s[r1+4:r2-1])
    r3=(s.find('.B0'))
    l.append(s[r2+4:r3-1])
    r4=(s.find('.Y'))
    l.append(s[r3+3:r4-1])
    r5=(s.find(';'))
    l.append(s[r4+2:r5-1])
    m.append('NAND2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+', .B'+l[2].rstrip()+', .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'01'+' ( .A'+l[3].rstrip()+', .B'+l[3].rstrip()+', .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'02'+' ( .A('+"".join([str('n')+str(r)])+')'+', .B('+"".join([str('n')+str(int(r)+1)])+')'+', .Y('+"".join([str('n')+str(int(r)+2)])+')'+' );')
    m.append('NOR2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+3)])+'), .B'+l[4].rstrip()+', .Y'+l[5].rstrip()+' );')
    m.append('NAND2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+2)])+')'+', .B('+"".join([str('n')+str(int(r)+2)])+')'+', .Y('+"".join([str('n')+str(int(r)+3)])+')'+' );')
    r0=r1=r2=r3=r4=r5=0
    return;
##
#
def OR2X2():
    
    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A'))
    l.append(s[r0:r1-1])
    r2=(s.find('.B'))
    l.append(s[r1+2:r2])
    r3=(s.find('.Y'))
    l.append(s[r2+2:r3])
    r4=(s.find(';'))
    l.append(s[r3+2:r4-1])
    m.append('NOR2X1 '+l[1].rstrip()+'00'+' ( .A'+l[2].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NOR2X1 '+l[1].rstrip()+'01'+' ( .A('+"".join([str('n')+str(r)])+')'+', .B('+"".join([str('n')+str(r)])+')'+', .Y'+l[4].rstrip()+' );') 
             
    r0=r1=r2=r3=r4=r5=0
    return;
##
#
def MXI2XL():
    
    r0=(s.find('U'))
    l.append(s[0:r0])
    r1=(s.find('.A'))
    l.append(s[r0:r1-1])
    r2=(s.find('.B'))
    l.append(s[r1+2:r2])
    r3=(s.find('.S0'))
    l.append(s[r2+2:r3])
    r4=(s.find('.Y'))
    l.append(s[r3+3:r4])
    r5=(s.find(';'))
    l.append(s[r4+2:r5-1])
    
    m.append('NAND2X1 '+l[1].rstrip()+'00'+' ( .A'+l[4].rstrip()+' .B'+l[3].rstrip()+' .Y('+"".join([str('n')+str(r)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'01'+' ( .A('+"".join([str('n')+str(r)])+')'+', .B('+"".join([str('n')+str(r)])+')'+', .Y('+"".join([str('n')+str(int(r)+4)])+')'+' );')
    m.append('NAND2X1 '+l[1].rstrip()+'02'+' ( .A'+l[4].rstrip()+' .B'+l[4].rstrip()+' .Y('+"".join([str('n')+str(int(r)+1)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'03'+' ( .A('+"".join([str('n')+str(int(r)+1)])+'), .B'+l[2].rstrip()+' .Y('+"".join([str('n')+str(int(r)+2)])+') );')
    m.append('NAND2X1 '+l[1].rstrip()+'04'+' ( .A('+"".join([str('n')+str(int(r)+2)])+')'+', .B('+"".join([str('n')+str(int(r)+2)])+')'+', .Y('+"".join([str('n')+str(int(r)+3)])+')'+' );')
    m.append('NOR2X1 '+l[1].rstrip()+'05'+' ( .A('+"".join([str('n')+str(int(r)+3)])+')'+', .B('+"".join([str('n')+str(int(r)+4)])+')'+', .Y'+l[5].rstrip()+' );')    
    r0=r1=r2=r3=r4=r5=0
    return;
##
#
##
# Creating a for loop for accessing each line in the file
for s in f:

    if s.find("NAND3XL")> -1:
       s=s.replace(" ","")
       l=[]
       NAND3XL()
       r+=2

    elif s.find("NAND2X1")> -1:
       NAND2X1()

    elif s.find("CLKINVX1")> -1:
       s=s.replace(" ","")
       l=[]
       CLKINVX1()

    elif s.find("OAI22XL")> -1:
       s=s.replace(" ","")
       l=[]
       OAI22XL()
       r+=4
       
    elif s.find("OAI221X1")> -1:
       s=s.replace(" ","")
       l=[]
       OAI221X1()
       r+=6
       
    elif s.find("OAI21XL")> -1:
       s=s.replace(" ","")
       l=[]
       OAI21XL()
       r+=2
       
    elif s.find("OAI2BB1X1")> -1:
       s=s.replace(" ","")
       l=[]
       OAI2BB1X1()
       r+=4
       
    elif s.find("OAI211XL")> -1:
       s=s.replace(" ","")
       l=[]
       OAI211XL()
       r+=4

    elif s.find("OAI33X1")> -1:
       s=s.replace(" ","")
       l=[]
       OAI33X1()
       r+=8
       
    elif s.find("XNOR2XL")> -1:
       s=s.replace(" ","")
       l=[]
       XNOR2XL()
       r+=3

    elif s.find("NOR2XL")> -1:
       s=s.replace("NOR2XL","NOR2X1")
       NOR2XL()

    elif s.find("AOI32X1")> -1:
       s=s.replace(" ","")
       l=[]
       AOI32X1()
       r+=6
       
    elif s.find("OAI32X1")> -1:
       s=s.replace(" ","")
       l=[]
       OAI32X1()
       r+=6
       
    elif s.find("INVX2")> -1:
       s=s.replace(" ","")
       l=[]
       INVX2()
       
    elif s.find("OAI31X1")> -1:
       s=s.replace(" ","")
       l=[]
       OAI31X1()
       r+=4
       
    elif s.find("OAI2BB2X1")>-1:
        s=s.replace(" ","")
        l=[]
        OAI2BB2X1()
        r+=6
        
    elif s.find("AOI21X1")>-1:
        s=s.replace(" ","")
        l=[]
        AOI21X1()
        r+=2
        
    elif s.find("AOI31X1")>-1:
        s=s.replace(" ","")
        l=[]
        AOI31X1()
        r+=4
        
    elif s.find("NOR3XL")>-1:
        s=s.replace(" ","")
        l=[]
        NOR3XL()
        r+=2

    elif s.find("AOI2BB1X1")>-1:
        s=s.replace(" ","")
        l=[]
        AOI2BB1X1()
        r+=4
        
    elif s.find("OR2X2")>-1:
        s=s.replace(" ","")
        l=[]
        OR2X2()
        r+=1

    elif s.find("MXI2XL")>-1:
        s=s.replace(" ","")
        l=[]
        MXI2XL()
        r+=5

    else:
        m.append(s)
       
##
#
##
#
   

##
# for generating output file
with open('out.v','w') as g:
 for v in m:
     x=v
     g.write(x+'\n')
##
# For cleaning the spaces in the file
clean_lines = []
with open("out.v", "r") as f:
    lines = f.readlines()
    clean_lines = [l.strip() for l in lines if l.strip()]

with open("out.v", "w") as f:
    f.writelines('\n'.join(clean_lines))
##
#
##
# Closing the files
g.close
f.close
  
##################################################
#########  End of Main functionaility  ###########
##################################################


##################################################
##### Block for adding new wires generated #######
##################################################

f=open('out.v','r')
m=[]
n=[]
k=[]
l=[]
xx=r
for e in range((int(zmin)),(int(r))):
    n.append("".join([str(' n')+str(e)+str(',')]))
    q=[]
    q.append('wire '.rstrip())
    q.append(''.join(n + ['']).rstrip(' '))
    q.append(";")
    k=(''.join(q + ['']).rstrip(' '))
    k=k.replace(",;",";")

for r in f:

    if r.find('wire')>-1:
        m.append(k)

    elif r.startswith('n')== True:
        l.append(r)
    else:
        m.append(r)

##
# for generating output file and textwrapping
##
with open('out.v','w') as g:
 for v in m:
     x=v
     x=(textwrap.fill(x,130))
     g.write(x+'\n')

##
## Text wrap
   
# For cleaning the spaces in the file
clean_lines = []
with open("out.v", "r") as f:
    lines = f.readlines()
    clean_lines = [l.strip() for l in lines if l.strip()]

with open("out.v", "w") as f:
    f.writelines('\n'.join(clean_lines))
##
#
##
# Closing the files
g.close
f.close
################################################
###########    Time calculation   ##############
################################################

Endtime = time.clock()
Totaltime =  Endtime - startTime
print ("Verilog netlist conversion")
print ("-using Python version", sys.version)
print ("Total conversion time:", Totaltime)
print ("Total source lines:", num_lines)
print ("Total number of new wires added:", int(xx) - int(zmax))
print ("Average lines/sec:", ( "%.1f" % (float(num_lines)/(Totaltime+.05 ) ) ))

#####################################################################
############-------------    The End       ----------################
#####################################################################
