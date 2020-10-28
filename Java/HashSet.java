package com.company;

class MyHashSet {

    int x;
    int y;
    int[] a = new int[10000];
    int length = 0;
    /** Initialize your data structure here. */
    public MyHashSet()
    {

    }

    public void add(int key)
    {
        a[length] = key;
        ++length;
    }

    public void remove(int key)
    {
        length = a.length-1;
        int c;
        for(int i=0;i<a.length;i++)
        {
            if(key == a[i])
            {
                c = i;
                if(c==a.length-1)
                {
                    length--;
                }
                else
                {
                    for(int j = c;j<a.length-1;j++)
                    {
                        a[j] = a[j+1];
                        length--;
                    }
                }

            }
        }






    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key)
    {
        boolean var = false;
        for(int i = 0;i<a.length;i++)
        {
            if(key == a[i])
            {
                var = true;
            }
        }
        return var;
    }
}