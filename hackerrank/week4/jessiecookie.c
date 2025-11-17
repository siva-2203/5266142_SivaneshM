int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int cookies(int k, int A_count, int* A)
{
    long ops=0;
    qsort(A,A_count,sizeof(int),compare);
    while(1)
    {
        if(A[0]>=k)return ops;
        if(A_count<2)return -1;
        int val=A[0]+2*A[1];
        for(int i=2;i<A_count;i++)
        {
            A[i-2]=A[i];
        }
        A_count-=1;
        int pos = A_count - 1;
        while (pos > 0 && A[pos - 1] > val) {
            A[pos] = A[pos - 1];
            pos--;
        }
        A[pos] = val;
        ops++;
    }
}

