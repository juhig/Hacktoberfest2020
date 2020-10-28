class Solution
{
    long minValueToBalance(long a[] ,int n)
    {
        int sum1=0;
        for(int i=0;i<n/2;i++){
            sum1+=a[i];
        }
    int sum2=0;
    for(int i=n/2;i<n;i++){
        sum2+=a[i];
    }
return Math.abs(sum2- sum1);
    }
}
