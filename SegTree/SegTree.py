tree = [0] * (2*size)
#n = size
  
def build(arr) : 
  
    for i in range(n) :  
        tree[n + i] = arr[i]
      
    for i in range(n - 1, 0, -1) :  
        tree[i] = tree[i << 1] + tree[i << 1 | 1] 
  
def updateTreeNode(p, value) :  
      
    tree[p + n] = value
    p = p + n
      
    i = p; 
      
    while i > 1 : 
          
        tree[i >> 1] = tree[i] + tree[i ^ 1] 
        i >>= 1
  
def query(l, r) :  
  
    res = 0
      
    l += n
    r += n
      
    while l < r : 
      
        if (l & 1) : 
            res += tree[l] 
            l += 1
      
        if (r & 1) : 
            r -= 1 
            res += tree[r] 
              
        l >>= 1
        r >>= 1
      
    return res