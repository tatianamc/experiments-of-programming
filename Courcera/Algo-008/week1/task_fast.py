with open('IntegerArray.txt', 'r') as f:
	read_data = [int(x) for x in f.read().splitlines()]  #readlines()#f.read()
	f.closed

count = 0

N = len(read_data)

def merge_sort(A,p,r):
    if(p<r):
        q = (p+r)//2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    return A;

def merge(A, p , q, r):
    "A массив p - левый индекс, q - центральный, r - правый"
    n1 = q - p + 1;
    n2 = r - q;
    #print("n1n2: " , n1,n2);

    L = [None] * (n1 + 1);
    R = [None] * (n2 + 1);

    for i in range(0,n1):
        L[i] = A[p + i];
    for j in range(0, n2):
        R[j] = A[q + j + 1];

    L[n1] = (float("inf"));
    R[n2] = (float("inf"));

    i = 0;
    j = 0;

    global count
    
    for k in range(p, (r+1)):
        if( L[i] <= R[j]):
            A[k] = L[i];
            i = i + 1;
        else:
            A[k] = R[j];

            
            count+= len(L)-1-i
            #print(">>>",L[i],R[j],i,j, len(L), len(R) )
            j = j + 1;

    return A;


#len(sor)-1
#test2 = [1,3,5,2,4,6]
#test1 = [5,4,3,2,1]

print(merge_sort(read_data, 0, 100000-1))
#print(test1)
#print(merge_sort(test1, 0, len(test1)-1))
print(count)