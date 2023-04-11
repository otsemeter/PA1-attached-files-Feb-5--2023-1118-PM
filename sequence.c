#include "sequence.h"
#include<stdlib.h>
#include<stdio.h>

static int log_2(int n)
{
    int logn = 0;

    while(n > 1)
    {
        n /= 2;
        logn++;
    }
    return logn;
}
long *Generate_2p3q_Seq(int n, int *seq_size)
{
    int i = 0; //sequence itterator
    int ind2 = 0; //index for base_2 depth in sequence
    int ind3 = 0; //index for base_3 depth in sequence
    int curr2 = 1; //current base_2 value initialized as 1
    int curr3 = 1; //current base_3 value initialized as 1
    int log_n = 0; //to store the log base_2 of n (array length)
    
    //base case array too small for any sequence
    //still allocate memory for sequence
    if(n <= 1)
    {
        *seq_size = 0;
        long* seq_2p3q= (long*)malloc(sizeof(long) * (*seq_size));
        return seq_2p3q;
    }

    //initialize log_n
    //and set sequence size to log_n^2 (approximated length)
    log_n = log_2(n);
    (*seq_size) = log_n * log_n;

    //allocate memory for sequence and initialize first value to 1 
    long *seq_2p3q = (long*)malloc(sizeof(long) * (*seq_size));
    seq_2p3q[0] = 1;

    //itterate over empty sequence, filling indecies with product
    //of current base_2 and base_3 values, setting each of curr2 and curr3
    //to be their respective previous values times their base
    //using the conditional find the lesser of the two and set the current value of
    //the sequence accordingly, then finding the minimum 
    //of each, and itterating the index of the smaller
    while(seq_2p3q[i] < n)
    {
        i++;
        curr2 = seq_2p3q[ind2] * 2;
        curr3 = seq_2p3q[ind3] * 3;
        (curr2 <= curr3)? (seq_2p3q[i] = curr2): (seq_2p3q[i] = curr3);
        ind2 += (curr2 <= curr3);
        ind3 += (curr3 <= curr2);
    }

    //set seq_size to actual sequence size, determined by itterator i
    *seq_size = i;

    //return statement
    return seq_2p3q;
    
}//end Generate_2p3q_Seq()