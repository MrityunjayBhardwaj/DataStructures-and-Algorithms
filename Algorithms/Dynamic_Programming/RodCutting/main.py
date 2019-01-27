"""
TODO: fetch the cutting route also.

CalcRodVal():

    valTable = [[]]

    let cvals = [] // array contains currently evaluated values
    let cuttingPattern = [];

    for i in range(rodlen):# i is our cut of rodlen @i
        let len1  = i;
        let len2  = rodlen-i;

        let  l1val = 0;
        let l2val = 0;

        if (len1 in valTable)l1val = valtable[0][len1] // considering it as a plain rod of len: len1
        # else l1val = CalcRodVal(len1)

        if (len2 in valTable)l2val = valtable[rodlen][len2]
        else l2val = CalcRodVal(len2)
        cvals.push(l1val + l2val);

        valTable[rodlen][i] = l1val + v2val;

    return find_max(cvals);

"""


def evalrev(cpos,rlen,lut):
# cpos : cut position
# rlen : rod length
# lut  : lookuptable

    # looking up
    return lut[cpos-1] + lut[cpos - cpos-1] # "-1" because index starts at 0 and our value starts at 1;

valtable = [[]] # contains the values
# where p is the cost of cutting rod of length "x" at "y"
# x1->   1   2   3   4   5
# x2___________________________
# 0| p  .  ... .  . . . . ..  .
# 1| p  .  ... .  . . . . ..  .
# 2| p  .  ... .  . . . . ..  .
# 3| p  .  ... .  . . . . ..  .

def find_max_index(arr):
    a =  max(arr);
    for i in range(arr.length):
        if (arr[i] == a):return i;

# so if we want to find the best possible route to cut the rod. then just keep backtracking untill you reach 1length rod

def CalcRodVal(rodlen,valtable):


    cvals = [] # array contains currently evaluated values
    cuttingPattern = [];

    cuttingthisrod = [];
    for i in range(rodlen):# i is our cut of rodlen @i
        len1  = i;
        len2  = rodlen-i;

        l1val = 0;
        l2val = 0;

        l1val = valtable[rodlen][len1][0];

        if (len2 in valtable):l2val = valtable[rodlen][len2][0]
        else: 
            val = CalcRodVal(len2)
            l2val = val[0]
            valtable[rodlen][i][1] = val[1];

        cvals.push(l1val + l2val);

        valtable[rodlen][i][0] = l1val + l2val;

        cuttingPattern.push(i);


    mxvalindex = find_max_index(cvals)
    cuttingthisrod = cuttingPattern[mxvalindex] # so this is the best cutting pattern
    if (rodlen == 1): cuttingthisrod = 0

    return [max(cvals),cuttingthisrod];



def main():
    rcprice = [1,4,5,8,15];
    rodlen = 4
    myrev = [[0]*rodlen]*rodlen;# creating a LUT;
    RodCutting(rodlen,rcprice,myrev);


if __name__ == '__main__':
    main();
    
