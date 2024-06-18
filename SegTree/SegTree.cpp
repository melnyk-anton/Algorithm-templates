int tree[2*size]; 
//n = size

void build( int arr[])  
{  
    for (int i=0; i<n; i++)     
        tree[n+i] = arr[i]; 
      
    for (int i = n - 1; i > 0; --i)      
        tree[i] = tree[i<<1] + tree[i<<1 | 1];     
} 
  
void updateTreeNode(int p, int value)  
{  
    tree[p+n] = value; 
    p = p+n; 
      
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
} 
  
int query(int l, int r)  
{  
    int res = 0; 
      
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res += tree[l++]; 
      
        if (r&1)  
            res += tree[--r]; 
    } 
      
    return res; 
} 